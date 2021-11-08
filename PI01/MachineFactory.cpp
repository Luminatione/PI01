#include "MachineFactory.h"

Machine MachineFactory::CreateMachineFromFile(std::string configurationFileName, std::string startState)
{
	file = std::fstream(configurationFileName, std::ios::in);
	if (!file.is_open() || !file.good())
	{
		throw std::exception("Failed to open specified file");
	}
	int statesAmount, alphabetSize, endingStatesAmount;
	file >> statesAmount >> alphabetSize >> endingStatesAmount;

	std::vector<std::string> allStates = std::vector<std::string>(statesAmount);
	for (int i = 0; i < statesAmount; i++)
	{
		file >> allStates[i];
	}

	std::vector<int> alphabet = std::vector<int>(alphabetSize);
	for (int i = 0; i < alphabetSize; i++)
	{
		file >> alphabet[i];
	}

	std::map<int, std::map<std::string, std::string>> transitions = std::map<int, std::map<std::string, std::string>>();
	for (int i = 0; i < statesAmount; i++)
	{
		for (int j = 0; j < alphabetSize; j++)
		{
			file >> transitions[alphabet[j]][allStates[i]];
		}
	}

	std::vector<std::string> endingStates = std::vector<std::string>(endingStatesAmount);
	for (int i = 0; i < endingStatesAmount; i++)
	{
		file >> endingStates[i];
	}
	file.close();
	return Machine(startState, transitions, endingStates);
}

MachineFactory::~MachineFactory()
{
	if (file.is_open())
		file.close();
}
