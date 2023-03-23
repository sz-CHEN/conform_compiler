cmake_minimum_required(VERSION 3.21)

project(test_compiler)

set(CMAKE_C_STANDARD_REQUIRED on)
set(CMAKE_CXX_STANDARD_REQUIRED on)

if(MSVC) 
add_compile_options(/Zc:__cplusplus /analyze /W4)
else()
add_compile_options(-Wall)
endif()


file(GLOB CSRCFILE *.c)
file(GLOB CPPSRCFILE *.cpp)

add_library(test_compilerc90 ${CSRCFILE})
set_property(TARGET test_compilerc90 PROPERTY C_STANDARD 90)
add_library(test_compilerc99 ${CSRCFILE})
set_property(TARGET test_compilerc99 PROPERTY C_STANDARD 99)
add_library(test_compilerc11 ${CSRCFILE})
set_property(TARGET test_compilerc11 PROPERTY C_STANDARD 11)
add_library(test_compilerc17 ${CSRCFILE})
set_property(TARGET test_compilerc17 PROPERTY C_STANDARD 17)
add_library(test_compilerc23 ${CSRCFILE})
# set_property(TARGET test_compilerc23 PROPERTY C_STANDARD 23)

add_library(test_compilercpp98 ${CPPSRCFILE})
set_property(TARGET test_compilercpp98 PROPERTY C_STANDARD 98)
add_library(test_compilercpp11 ${CPPSRCFILE})
set_property(TARGET test_compilercpp11 PROPERTY C_STANDARD 11)
add_library(test_compilercpp14 ${CPPSRCFILE})
set_property(TARGET test_compilercpp14 PROPERTY C_STANDARD 14)
add_library(test_compilercpp17 ${CPPSRCFILE})
set_property(TARGET test_compilercpp17 PROPERTY C_STANDARD 17)
add_library(test_compilercpp20 ${CPPSRCFILE})
set_property(TARGET test_compilercpp20 PROPERTY C_STANDARD 20)
add_library(test_compilercpp23 ${CPPSRCFILE})
set_property(TARGET test_compilercpp23 PROPERTY C_STANDARD 23)


