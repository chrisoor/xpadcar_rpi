cmake_minimum_required(VERSION 3.13)

project(xpadcar_rpi)

set (SOURCES
	src/main.cpp
	src/IGamepadInterface.hpp
	src/GamepadInterfaceSDL2.cpp
	src/GamepadInterfaceSDL2.hpp
	src/example.cpp
	src/example.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(SDL2 REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
