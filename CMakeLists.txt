cmake_minimum_required(VERSION 3.13)

project(xpadcar_rpi)

set (SOURCES
	src/main.cpp
        src/gamepadinterface.cpp
        src/gamepadinterface.hpp
	src/example.cpp
	src/example.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

