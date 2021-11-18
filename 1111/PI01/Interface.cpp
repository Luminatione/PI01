#include <fstream>

#include "Interface.h"

void Interface::beginHighlight()
{
	SetConsoleTextAttribute(console, highlightColor);
}

void Interface::endHighlight()
{
	SetConsoleTextAttribute(console, defaultColor);
}

void Interface::loadInterfaceString(std::string filePath)
{
	std::fstream file = std::fstream(filePath, std::ios::in);
	if (!file.is_open() || !file.good())
	{
		throw std::exception("Failed to open graph file");
	}
	file.seekg(0, std::ios::end);
	int size = file.tellg();
	interfaceRawString.resize(size);
	file.seekg(0, std::ios::beg);
	file.read(&interfaceRawString[0], size);
	file.close();
}

void Interface::displayFrame()
{
	system("cls");
	for (size_t i = 0; i < interfaceRawString.size(); i++)
	{
		if (interfaceRawString[i] != customColorSpacePrefix)
		{
			std::cout << interfaceRawString[i];
		}
		else if (interfaceRawString[i + 2] == machine->getCurrentState()[1])//if this is the same state machine currently is in
		{
			beginHighlight();
		}
		if (isblank(interfaceRawString[i]))
		{
			endHighlight();
		}
	}
}

Interface::Interface(const std::string& interfaceFilePath, Machine* machine) : machine(machine)
{
	loadInterfaceString(interfaceFilePath);
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	endHighlight();//make display consistent
}
