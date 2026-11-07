cmake_minimum_required(VERSION 4.4.4)

project(CFS VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# This is the main program

add_executable(
    scheduler               # Executable name
    src/scheduler.cpp       # Entry point
    src/job.cpp
    src/BST.cpp
    src/CFS.cpp
)

# This is the program that runs the test suite.
# Provide the source code needed to run BST.cpp ONLY

add_executable(
    tests                    # Executable name
    tests/tests.cpp          # Entry point
    tests/BST/src/insertSuite.cpp
    tests/BST/src/removeSuite.cpp
    tests/BST/src/helper/jobGenerator.cpp
    tests/BST/src/helper/validateTreeTraversal.cpp
    tests/BST/src/helper/run.cpp
    src/job.cpp
    src/BST.cpp
    src/CFS.cpp
)

target_include_directories(scheduler PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_compile_options(scheduler PRIVATE -g)

target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_compile_options(tests PRIVATE -g)