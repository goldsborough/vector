###########################################################
## CMAKE SETUP
###########################################################

cmake_minimum_required(VERSION 3.2)
project(vector)

###########################################################
## LIBRARY
###########################################################

add_library(vector SHARED vector.c)

###########################################################
## EXECUTABLES
###########################################################

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(vector-test vector.c ${CMAKE_CURRENT_SOURCE_DIR}/test/test.c)
add_executable(example vector.c ${CMAKE_CURRENT_SOURCE_DIR}/test/example.c)

###########################################################
## COMPILER FLAGS
###########################################################

target_compile_options(vector PUBLIC -O3 -Os -std=c90)
