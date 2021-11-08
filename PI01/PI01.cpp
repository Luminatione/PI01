// PI01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Interface.h"
#include "MachineFactory.h"

int main()
{
    MachineFactory machineFactory;
    Machine machine;
	try
	{
        machine = machineFactory.CreateMachineFromFile("conf", "q0");
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
        ui.displayFrame();
        for (int i = 0; i < tapeLength; i++)
        {
            int temp;
            std::cin >> temp;
            machine.moveTape(temp);
            ui.displayFrame();
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