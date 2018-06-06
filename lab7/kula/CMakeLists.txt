
project(kula)

set(HEDEAR_FILES Kolo.h Kula.h)
set(SOURCE_FILES Kolo.cpp Kula.cpp)

add_library(libkula STATIC ${SOURCE_FILES})
target_include_directories(libkula PUBLIC .)

add_executable(kula ${SOURCE_FILES} main.cpp)

target_link_libraries(kula libkula)
