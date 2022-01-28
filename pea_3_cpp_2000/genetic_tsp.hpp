#ifndef GENETIC_TSP
#define GENETIC_TSP

#include <algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <numeric>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <chrono>
#include <iterator>
#include <unordered_map>
#include "Graph.hpp"
#include "params.hpp"

using mutation_pair = std::pair<std::vector<int> &, std::vector<int> &>;
using crossing_pair = std::pair<std::vector<int>, std::vector<int>>;
using namespace std::chrono;

std::vector<int> new_random_path(std::vector<int>& path);
std::vector<int> inversion_mutation(std::vector<int>& path);
std::vector<int> transposition_mutation(std::vector<int>& path);
std::vector<int> scramble_mutation(std::vector<int> &path);
std::vector<int> displacement_mutation(std::vector<int>& path);


crossing_pair choose_path(std::vector<int> &path1, std::vector<int> &path2);
crossing_pair corssover_pmx(std::vector<int> &path1, std::vector<int> &path2);
std::vector<int> crossover_ox(std::vector<int> &path1, std::vector<int> &path2);
std::vector<int> crossover_ex(std::vector<int> &path1, std::vector<int> &path2);
double tsp(std::vector<int> path, Graph &graph);
std::vector<int> new_random_path(std::vector<int> &init_path);
void show_path(std::vector<int> &path);
std::vector<std::vector<int>> create_random_population(Graph &graph, Params &params);
void crossover_population(std::vector<std::vector<int>> &population, Params &params);
void mutate_population(std::vector<std::vector<int>> &population, Params &params);
void select_survivors(std::vector<std::vector<int>> &population, int next_population_size, Graph &graph, std::vector<int> &global_best_path, int &global_best_path_val);
bool check_update_global_best_path(std::vector<std::vector<int>> &population, std::vector<int> &globla_best_path);
void show_population(std::vector<std::vector<int>> &population);
void show_generation(std::vector<std::vector<int>> &population, int gen_idx);
bool operation_criterion(Params &params, std::chrono::time_point<std::chrono::system_clock> &starttime, std::chrono::seconds &timelimit);
void genetic_algorithm_tsp(Graph &graph, Params &params);


#endif