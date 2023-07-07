#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>

namespace brandywine
{

    class FileReader
    {
    private:
        int eof_byte_offset;
        std::string filepath;

    public:
        std::string read_value(int byte_offset);

        void write_value(std::string val);
    };

}

#endif