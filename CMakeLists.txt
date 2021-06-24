cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# set the project name
project(Template)
add_executable(Template src/main.cpp)

# set as default startup project in Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Template)


# add OpenCV
set (OpenCV_DIR ${PROJECT_SOURCE_DIR}/lib/opencv/build)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_custom_command(TARGET Template POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${PROJECT_SOURCE_DIR}/lib/opencv/build/x64/vc14/bin"
    $<TARGET_FILE_DIR:Template>)


# put all cpp files here (except main.cpp)
set(SOURCE_FILES src/utils.cpp)  
set(HEADER_FILES src/utils.hpp)
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
include_directories(${SOURCE_DIR})


# create an intermediate library that is used for the main executable and the unit tests
add_library(IntermediateLib SHARED STATIC ${SOURCE_FILES} ${HEADER_FILES}) 
target_link_libraries(IntermediateLib ${OpenCV_LIBS})


# the main executable
target_link_libraries(Template IntermediateLib)


# unit tests
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # required for Windows
add_subdirectory(lib/googletest EXCLUDE_FROM_ALL)
add_subdirectory(test)
