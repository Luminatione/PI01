#pragma once

#include <vector>
#include <iostream>
#include <map>

#define MACHINE_NO_TRANSITION_SYMBOL "-"

class Machine
{
	std::map<int, std::map<std::string, std::string>> transitions;
	std::string currentState;
	std::string path;
	std::string pathSeparator = "->";
	std::vector<std::string> endingStates;

public:

	explicit Machine(std::string startState, std::map<int, std::map<std::string, std::string>> transitions, std::vector<std::string> endingStates);

	Machine() = default;

	void moveTape(int nextSymbol);

	std::string getCurrentState();

	void logCurrentState(std::ostream& out);

	void logPath(std::ostream& out);

	bool isInEndingState();
};
