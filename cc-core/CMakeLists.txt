add_library(cc-core STATIC 
    src/Target.cpp
    src/TargetManager.cpp)
target_include_directories(cc-core PUBLIC include)