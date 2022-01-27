#ifndef FILEREADER
#define FILEREADER

#include <string>
#include <memory>
#include <fstream>

#include "Graph.hpp"

class FileReader {
    private:
        std::string file_path;
    public:
        FileReader(std::string _file_path);
        std::string read();
};

std::unique_ptr<Graph> read_graph_file(std::string file_name);

#endif