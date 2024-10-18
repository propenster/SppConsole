#include <iostream>
#include <cstdlib>
#include <string>
#include "Backend.h"







int main() {
	std::string input = "";
	Backend backend = { "" };

	backend.DrawASCIIArt();

	std::vector<int> multiVersion = { 2, 3 };
	int version = 3;
	//Engine engine(version, nullptr); //to use all versions...1,2,3
	Engine engine(version, &multiVersion);

	


	while (true) {
		std::cout << "Enter lines separated by a space e.g 1.20 3.50 4.25: ";
		if (!std::getline(std::cin, input)) {
			std::cerr << "Error reading input or EOF reached" << std::endl;
			continue;
		}
		if (input == "cls")
		{
			system("cls");
			continue;
		}
		if (input == "exit") {
			std::cout << "Exiting..." << std::endl;
			break;
		}
		//Score& result = backend.RunHighestScoringHalf(engine, input);
		//std::cout << result.ToString(input) << std::endl;
		//backend.RunSeptember2024(input);
		//backend.RunPrimalSumsHSH(input);
		//backend.RunSumAdjacency2024(input);
		//backend.RunSumAdjacency2024Improved(input);
		backend.RunSumAdjacency2024Improved34(input);

	}


	std::cin.get();
	return 0;
}