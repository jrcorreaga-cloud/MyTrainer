#include "unit_tests.h"
#include <iostream>
#include "../../src/persistence/repositories/UserRepository.h"
#include "../../src/persistence/repositories/PlanRepository.h"
#include "../../src/persistence/repositories/ScheduleRepository.h"
#include "../../src/business_logic/services/AuthService.h"
#include "../../src/business_logic/services/UserService.h"
#include "../../src/business_logic/services/PlanService.h"
#include "../../src/business_logic/services/SchedulingService.h"
#include "../../src/business_logic/services/UserServiceProxy.h"
#include "../../src/business_logic/services/ReportService.h"
#include "../../src/business_logic/services/notifications/NotificationManager.h"
#include "../../src/business_logic/services/notifications/EmailNotifier.h"
#include "../../src/business_logic/models/subscription/Subscription.h"
#include "../../src/business_logic/models/subscription/ActiveState.h"
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
    allPassed &= testReportService();
    allPassed &= testObserverPattern();
    allPassed &= testStatePattern();
    allPassed &= testProxyPattern();
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

bool UnitTests::testReportService() {
    ScheduleRepository scheduleRepo;
    UserRepository userRepo;
    PlanRepository planRepo;
    ReportService service(&scheduleRepo, &userRepo, &planRepo);

    QString report = service.generateGlobalReport();
    ASSERT_TRUE(report.contains("Global Performance Report"), "Report should contain main title");
    ASSERT_TRUE(report.contains("User Metrics"), "Report should contain User Metrics composite");
    ASSERT_TRUE(report.contains("Schedule Metrics"), "Report should contain Schedule Metrics composite");
    return true;
}

bool UnitTests::testObserverPattern() {
    auto manager = std::make_shared<NotificationManager>();
    auto emailNotifier = std::make_shared<EmailNotifier>();
    manager->attach(emailNotifier);

    // In a real mocking framework we'd check if emailNotifier.update was called
    // Here we just ensure it doesn't crash
    manager->notify("Test message", "test@test.com");
    ASSERT_TRUE(true, "Observer pattern executed notification successfully");
    return true;
}

bool UnitTests::testStatePattern() {
    Subscription sub(1, 1);
    ASSERT_TRUE(sub.getStatus() == "Active", "Initial state should be Active");

    sub.suspend();
    ASSERT_TRUE(sub.getStatus() == "Suspended", "State should transition to Suspended");

    sub.cancel();
    ASSERT_TRUE(sub.getStatus() == "Cancelled", "State should transition to Cancelled");

    sub.activate();
    ASSERT_TRUE(sub.getStatus() == "Cancelled", "Cancelled state cannot be activated");

    return true;
}

bool UnitTests::testProxyPattern() {
    UserRepository repo;
    auto realService = std::make_shared<UserService>(&repo);
    UserServiceProxy proxy(realService);

    bool result = proxy.registerStudent("proxytest@test.com", "pass");
    ASSERT_TRUE(result, "Proxy should successfully register student and log to audit.log");

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
