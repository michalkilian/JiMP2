
project(square)


set(HEDEAR_FILES Point.h Square.h)
set(SOURCE_FILES Point.cpp Square.cpp)

add_library(libsquare STATIC ${SOURCE_FILES})
target_include_directories(libsquare PUBLIC .)

add_executable(square ${SOURCE_FILES} main.cpp)

target_link_libraries(square libsquare)
