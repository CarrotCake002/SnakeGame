cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

# Use C++17 or later if needed
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML (change path if needed)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add your source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

# Define your executable
add_executable(snake ${SOURCES})

# Link SFML
target_link_libraries(snake sfml-graphics sfml-window sfml-system)
