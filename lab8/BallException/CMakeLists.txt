
project(ballexception)

add_library(libballexception STATIC ${SOURCE_FILES})
target_include_directories(libballexception PUBLIC .)

add_executable(ballexception ${SOURCE_FILES} main.cpp)
