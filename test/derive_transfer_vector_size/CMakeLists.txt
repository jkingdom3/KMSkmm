cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(TestKMSkmmDeriveTransferVectorSize
        VERSION 1.0
        DESCRIPTION "A test for Kmm::derive_transfer_vector_size"
        LANGUAGES CXX)

add_executable(test test.cc)
target_link_libraries(test PRIVATE
        KMSkmm-1.0)
