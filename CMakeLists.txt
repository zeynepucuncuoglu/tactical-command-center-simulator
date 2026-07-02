cmake_minimum_required(VERSION 3.20)
project(CommandControlSystem VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

enable_Testing()
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(googletest)
add_subdirectory(target-simulator)
add_subdirectory(cc-core)
add_subdirectory(qt-operator)
add_subdirectory(tests)
add_subdirectory(command-receiver)

