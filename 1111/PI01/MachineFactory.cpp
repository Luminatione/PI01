#include "MachineFactory.h"

MachineFactory::MachineFactory(std::string configurationFileName)
{
	file = std::fstream(configurationFileName, std::ios::in);
	if (!file.is_open() || !file.good())
	{
		throw std::exception("Failed to open configuration file");
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

	transitions = std::map<int, std::map<std::string, std::string>>();
	for (int i = 0; i < statesAmount; i++)
	{
		for (int j = 0; j < alphabetSize; j++)
		{
			file >> transitions[alphabet[j]][allStates[i]];
		}
	}

	endingStates = std::vector<std::string>(endingStatesAmount);
	for (int i = 0; i < endingStatesAmount; i++)
	{
		file >> endingStates[i];
	}
	file.close();

}

Machine MachineFactory::CreateMachine(std::string startState)
{
	return Machine(startState, transitions, endingStates);
}
