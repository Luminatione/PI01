#pragma once
#include <string>
#include <Windows.h>
#include "Machine.h"

class Interface
{
	int highlightColor = 12;
	int defaultColor = 7;
	char customColorSpacePrefix = '&';
	HANDLE console;

	std::string interfaceRawString;
	Machine* machine;

	void beginHighlight();
	void endHighlight();
	void loadInterfaceString(std::string filePath);
public:
	Interface(const std::string& interfaceFilePath, Machine* machine);

	void displayFrame();
};
