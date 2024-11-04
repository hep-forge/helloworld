cmake_minimum_required(VERSION 3.10)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 11)

#
# Library HelloWorld
#
include_directories(include)
install(DIRECTORY include/
        DESTINATION include)

add_library(HelloWorld STATIC src/fibonacci.cpp src/hello.cpp)
install(TARGETS HelloWorld
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

#
# Tools
#
add_executable(hello tools/hello.cpp)
target_link_libraries(hello HelloWorld)
install(TARGETS hello
        RUNTIME DESTINATION bin)

#
# Tests
# 
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

add_executable(test_fibonacci tests/test_fibonacci.cpp)
target_link_libraries(test_fibonacci HelloWorld ${GTEST_LIBRARIES} pthread)

add_test(NAME FibonacciTests COMMAND test_fibonacci)
add_custom_target(python_tests
    COMMAND python -m unittest discover -s ${CMAKE_SOURCE_DIR}/tests -p "*.py"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tests
)

add_custom_target(tests
    DEPENDS test_fibonacci python_tests
)

add_test(NAME AllTests COMMAND ${CMAKE_COMMAND} --build . --target tests)
