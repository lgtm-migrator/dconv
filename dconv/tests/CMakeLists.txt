cmake_minimum_required(VERSION 3.1.0)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(view.gtest view_test.cpp)
target_link_libraries(view.gtest ${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} pthread)
install(TARGETS view.gtest DESTINATION share/dconv/tests)
