add_library(cc-core STATIC 
    src/CCCore.cpp
    src/Target.cpp)
target_include_directories(cc-core PUBLIC include)