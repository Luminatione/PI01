#include "Machine.h"

Machine::Machine(std::string startState, std::map<int, std::map<std::string, std::string>> transitions, std::vector<std::string> endingStates) : transitions(transitions), currentState(startState), endingStates(endingStates)
{
	if(!transitions.at(0).count(startState))
	{
		throw std::exception("Illegal start symbol");
	}
	path += startState;
}

void Machine::moveTape(int nextSymbol)
{
	if(transitions.count(nextSymbol))
	{
		currentState = transitions[nextSymbol][currentState];
		path += pathSeparator + currentState;
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

void Machine::logCurrentState(std::ostream& out)
{
	out << "Aktualny stan: " << currentState << std::endl;
}

void Machine::logPath(std::ostream& out)
{
	out << "Diagram przejsc " << path;
}

bool Machine::isInEndingState()
{
	return std::find(endingStates.begin(), endingStates.end(), currentState) != endingStates.end();
}
