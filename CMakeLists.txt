# CMake
cmake_minimum_required(VERSION 3.14)

# Project
project(trace)

# Common variables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Release)
set(INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LIBLARIES)

# Config settings
set(INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME})
set(INSTALL_LIB_DIR ${INSTALL_DIR}/lib)
set(INSTALL_INCLUDE_DIR ${INSTALL_DIR}/include)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.cmake.in
               ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
               @ONLY)

#  Source files
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

#  Target (static by default)
option(BUILD_SHARED "Build shared trace library" Off)
if(BUILD_SHARED)
    add_library(${PROJECT_NAME} SHARED ${SOURCES})

    install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${INSTALL_LIB_DIR})
else()
    add_library(${PROJECT_NAME} STATIC ${SOURCES})

    install(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION ${INSTALL_LIB_DIR})
endif()

# Target dependencies
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBLARIES})

# Installation
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION ${INSTALL_INCLUDE_DIR})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake DESTINATION ${INSTALL_DIR})

# Testing
option("Build test" Off)
if(BUILD_TEST)
    enable_testing()

    include_directories(${INCLUDES})
    link_libraries(${PROJECT_NAME} ${LIBLARIES})

    add_executable(File test/file.cpp)
    add_test(NAME FileTest COMMAND File)

    add_executable(Type test/type.cpp)
    add_test(NAME TypeTest COMMAND Type)

    add_executable(Object test/object.cpp)
    add_test(NAME ObjectTest COMMAND Object)
endif()