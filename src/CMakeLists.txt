add_library(Key_value_store key_value_store.cpp key_value_store.h)
add_library(Api_layer api_layer.cpp api_layer.h)
add_library(Hash_table hash_table.cpp hash_table.h)
add_library(File_reader file_reader.cpp file_reader.h)
add_executable(brandywine_server main.cpp)
target_link_libraries(brandywine_server PRIVATE Api_layer Hash_table Key_value_store File_reader httplib)
set_target_properties(brandywine_server PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)