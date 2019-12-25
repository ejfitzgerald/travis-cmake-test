
cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(travis-test CXX)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(foo src/foo.cpp)

add_executable(foo-bin src/main.cpp)
target_link_libraries(foo-bin PRIVATE foo)

add_subdirectory(vendor/googletest)

include(CTest)
enable_testing()

add_executable(foo-tests tests/tests.cpp)
target_link_libraries(foo-tests PRIVATE foo gtest gtest_main)
target_include_directories(foo-tests PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/vendor/googletest/googletest/include"
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
)

add_test(foo-tests foo-tests)
