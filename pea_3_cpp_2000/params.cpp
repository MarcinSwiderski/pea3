#include "params.hpp"

/** Params */

Params::Params() : duration(30), init_population_size(4), crossover_factor(0.8), mutation_factor(0.01)
{
}

void Params::setParams()
{
    std::cout << "duration: " << std::endl;
    std::cin >> duration;
    std::cout << "initial population size: " << std::endl;
    std::cin >> init_population_size;
    std::cout << "crossover factor: " << std::endl;
    std::cin >> crossover_factor;
    std::cout << "mutation factor: " << std::endl;
    std::cin >> mutation_factor;
}

void Params::showParams()
{
    std::cout << "duration: " << duration;
    std::cout << "crossover factor: " << crossover_factor;
    std::cout << "mutation factor: " << mutation_factor;
}

/** State */

State::State()
{
}

void State::show()
{
}

void State::show_path()
{
    std::cout << "path: { " << std::endl;
    for (auto p : path)
    {
        std::cout << p << ", ";
    }
    std::cout << "}" << std::endl;
}
