#include "Graph.hpp"

Graph::Graph() : vertexCount(0), Nmatrix(nullptr)
{
}

Graph::Graph(int _vertexCount) : vertexCount(_vertexCount)
{
    Nmatrix = new int *[vertexCount];
    for (int v_idx = 0; v_idx < vertexCount; v_idx++)
    {
        Nmatrix[v_idx] = new int[vertexCount];
    }
}

Graph::Graph(Graph &graph)
{
    /** alocate mmemory for Nmatrix */
    vertexCount = graph.vertexCount;
    Nmatrix = new int *[vertexCount];
    for (int v_idx = 0; v_idx < vertexCount; v_idx++)
    {
        Nmatrix[v_idx] = new int[vertexCount];
    }

    /** fill Nmatrix */
    for (int row_idx = 0; row_idx < vertexCount; row_idx++)
    {
        for (int col_idx = 0; col_idx < vertexCount; col_idx++)
        {
            Nmatrix[row_idx][col_idx] = graph.at(row_idx, col_idx);
        }
    }
}

Graph::~Graph()
{
    if (Nmatrix != nullptr)
    {
        for (int v_idx = 0; v_idx < vertexCount; v_idx++)
        {
            if (Nmatrix[v_idx] != nullptr)
                delete Nmatrix[v_idx];
        }
        delete Nmatrix;
    }
}

void Graph::fill(int rows, int cols, int **matrix)
{
    for (int row_idx = 0; row_idx < rows; row_idx++)
    {
        for (int col_idx = 0; col_idx < cols; col_idx++)
        {
            Nmatrix[row_idx][col_idx] = matrix[row_idx][col_idx];
        }
    }
}

int Graph::at(int row, int col)
{
    if (row < 0 || row >= vertexCount || col < 0 || col >= vertexCount)
        throw std::out_of_range("access to row or col out of range index");
    return Nmatrix[row][col];
}

void Graph::set(int row, int col, int weight)
{
    if (row < 0 || row >= vertexCount || col < 0 || col >= vertexCount)
        throw std::out_of_range("access to row or col out of range index");
    Nmatrix[row][col] = weight;
}

int Graph::getVertexCount()
{
    return vertexCount;
}

int **Graph::getNmatrix()
{
    return Nmatrix;
}

void Graph::show()
{
    try
    {
        std::cout << "{ ";
        for (int row_idx = 0; row_idx < vertexCount; row_idx++)
        {
            std::cout << "{ ";
            for (int col_idx = 0; col_idx < vertexCount; col_idx++)
            {
                std::cout << at(row_idx, col_idx) << ", ";
            }
            std::cout << "}" << std::endl;
        }
        std::cout << "}" << std::endl;
    }
    catch (std::out_of_range &oor)
    {
        std::cout << "show: " << oor.what() << std::endl;
    }
}

/** edge struct */

Edge::Edge() {}
Edge::Edge(int _beg, int _end, int _weight) : beg(_beg), end(_end), weight(_weight) {}

void Edge::show()
{
    std::cout << "beg: " << beg << " end: " << end << " weight: " << weight << std::endl;
}