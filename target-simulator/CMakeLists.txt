add_executable(target_simulator src/main.cpp)

target_link_libraries(target_simulator
    PRIVATE
        cc-core
)