# set cmake minimum required version
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# define a c project with name provided as parameter (cmake CMakeLists.txt -DPRJCT_NAME=foo)
project(Practica2 C)

# enable compilation warnings
add_compile_options(-std=c17 -Wall -Wextra -Wpedantic)


# add all those sources to executable
add_executable(main main.c gestionAcceso/hash.c gestionAcceso/persona.c)
