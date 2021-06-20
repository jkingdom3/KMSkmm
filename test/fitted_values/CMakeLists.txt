cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(TestKMSkmmFittedValues
        VERSION 1.0
        DESCRIPTION "A test for KMS Kmm::fitted_values()"
        LANGUAGES CXX)

add_executable(test test.cc)
target_link_libraries(test PRIVATE KMSkmm-1.0 KMSdata-1.0)

configure_file(data.csv ${CMAKE_CURRENT_BINARY_DIR}/data.csv COPYONLY)
configure_file(solution.csv ${CMAKE_CURRENT_BINARY_DIR}/solution.csv COPYONLY)
