cmake_minimum_required(VERSION 3.20)
project(CommandControlSystem VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(target-simulator)
add_subdirectory(cc-core)
add_subdirectory(qt-operator)
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.14.0
)
FetchContent_MakeAvailable(googletest)