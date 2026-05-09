cmake_minimum_required(VERSION 3.20)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    project(cpp_sim VERSION 0.1.0 LANGUAGES CXX)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cpp_sim
    src/dryden.cpp
    src/forces.cpp
    src/integrator.cpp
    src/logger.cpp
    src/main.cpp
    src/rigid_body.cpp
    src/simulator.cpp
)

target_include_directories(cpp_sim
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(cpp_sim PRIVATE /W4 /permissive-)
else()
    target_compile_options(cpp_sim PRIVATE -Wall -Wextra -Wpedantic)
endif()
