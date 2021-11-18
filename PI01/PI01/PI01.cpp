// PI01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>

#include "Interface.h"
#include "MachineFactory.h"


int main()
{
    MachineFactory machineFactory("conf");
    Machine machine;
	try
	{
        machine = machineFactory.CreateMachine("q0");
	}
	catch (std::exception &e)
	{
        std::cout << "Wyjatek: " << e.what() << "\nNie udalo sie utworzyc automatu z pliku konfiguracyjnego\n";
        return 1;
	}
   
    try
    {
        Interface ui = Interface("graph", &machine);
        int tapeLength;
        std::cin >> tapeLength;
        std::vector<int> tape(tapeLength);
        for (int i = 0; i < tapeLength; i++)
        {
            std::cin >> tape[i];
        }
        ui.displayFrame();
        _getch();
        for (int i = 0; i < tapeLength; i++)
        {
            machine.moveTape(tape[i]);
            ui.displayFrame();
            _getch();
        }
        if(machine.isInEndingState())
        {
            std::cout << "Ciag zostal zaakceptowany\n";
        }
        else
        {
            std::cout << "Ciag nie zostal zaakceptowany, wykonywanine nie zakonczylo sie na symbolu koncowym\n";
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Wyjatek: " << e.what() << "\nCiag nie zostal zaakceptowany \n";
        return 1;
    }
    
   
    return 0;
}