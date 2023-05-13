#include <string>

#include "api_layer.h"

namespace brandywine {

    std::string ApiLayer::hello_world_response() {
        std::string resp_txt = "Hello, World!";
        return resp_txt;    
    }
    
}