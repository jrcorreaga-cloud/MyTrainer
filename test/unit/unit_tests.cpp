#include "unit_tests.h"
#include <iostream>
#include "../../src/persistence/repositories/UserRepository.h"
#include "../../src/persistence/repositories/PlanRepository.h"
#include "../../src/persistence/repositories/ScheduleRepository.h"
#include "../../src/business_logic/services/AuthService.h"
#include "../../src/business_logic/services/PlanService.h"
#include "../../src/business_logic/services/SchedulingService.h"
#include "../../src/business_logic/models/ModelFactory.h"

#define ASSERT_TRUE(condition, msg) \
    if (!(condition)) { std::cerr << "[FAIL] " << msg << std::endl; return false; } \
    std::cout << "[PASS] " << msg << std::endl;

bool UnitTests::runAllTests() {
    std::cout << "--- RUNNING UNIT TESTS ---" << std::endl;
    bool allPassed = true;
    allPassed &= testUserRepository();
    allPassed &= testPlanService();
    allPassed &= testScheduleService();
    return allPassed;
}

bool UnitTests::testUserRepository() {
    UserRepository repo;
    ASSERT_TRUE(repo.getUserByEmail("admin@mytrainer.com").has_value(), "Admin user should exist initially");
    
    User newUser = ModelFactory::createUser(0, "new@test.com", "pass", Role::Student, "");
    ASSERT_TRUE(repo.addUser(newUser), "Adding new user should succeed");
    ASSERT_TRUE(repo.getUserByEmail("new@test.com").has_value(), "Newly added user should be retrievable");
    ASSERT_TRUE(!repo.addUser(newUser), "Adding duplicate user should fail");
    
    return true;
}

bool UnitTests::testPlanService() {
    PlanRepository repo;
    PlanService service(&repo);
    ASSERT_TRUE(service.createPlan("Bulk", 100.0, 6), "Valid plan should be created");
    ASSERT_TRUE(!service.createPlan("", 100.0, 6), "Plan with empty name should fail");
    ASSERT_TRUE(!service.createPlan("Cut", -10.0, 6), "Plan with negative price should fail");
    return true;
}

bool UnitTests::testScheduleService() {
    ScheduleRepository repo;
    SchedulingService service(&repo);
    auto initialSlots = service.getAvailableSlots();
    ASSERT_TRUE(initialSlots.size() > 0, "There should be initial available slots");
    
    int firstSlotId = initialSlots[0].getId();
    ASSERT_TRUE(service.bookClass(firstSlotId, 99), "Booking an available slot should succeed");
    
    auto updatedSlots = service.getAvailableSlots();
    ASSERT_TRUE(updatedSlots.size() == initialSlots.size() - 1, "Available slots should decrease by 1");
    
    ASSERT_TRUE(!service.bookClass(firstSlotId, 100), "Booking an already booked slot should fail");
    return true;
}
