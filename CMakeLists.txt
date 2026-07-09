cmake_minimum_required(VERSION 3.16)
project(MyTrainer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Core Library (Business Logic & Persistence)
file(GLOB_RECURSE CORE_SRC 
    src/business_logic/*.cpp src/business_logic/*.h
    src/persistence/*.cpp src/persistence/*.h
)
add_library(CoreLib STATIC ${CORE_SRC})
target_link_libraries(CoreLib PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets)
target_include_directories(CoreLib PUBLIC src)

# Main Executable (Presentation / UI Layer)
file(GLOB_RECURSE UI_SRC 
    src/presentation/*.cpp src/presentation/*.h
)
add_executable(MyTrainer src/main.cpp ${UI_SRC})
target_link_libraries(MyTrainer PRIVATE CoreLib Qt6::Core Qt6::Gui Qt6::Widgets)

# Unit Tests
add_executable(unit_tests test/unit/main.cpp test/unit/unit_tests.cpp test/unit/unit_tests.h)
target_link_libraries(unit_tests PRIVATE CoreLib Qt6::Core)

# Functional Tests
add_executable(funcional_tests test/funcional/main.cpp test/funcional/funcional_tests.cpp test/funcional/funcional_tests.h ${UI_SRC})
target_link_libraries(funcional_tests PRIVATE CoreLib Qt6::Core Qt6::Gui Qt6::Widgets)
