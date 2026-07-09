#pragma once

class FuncionalTests {
public:
    bool runAllTests();

private:
    bool testFullBookingFlow();
    bool testAdminRegistrationFlow();
};
