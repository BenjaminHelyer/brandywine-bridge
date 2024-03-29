#include <string>

#include "api_layer.h"

namespace brandywine
{

    std::string ApiLayer::hello_world_response()
    {
        std::string resp_txt = "Hello, World!";
        return resp_txt;
    }

    std::string ApiLayer::create_key(std::string key, std::string val)
    {
        store->write_key(key, val);
        std::string ack_txt = "Create request received.";
        return ack_txt;
    }

    std::string ApiLayer::read_key(std::string key)
    {
        std::string ack_txt = "Read request received.";
        std::string val = store->read_key(key);
        if (val != "")
        {
            return ack_txt + " Value is: " + val;
        }
        else
        {
            return ack_txt + " Value not found in store.";
        }
    }

    std::string ApiLayer::update_key(std::string key, std::string val)
    {
        std::string ack_txt = "Update request received.";
        store->write_key(key, val);
        return ack_txt;
    }

    std::string ApiLayer::delete_key(std::string key)
    {
        std::string ack_txt = "Delete request received.";
        store->remove_key(key);
        return ack_txt;
    }

} // namespace brandywine