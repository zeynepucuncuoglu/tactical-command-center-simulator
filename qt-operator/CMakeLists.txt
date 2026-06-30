find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(qt-operator
    src/main.cpp
    src/MainWindow.cpp
    include/MainWindow.h
)


target_link_libraries(qt-operator
    PRIVATE
        Qt6::Widgets
        cc-core
)
target_include_directories(qt-operator PRIVATE include)
