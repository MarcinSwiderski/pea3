#pragma once
#include <string>
#define INF 9999

#include <exception>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

#define MAX_VAL 100000

class Graph
{
private:
    int **matrix = nullptr;
    int vert_count;
    string description = "";
public:
    Graph();
  //  Graph(int _vertexCount);
  //  Graph(Graph &graph);
    ~Graph();
    //void fill(int rows, int cols, int **matrix);
    int at(int row, int col);
    //void set(int row, int col, int weight);
    int **getNmatrix();
    int getVertexCount();
    void show();
    string toString();
    bool infDiag();
    bool readGraph(string file);
    string getDescription();
};

class Edge
{
public:
    int beg;
    int end;
    int weight;
    Edge();
    Edge(int _beg, int _end, int _weight);
    void show();
};