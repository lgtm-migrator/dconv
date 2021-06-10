cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

include(GoogleTest)

add_executable(view.gtest view_test.cpp)
target_link_libraries(view.gtest ${PROJECT_NAME} gtest gtest_main pthread gcov)
gtest_discover_tests(view.gtest)

add_executable(atod.gtest atod_test.cpp)
target_link_libraries(atod.gtest ${PROJECT_NAME} gtest gtest_main pthread gcov)
gtest_discover_tests(atod.gtest)

add_executable(dtoa.gtest dtoa_test.cpp)
target_link_libraries(dtoa.gtest ${PROJECT_NAME} gtest gtest_main pthread gcov)
gtest_discover_tests(dtoa.gtest)

add_executable(roundtrip.gtest roundtrip_test.cpp)
target_link_libraries(roundtrip.gtest ${PROJECT_NAME} gtest gtest_main pthread gcov)
gtest_discover_tests(roundtrip.gtest)
