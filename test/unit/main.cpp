#include "unit_tests.h"

int main(int argc, char** argv) {
    UnitTests tests;
    return tests.runAllTests() ? 0 : 1;
}
