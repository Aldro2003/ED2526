cmake_minimum_required(VERSION 3.20)
project(segundoDia)

add_compile_options(-std=c17 -Wall -Wextra -Wpedantic)  # Para todo el proyecto

add_executable(ejerPtr1 ejerPtr1.c)

#si solo quiere añadir a este ejecutable y sus dependientes
#target_compile_options(principal PUBLIC -Wall -Wextra)