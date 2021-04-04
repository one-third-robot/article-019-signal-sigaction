cmake_minimum_required(VERSION 3.5)
project(signal-sigaction-demo)

set(CMAKE_CXX_STANDARD 17)

# ------------------------------
add_executable(
    signal-demo
    signal-demo.cpp
)

# ------------------------------
add_executable(
    sigaction-demo
    sigaction-demo.cpp
)

# ------------------------------
add_executable(
    sigaction-safe-demo
    sigaction-safe-demo.cpp
)
