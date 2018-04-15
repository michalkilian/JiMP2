
project(wordcounter)

set(HEDEAR_FILES Counts.h Word.h WordCounter.h)
set(SOURCE_FILES Counts.cpp Word.cpp WordCounter.cpp)

add_library(libwordcounter STATIC ${SOURCE_FILES})
target_include_directories(libwordcounter PUBLIC .)

add_executable(wordcounter ${SOURCE_FILES} main.cpp)

target_link_libraries(wordcounter libwordcounter)

