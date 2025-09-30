# set cmake minimum required version
cmake_minimum_required(VERSION 3.26 FATAL_ERROR)
project(data_structures_c C)

# enable compilation warnings
add_compile_options(-std=c17 -Wall -Wextra -Wpedantic)

# add all those sources to executable
add_executable(${PROJECT_NAME} src/principal.c  src/canalesl/canales.c)