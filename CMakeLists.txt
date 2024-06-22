cmake_minimum_required (VERSION 3.24)

project (DZY3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

cmake_policy(SET CMP0135 NEW)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR
    	"CMake generation should be in a build directory!"
        "Run the following commands:"
        "rm -rf CMakeCache.txt CMakeFiles"
        "mkdir build && cd build"
        "cmake .."
    )
endif()

include(FetchContent)
FetchContent_Declare(
  	googletest
  	# Specify the commit you depend on and update it regularly.
  	URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(DZY3 source/main.cpp)

target_include_directories(DZY3 PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(DZY3)

# Check if this is a debug build
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	enable_testing()
    add_subdirectory(tests)
endif()
