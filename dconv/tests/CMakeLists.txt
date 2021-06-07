cmake_minimum_required(VERSION 3.1.0)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(view.gtest view_test.cpp)
target_link_libraries(view.gtest ${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} pthread)
install(TARGETS view.gtest DESTINATION share/dconv/tests)

add_executable(atod.gtest atod_test.cpp)
target_link_libraries(atod.gtest ${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} pthread)
install(TARGETS atod.gtest DESTINATION share/dconv/tests)

add_executable(dtoa.gtest dtoa_test.cpp)
target_link_libraries(dtoa.gtest ${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} pthread)
install(TARGETS dtoa.gtest DESTINATION share/dconv/tests)

add_executable(roundtrip.gtest roundtrip_test.cpp)
target_link_libraries(roundtrip.gtest ${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} pthread)
install(TARGETS roundtrip.gtest DESTINATION share/dconv/tests)
