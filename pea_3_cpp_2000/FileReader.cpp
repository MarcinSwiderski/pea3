#include "FileReader.hpp"

std::unique_ptr<Graph> read_graph_file(std::string file_name)
{
    std::ifstream file;
    file.open(file_name);
    if (file.is_open())
    {
        int vertices_cnt, tmp_weight;
        file >> vertices_cnt;
        std::unique_ptr<Graph> graph(new Graph(vertices_cnt));
        for (int row_idx = 0; row_idx < vertices_cnt; row_idx++)
        {
            for (int col_idx = 0; col_idx < vertices_cnt; col_idx++)
            {
                file >> tmp_weight;
                graph->set(row_idx, col_idx, tmp_weight);
            }
        }
        return graph;
    }
    throw std::runtime_error("Could not open file");
}