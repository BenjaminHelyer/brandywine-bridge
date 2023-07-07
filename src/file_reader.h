#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>

namespace brandywine
{

    class FileReader
    {
    private:
        std::string path;
        int eof_offset;

    public:
        explicit FileReader(std::string filepath) : eof_offset(0), path(std::move(filepath)) {}

        std::string read_value(int byte_offset);

        int write_value(std::string val);
    };

}

#endif