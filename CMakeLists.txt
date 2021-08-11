cmake_minimum_required(VERSION 3.1..19)

project(unicode_test)

include(FetchContent)

set(CMAKE_CXX_STANDARD 14)

add_executable(unicode_test main.cpp)

# FetchContent_Declare(fmt
#   GIT_REPOSITORY https://github.com/fmtlib/fmt.git
#   GIT_TAG master
# )
# FetchContent_MakeAvailable(fmt)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# target_link_libraries(unicode_test fmt::fmt)

