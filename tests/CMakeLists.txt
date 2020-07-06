cmake_minimum_required(VERSION 3.13)

project(xpadcar_rpi_tests)

aux_source_directory(../src SRC)
list(REMOVE_ITEM SRC ../src/main.cpp)
include_directories(../src)

set(SOURCES
    ${SRC}
    MessageMakerTests.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(SDL2 REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
find_package(GTest REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${GTEST_INCLUDE_DIRECTORIES})
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${GTEST_LIBRARY}
    ${GTEST_MAIN_LIBRARY}
    ${SDL2_LIBRARIES}
)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
