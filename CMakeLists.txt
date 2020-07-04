###########################################################
## CMAKE SETUP
###########################################################

cmake_minimum_required(VERSION 3.5)
project(vector)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

###########################################################
## LIBRARY
###########################################################

add_library(vector SHARED vector.c)
add_library(vector-static STATIC vector.c)

###########################################################
## EXECUTABLES
###########################################################

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(vector-test ${CMAKE_CURRENT_SOURCE_DIR}/test/test.c)
add_executable(vector-example ${CMAKE_CURRENT_SOURCE_DIR}/test/example.c)

target_link_libraries(vector-test vector)
target_link_libraries(vector-example vector)

###########################################################
## COMPILER FLAGS
###########################################################

# Enable all possible warnings and treat them as errors
set(WRN_FLAGS -Wall -Wextra -Wpedantic -Werror)
target_compile_options(vector PRIVATE ${WRN_FLAGS})
target_compile_options(vector-static PRIVATE ${WRN_FLAGS})
target_compile_options(vector-test PRIVATE ${WRN_FLAGS})
target_compile_options(vector-example PRIVATE ${WRN_FLAGS})

target_compile_options(vector PUBLIC -O3 -Os -g)
