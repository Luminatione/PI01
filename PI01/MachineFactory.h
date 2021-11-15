#pragma once

#include <string>
#include <fstream>

#include "Machine.h"

class MachineFactory
{
	std::fstream file;
	std::map<int, std::map<std::string, std::string>> transitions;
	std::vector<std::string> endingStates;
public:
	MachineFactory(std::string configurationFileName);
	Machine CreateMachine(std::string startState);

	~MachineFactory();
};
