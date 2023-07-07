include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/bc860af08783b8113005ca7697da5f5d49a8056f.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    test_api
    test_api.cpp
    ../../src/api_layer.cpp
)
add_executable(
    test_ben_red_black_tree
    test_ben_red_black_tree.cpp
    ../../src/ben_red_black_tree.cpp
)
add_executable(
    test_file_reader
    test_file_reader.cpp
    ../../src/file_reader.cpp
)
target_link_libraries(
    test_api
    GTest::gtest_main
    httplib
    Hash_table
    Key_value_store
)
target_link_libraries(
    test_ben_red_black_tree
    GTest::gtest_main
)
target_link_libraries(
    test_file_reader
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_api)
gtest_discover_tests(test_ben_red_black_tree)
gtest_discover_tests(test_file_reader)