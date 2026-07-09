#include "funcional_tests.h"
#include <iostream>
#include "../../src/persistence/repositories/UserRepository.h"
#include "../../src/persistence/repositories/ScheduleRepository.h"
#include "../../src/business_logic/services/AuthService.h"
#include "../../src/business_logic/services/AdminService.h"
#include "../../src/business_logic/services/ScheduleService.h"

#define ASSERT_TRUE(condition, msg) \
    if (!(condition)) { std::cerr << "[FAIL] " << msg << std::endl; return false; } \
    std::cout << "[PASS] " << msg << std::endl;

bool FuncionalTests::runAllTests() {
    std::cout << "--- RUNNING FUNCIONAL TESTS ---" << std::endl;
    bool allPassed = true;
    allPassed &= testFullBookingFlow();
    allPassed &= testAdminRegistrationFlow();
    return allPassed;
}

bool FuncionalTests::testFullBookingFlow() {
    UserRepository userRepo;
    ScheduleRepository scheduleRepo;
    AuthService authService(&userRepo);
    ScheduleService scheduleService(&scheduleRepo);

    // 1. Login as existing student
    auto userOpt = authService.login("student@mytrainer.com", "student123");
    ASSERT_TRUE(userOpt.has_value(), "Student login successful");
    User student = userOpt.value();

    // 2. Fetch available slots
    auto availableSlots = scheduleService.getAvailableSlots();
    ASSERT_TRUE(!availableSlots.empty(), "There are available slots");
    int targetSlotId = availableSlots[0].getId();

    // 3. Book the slot
    bool success = scheduleService.bookClass(targetSlotId, student.getId());
    ASSERT_TRUE(success, "Slot booking successful");

    // 4. Verify it's no longer available
    auto newAvailableSlots = scheduleService.getAvailableSlots();
    for (const auto& slot : newAvailableSlots) {
        ASSERT_TRUE(slot.getId() != targetSlotId, "Booked slot should not be available anymore");
    }

    return true;
}

bool FuncionalTests::testAdminRegistrationFlow() {
    UserRepository userRepo;
    AuthService authService(&userRepo);
    AdminService adminService(&userRepo);

    // 1. Login as admin
    auto adminOpt = authService.login("admin@mytrainer.com", "admin123");
    ASSERT_TRUE(adminOpt.has_value() && adminOpt.value().getRole() == Role::Admin, "Admin login successful");

    // 2. Admin registers a new student
    bool regSuccess = adminService.registerStudent("newstudent@mytrainer.com", "pass123");
    ASSERT_TRUE(regSuccess, "Admin registers new student successfully");

    // 3. New student can login
    auto newStudentOpt = authService.login("newstudent@mytrainer.com", "pass123");
    ASSERT_TRUE(newStudentOpt.has_value(), "New student can login");
    ASSERT_TRUE(newStudentOpt.value().getRole() == Role::Student, "New student has correct role");

    return true;
}
