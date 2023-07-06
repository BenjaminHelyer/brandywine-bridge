add_library(httplib httplib.h)
set_target_properties(httplib PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(httplib WS2_32)