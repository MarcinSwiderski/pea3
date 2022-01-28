//#include "pch.h"
#include "Graph.hpp"
#include <fstream>
#include <time.h>
#include <string>
#include <iostream>

string Graph::getDescription()
{
	if (!vert_count)
	{
		return "Brak danych\n";
	}
	else
	{
		return description;
	}

}

string Graph::toString()
{
	string graph = "";
	graph.append(description);

	if (vert_count)
	{
		for (int r = 0; r < vert_count; r++)
		{
			for (int c = 0; c < vert_count; c++)
			{
				if ((matrix[r][c] < 10) && (matrix[r][c] >= 0))
					graph += to_string(matrix[r][c]) + "    ";

				else if (((matrix[r][c] < 100) && (matrix[r][c] > 9)) || (matrix[r][c] < 0))
					graph += to_string(matrix[r][c]) + "   ";
				else if (matrix[r][c] == 100000000)
					graph += "N    ";
				else
					graph += to_string(matrix[r][c]) + "  ";
			}
			graph += "\n";
		}
	}
	else
	{
		graph = "Graf pusty\n";
	}
	return graph;
}

bool Graph::infDiag()
{
	if (!vert_count)
		return false;
	else
	{
		for (int i = 0; i < vert_count; i++)
		{
			matrix[i][i] = INF;
		}
		return true;
	}
}

int Graph::at(int row, int col)
{
	if (row < 0 || row >= vert_count || col < 0 || col >= vert_count)
		throw std::out_of_range("access to row or col out of range index");
	return matrix[row][col];
}

bool Graph::readGraph(string file)
{

	int** temp;
	description = "";
	string tempDesc = "";

	ifstream fin;
	fin.open(file);

	if (fin.fail() || fin.eof())
	{
		cout << "plik nie zostal wczytany";
		return false;
	}

	if (vert_count)
	{
		for (int i = 0; i < vert_count; i++)
		{
			delete[] matrix[i];
		}

		delete[] matrix;
	}

	getline(fin, tempDesc);

	description.append(tempDesc + "\n");

	getline(fin, tempDesc);

	description.append(tempDesc + "\n");

	getline(fin, tempDesc);

	description.append(tempDesc + "\n");

	fin >> tempDesc;

	description.append(tempDesc);

	fin >> vert_count;



	description.append(to_string(vert_count) + "\n");



	getline(fin, tempDesc);
	getline(fin, tempDesc);
	getline(fin, tempDesc);
	getline(fin, tempDesc);

	temp = new int* [vert_count];

	for (int i = 0; i < vert_count; i++)
	{
		temp[i] = new int[vert_count];
	}

	for (int c = 0; c < vert_count; c++)
	{
		for (int r = 0; r < vert_count; r++)
		{
			fin >> temp[r][c];
		}
	}

	fin.close();

	matrix = temp;
	return true;
}

int Graph::getVertexCount()
{
	return vert_count;
}

Graph::Graph()
{

}

Graph::~Graph()
{

}

int** Graph::getNmatrix()
{
	return matrix;
}
