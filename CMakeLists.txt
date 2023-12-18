cmake_minimum_required(VERSION 3.0)
project(MedianContainerTask)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the executable
include_directories(.)
add_executable(MedianContainerTask main.cpp)

# Catch2
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.0
)
FetchContent_MakeAvailable(Catch2)
# // Catch2

# Add the executable for tests
add_executable(MedianContainerTaskTests tests/MedianContainerUnitTests.cpp)
target_link_libraries(MedianContainerTaskTests PRIVATE Catch2::Catch2WithMain)