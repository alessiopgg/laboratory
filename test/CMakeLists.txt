add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES runAllTests.cpp runAllTests.cpp ShoppingListFixture.cpp ShoppingListTest.cpp)
add_executable(runLabTests ${SOURCE_TEST_FILES})
target_link_libraries(runLabTests gtest gtest_main core)