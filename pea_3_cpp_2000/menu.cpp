#include "menu.hpp"

void menu()
{

    std::unique_ptr<Graph> graph;
    Params params;
    std::string fileName;

    int control = -1;
    bool loop = true;
    int test_iter = 0;

    while (loop)
    {
        std::cout << "1) read data from file" << std::endl;
        std::cout << "2) enter stop criterion" << std::endl;
        std::cout << "3) set initial population size" << std::endl;
        std::cout << "4) set mutation factor" << std::endl;
        std::cout << "5) set crossover factor" << std::endl;
        std::cout << "6) choose mutation method" << std::endl;
        std::cout << "7) run algorithm with set parameters" << std::endl;
        std::cout << "8) exit" << std::endl;

        std::cin >> control;
        switch (control)
        {
        case 1:
            std::cin >> fileName;
            graph = read_graph_file(fileName);
            graph->show();
            break;
        case 2:
            std::cout << "duration:" << std::endl;
            params.enter_duration();
            break;
        case 3:
            std::cout << "initial population size:" << std::endl;
            params.enter_init_population_size();
            break;
        case 4:
            std::cout << "mutation factor:" << std::endl;
            params.enter_mutation_factor();
            break;
        case 5:
            std::cout << "crossover factor:" << std::endl;
            params.enter_crossover_factor();
            break;
        case 7:
            genetic_algorithm_tsp(*graph, params);
            break;
        case 8:
            loop = false;
            break;
        default:
            std::cout << "Wrong menu option" << std::endl;
            break;
        }
    }
}