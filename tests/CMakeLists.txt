add_executable(target_tests target_test.cpp)
target_link_libraries(
    target_tests PRIVATE 
    cc-core
    GTest::gtest_main
)
include(GoogleTest)
gtest_add_tests(TARGET target_tests)

