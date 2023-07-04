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
    test_ben_red_black_tree
    test_ben_red_black_tree.cpp
    ../../src/ben_red_black_tree.cpp
)
target_link_libraries(
    test_api
    GTest::gtest_main
    httplib
    Hash_table
    Key_value_store
)

include(GoogleTest)
gtest_discover_tests(test_api)