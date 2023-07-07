#include <string>
#include <fstream>

#include "file_reader.h"

namespace brandywine
{

    std::string FileReader::read_value(int byte_offset)
    {
        std::ifstream file(path, std::ios::binary);
        if (!file.is_open())
        {
            // TODO: handle error for unable to open file
            return "";
        }

        if (byte_offset > eof_offset)
        {
            // TODO: handle error for byte offset greater than eof offset
            return "";
        }

        file.seekg(byte_offset);

        std::string value;
        file >> value;

        file.close();

        return value;
    }

    int FileReader::write_value(std::string val)
    {
        std::ofstream file(path, std::ios::app);
        if (!file.is_open())
        {
            // TODO: handle error for unable to open file
            return -1;
        }

        std::streampos beginPos = file.tellp();

        file << val;

        file.close();

        std::streampos endPos = file.tellp();
        eof_offset = endPos;

        return beginPos;
    }

} // namespace brandywine