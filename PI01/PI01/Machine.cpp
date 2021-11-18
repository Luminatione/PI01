#include "Machine.h"

Machine::Machine(std::string startState, std::map<int, std::map<std::string, std::string>> transitions, std::vector<std::string> endingStates) : transitions(transitions), currentState(startState), endingStates(endingStates)
{
	if(!transitions.at(0).count(startState))
	{
		throw std::exception("Illegal start symbol");
	}
}

void Machine::moveTape(int nextSymbol)
{
	if(transitions.count(nextSymbol))
	{
		currentState = transitions[nextSymbol][currentState];
		if(currentState == MACHINE_NO_TRANSITION_SYMBOL)
		{
			throw std::exception("Illegal transition");
		}
		return;
	}
	throw std::exception("Illegal transition");
}

std::string Machine::getCurrentState()
{
	return currentState;
}

bool Machine::isInEndingState()
{
	return std::find(endingStates.begin(), endingStates.end(), currentState) != endingStates.end();
}
