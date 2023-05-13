add_library(Api_layer api_layer.cpp api_layer.h)
add_executable(brandywine_server main.cpp)
target_link_libraries(brandywine_server Api_layer)
set_target_properties(brandywine_server PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)