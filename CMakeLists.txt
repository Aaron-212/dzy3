cmake_minimum_required (VERSION 3.20)

project (DZY3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (OS_NAME STREQUAL "Windows")
	set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
	find_package(GTest REQUIRED CONFIG)
else()
	find_package(GTest REQUIRED)
endif()

add_executable(DZY3 source/main.cpp)

target_include_directories(DZY3 PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(DZY3)

# Check if this is a debug build
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	enable_testing()
    add_subdirectory(tests)
endif()
