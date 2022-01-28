#pragma once

#include "Graph.hpp"
//#include "FileReader.hpp"
#include "genetic_tsp.hpp"
#include <string>
#include <iostream>
#include <memory>

class Menu
{
private:

	std::string menu = "";
	std::string file = "ftv47.atsp";
	Params params;
	Graph graph;
	int time = 0;
	double temperatureFactor = 0;

public:

	void enable();
	Menu();
	~Menu();
};
