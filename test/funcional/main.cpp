#include "funcional_tests.h"

int main(int argc, char** argv) {
    FuncionalTests tests;
    return tests.runAllTests() ? 0 : 1;
}
