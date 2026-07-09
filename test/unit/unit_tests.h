#pragma once

class UnitTests {
public:
    bool runAllTests();

private:
    bool testUserRepository();
    bool testPlanService();
    bool testScheduleService();
};
