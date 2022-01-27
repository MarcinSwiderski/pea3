#include "genetic_tsp.hpp"

std::vector<int> inversion_mutation(std::vector<int> &path)
{
    std::vector<int> res_path(path);
    int rand_vertex1, rand_vertex2;
    int smaller_idx, larger_idx;
    do
    {
        rand_vertex1 = rand() % (res_path.size() - 2) + 1;
        rand_vertex2 = rand() % (res_path.size() - 2) + 1;
    } while (rand_vertex1 == rand_vertex2);

    smaller_idx = std::min(rand_vertex1, rand_vertex2);
    larger_idx = std::max(rand_vertex1, rand_vertex2);
    int mid_idx = (larger_idx + smaller_idx + 1) / 2;

    for (; smaller_idx < mid_idx; smaller_idx++, larger_idx--)
    {
        std::swap(res_path[smaller_idx], res_path[larger_idx]);
        //std::cout << "swap: " << smaller_idx << "|" << larger_idx << std::endl;
    }
    return res_path;
}

crossing_pair choose_path(std::vector<int> &path1, std::vector<int> &path2)
{
    if (rand() % 2 == 1)
        return crossing_pair(path1, path2);
    return crossing_pair(path2, path1);
}

crossing_pair corssover_pmx(std::vector<int> &path1, std::vector<int> &path2)
{
    std::vector<int> res_path1(path1.size());
    std::vector<int> res_path2(path2.size());

    // section to copy
    int rand_vertex1, rand_vertex2;
    int smaller_idx, larger_idx;
    do
    {
        rand_vertex1 = rand() % (res_path1.size() - 2 + 1);
        rand_vertex2 = rand() % (res_path1.size() - 2 + 1);
    } while (rand_vertex1 == rand_vertex2);
    smaller_idx = std::min(rand_vertex1, rand_vertex2);
    larger_idx = std::max(rand_vertex1, rand_vertex2);

    // choose from which path to copy
    // crossing_pair choosen_path = choose_path(path1, path2);
//    std::cout << "Dane z wektora";
    for (int idx = smaller_idx; idx <= larger_idx; idx++)
    {
        res_path1[idx] = path1[idx];
        res_path2[idx] = path2[idx];
//      std::cout <<" "<<res_path1[idx] << std::endl;
    }

    // find not copied elements and match copy between tables
    for (int idx = smaller_idx; idx <= larger_idx; idx++)
    {
        // find if path2 element was copied
        std::vector<int>::iterator position_p1 = std::find(res_path1.begin() + smaller_idx, res_path1.begin() + larger_idx, path2[idx]);
        if (position_p1 == res_path1.begin() + larger_idx) // not found in scope
        {
            // find in path 2 postion of path1[idx] and fill this place in res path 1 with value
            std::vector<int>::iterator position_p2 = std::find(path2.begin(), path2.end(), path1[idx]);
            size_t position_idx = position_p2 - (path2.begin() + 1);

            if (position_idx >= res_path1.size())
                break;

            if (position_idx < smaller_idx || position_idx > larger_idx)
            {
 //               std::cout <<std::endl<<"Rozmiar obu wektorow "<< path1.size() << std::endl;
 //               std::cout << "rozmiary wektorow: " << res_path1.size() << " " << path2.size()<<std::endl;
 //               std::cout << "indeksy ktore podobno sie nie zgadzaja: " << position_idx << " " << idx;
                res_path1[position_idx] = path2[idx];
            }
            else
            {
                std::vector<int>::iterator position_p3 = std::find(path2.begin(), path2.end(), path1[position_idx]);
                size_t position_idx_bufor = position_p3 - path2.begin();
                if (position_idx_bufor >= res_path2.size())
                    break;
                res_path1[position_p3 - path2.begin()] = path2[idx];
            }
        }
    }

    for (int idx = smaller_idx; idx <= larger_idx; idx++)
    {
        // find if path2 element was copied
        std::vector<int>::iterator position_p1 = std::find(res_path2.begin() + smaller_idx, res_path2.begin() + larger_idx, path1[idx]);
        if (position_p1 == res_path2.begin() + larger_idx) // not found in scope
        {
            // find in path 2 postion of path1[idx] and fill this place in res path 1 with value
            std::vector<int>::iterator position_p2 = std::find(path1.begin(), path1.end(), path2[idx]);
            size_t position_idx = position_p2 - path1.begin();
            
            if (position_idx >= res_path2.size())
                break;

            if (position_idx < smaller_idx || position_idx > larger_idx)
            {
//                std::cout << std::endl << "Rozmiar obu wektorow " << path1.size() << std::endl;
//                std::cout << "rozmiary wektorow: " << res_path2.size() << " " << path1.size() << std::endl;
//                std::cout << "indeksy ktore podobno sie nie zgadzaja: " << position_idx << " " << idx;
                //problem jest tutaj            
                res_path2[position_idx] = path1[idx];
            }
            else
            {
                std::vector<int>::iterator position_p3 = std::find(path1.begin(), path1.end(), path2[position_idx]);
                size_t position_idx_bufor = position_p3 - path1.begin();
                if (position_idx_bufor >= res_path2.size())
                    break;
                res_path2[position_idx_bufor] = path1[idx];
            }
        }
    }

    // fill crossover results with
    for (int idx = 0; idx < res_path1.size(); idx++)
    {
        if (res_path1[idx] == 0 && path2[idx] != 0)
        {
            res_path1[idx] = path2[idx];
        }
        if (res_path2[idx] == 0 && path1[idx] != 0)
        {
            res_path2[idx] = path1[idx];
        }
    }

    return crossing_pair(res_path1, res_path2);
}

double tsp(std::vector<int> path, Graph &graph)
{
    int res = 0;
    for (int i = 1; i < path.size(); i++)
    {
        res += graph.at(path[i - 1], path[i]);
    }
    return res;
}

/** population */

std::vector<int> new_random_path(std::vector<int> &init_path)
{
    std::vector<int> new_path(init_path);
    std::random_shuffle(new_path.begin() + 1, new_path.end() - 1);
    return new_path;
}

void show_path(std::vector<int> &path)
{
    std::cout << "path {";
    for (auto e : path)
    {
        std::cout << e << ", ";
    }
    std::cout << "}" << std::endl;
}

std::vector<std::vector<int>> create_random_population(Graph &graph, Params &params)
{
    // create init path
    std::vector<int> init_path(graph.getVertexCount());
    std::iota(std::begin(init_path), std::end(init_path), 0);
    std::random_shuffle(init_path.begin(), init_path.end());
    init_path.push_back(init_path.front());

    // create init population
    std::vector<std::vector<int>> init_population(params.init_population_size);
    for (int i = 0; i < params.init_population_size; i++)
    {
        init_population[i] = new_random_path(init_path);
    }

    return init_population;
}

void crossover_population(std::vector<std::vector<int>> &population, Params &params)
{
    //std::vector<int> hist(population.size());
    int path1_idx, path2_idx;
    int population_size = population.size();

    for (int idx = 0; idx < population_size; idx++)
    {
        path1_idx = rand() % population_size;
        do
        {
            path2_idx = rand() % population_size;
        } while (path1_idx == path2_idx);
        int random = rand() % 101;
        if (params.crossover_factor * 100 < random)
        {
            crossing_pair cross_pair = corssover_pmx(population[path1_idx], population[path2_idx]);
            population.push_back(cross_pair.first);
            population.push_back(cross_pair.second);
            //std::cout << "corsssingg" << std::endl;
        }
    }
}

void mutate_population(std::vector<std::vector<int>> &population, Params &params)
{
    for (int idx = 0; idx < population.size(); idx++)
    {
        int random = rand() % 101;
        if (random < params.crossover_factor * 100)
        {
            population[idx] = inversion_mutation(population[idx]);
        }
    }
}

void select_survivors(std::vector<std::vector<int>> &population, int next_population_size, Graph &graph, std::vector<int> &global_best_path, int &global_best_path_val)
{
    std::unordered_map<int, std::vector<int>> tsp_map;

    for (auto path : population)
    {
        tsp_map[tsp(path, graph)] = path;
    }

    std::map<int, std::vector<int>> ordered(tsp_map.begin(), tsp_map.end());

    if (ordered.begin()->first < global_best_path_val)
    {
        global_best_path_val = ordered.begin()->first;
        global_best_path = ordered.begin()->second;
    }
    size_t idx = 0;
    for (auto it = ordered.begin(); it != ordered.end() && idx < next_population_size; it++)
    {
        population[idx] = it->second;
    }
    population.resize(next_population_size);
}

void show_population(std::vector<std::vector<int>> &population)
{
    for (auto path : population)
    {
        std::cout << "\t";
        show_path(path);
    }
}

void show_generation(std::vector<std::vector<int>> &population, int gen_idx)
{
    std::cout << "Generation " << gen_idx << ": {" << std::endl;
    show_population(population);
    std::cout << "}" << std::endl;
}

bool operation_criterion(Params &params, std::chrono::time_point<std::chrono::system_clock> &starttime, std::chrono::seconds &timelimit)
{
    return std::chrono::system_clock::now() - starttime < timelimit;
}

void genetic_algorithm_tsp(Graph &graph, Params &params)
{
    std::vector<int> global_best_path;
    int global_best_path_val = INT_MAX;

    srand(time(NULL));

    // init population
    std::vector<std::vector<int>> population = create_random_population(graph, params);

    /*
    std::cout << "inversion mutation:" << std::endl;
    std::vector<int> mut_path = inversion_mutation(population[population.size() - 1]);
    show_path(mut_path);

    std::cout << "corssing pmx:" << std::endl;
    crossing_pair cross_path_pair = corssover_pmx(population[population.size() - 1], population[population.size() - 2]);
    show_path(cross_path_pair.first);
    show_path(cross_path_pair.second);
    */

    /*
    // crossover
    crossover_population(population, params);
    // mutation
    show_generation(population, 1);
    mutate_population(population, params);
    // survivors selection
    show_generation(population, 2);
    select_survivors(population, params.init_population_size, graph, global_best_path, global_best_path_val);
    show_generation(population, 3);
    */
    /*
    show_generation(population, 1);
    crossover_population(population, params);
    show_generation(population, 2);
    mutate_population(population, params);
    show_generation(population, 3);
    select_survivors(population, params.init_population_size, graph, global_best_path, global_best_path_val);
    show_generation(population, 4);
    */

   
    crossing_pair cp = corssover_pmx(population[0], population[1]);
    show_path(population[0]);
    show_path(population[1]);
    show_path(cp.first);
    show_path(cp.second);
  

    int generation_idx = 0;
    std::chrono::seconds timelimit = std::chrono::seconds{(int)params.duration};
    std::chrono::time_point<std::chrono::system_clock> starttime = std::chrono::system_clock::now();
    while (operation_criterion(params, starttime, timelimit))
    {
        // crossover
        crossover_population(population, params);
        // mutation
        mutate_population(population, params);
        // survivors selection
        select_survivors(population, params.init_population_size, graph, global_best_path, global_best_path_val);
        //show_generation(population, generation_idx);
        generation_idx++;
    }
    // best solution

    std::cout << "best path:" << std::endl;
    show_path(global_best_path);
    std::cout << "best path value:" << global_best_path_val << std::endl;
}
