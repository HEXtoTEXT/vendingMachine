#include "vendingMachineClass.h"

/// @brief Main function of the program.
/// @return just a dummy return.
int main()
{
    vendingMachineClass vendingMachine;

    while (1)   
    {
        vendingMachine.vendingMachineMenue();
        vendingMachine.vendingMachineFunc();
    }

    return 1;
}