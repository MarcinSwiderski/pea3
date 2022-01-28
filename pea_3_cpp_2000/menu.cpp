#include "menu.hpp"
#include <iostream>
#include <Windows.h>

void Menu::enable()
{
	int select = 0;

	while (true)
	{

		std::cout << "Time [s] : " << params.duration << " s\n";
		std::cout << "Startowy rozmiar populacji: " << params.init_population_size << "\n";
		std::cout << "Parametr mutacyjny: " << params.mutation_factor << "\n";
		std::cout << "Parametr krzyżowania : " << params.crossover_factor << "\n\n";

		std::cout << graph.getDescription();
		std::cout << menu;
		//std::cout << graph.toString();

		cin >> select;
		switch (select)
		{
		case 1:
			if (file == "")
				std::cin >> file;
			else
				graph.readGraph(file);
			std::cout << graph.getDescription();
			break;
		case 2:
			std::cout << "Ustaw czas wykonywania:" << std::endl;
			params.enter_duration();
			break;
		case 3:
			std::cout << "Ustaw startowa wartosc populacji: " << std::endl;
			params.enter_init_population_size();
			break;
		case 4:
			std::cout << "Ustaw parametr mutacyjny: " << std::endl;
			params.enter_mutation_factor();
			break;
		case 5:
			std::cout << "Ustaw parametr krzyzowania: " << std::endl;
			params.enter_crossover_factor();
			break;
		case 6:
			std::cout << graph.toString();
			getchar();
			break;
		case 7:
			genetic_algorithm_tsp(graph, params);
			getchar();
			break;
		default:
			std::cout << "Wrong menu option" << std::endl;
			break;
		}
		cin.ignore();
		system("cls");
	}
}

Menu::Menu()
{

	menu.append("1) wczytaj graf\n");
	menu.append("2) czas wykonywania\n");
	menu.append("3) wartosc populacji\n");
	menu.append("4) parametr mutacyjny\n");
	menu.append("5) parametr krzyzowania\n");
	menu.append("6) wydrukuj aktualny graf\n");
	menu.append("7) uruchom algorytm genetyczny\n");
	menu.append("8) exit\n");

}


Menu::~Menu()
{
}
