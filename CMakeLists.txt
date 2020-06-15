cmake_minimum_required(VERSION 3.13)

project(xpadcar_rpi)

set (SOURCES
	src/main.cpp
	src/ButtonsAxisStatus.hpp
	src/InputDeviceInterface.hpp
	src/GamepadInterfaceSDL2.hpp
	src/GamepadInterfaceSDL2.cpp
	src/TimerInterface.hpp
	src/TimerSDL2.hpp
	src/TimerSDL2.cpp
	src/PacketSenderInterface.hpp
	src/PacketSenderSerialLinux.hpp
	src/PacketSenderSerialLinux.hpp
	src/PacketShowTerminal.hpp
	src/PacketShowTerminal.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(SDL2 REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()