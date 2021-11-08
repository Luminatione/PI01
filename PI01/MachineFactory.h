#pragma once

#include <string>
#include <fstream>

#include "Machine.h"

class MachineFactory
{
	std::fstream file;
public:

	Machine CreateMachineFromFile(std::string configurationFileName, std::string startState);
	~MachineFactory();
};
