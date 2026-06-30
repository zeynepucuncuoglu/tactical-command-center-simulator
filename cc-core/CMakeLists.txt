find_package(Qt6 REQUIRED COMPONENTS Core)


add_library(cc-core STATIC 
    src/Target.cpp
    src/TargetManager.cpp
    src/UdpReceiver.cpp
    include/UdpReceiver.h)
target_include_directories(cc-core PUBLIC include)
target_link_libraries(cc-core PUBLIC Qt6::Core)