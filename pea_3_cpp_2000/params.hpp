#ifndef PARAMS
#define PARAMS

#include <iostream>
#include <vector>
#include <chrono>

struct Params
{
    double duration;
    int init_population_size;
    double mutation_factor;
    double crossover_factor;
    Params();
    void setParams();
    void showParams();
    void enter_duration() { std::cin >> duration; }
    void enter_init_population_size() { std::cin >> init_population_size; }
    void enter_mutation_factor() { std::cin >> mutation_factor; }
    void enter_crossover_factor() { std::cin >> crossover_factor; }
};

struct State
{
    int tsp;
    std::vector<int> path;

    State();
    void show();
    void show_path();
};

#endif