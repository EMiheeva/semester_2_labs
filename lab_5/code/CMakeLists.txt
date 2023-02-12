cmake_minimum_required(VERSION 3.15) 

set(PROJECT_NAME lab_5)				 	 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("inc/")

add_executable("${PROJECT_NAME}" main.cpp)

file(COPY "input.txt" DESTINATION "/")
