
#ifndef _VENDING_MACHINE_CLASS_H_
#define _VENDING_MACHINE_CLASS_H_

#include <iostream>
#include <limits>

using namespace std;

/// @brief A vending machine object with everything you need.
class vendingMachineClass
{
private:

    /// @brief Amount of the machine balance.
    uint32_t balance;

    /// @brief Array for getting the input value from input stream.
    char inputChar [3];

    /// @brief Every Coin value.
    const uint32_t coins[4] {10, 5, 2, 1};

    /// @brief Cost of every Drink;
    const uint32_t everyDrinkCost = 2;

    /// @brief A private method that can extract any numerical value from the limited string.
    /// @param str Constant pointer to the C type string.
    /// @return An unsigned integer containing returned value.
    uint32_t vendingMachineInt(const char *str);

    /// @brief It returns the rest of the balance in supported format Coins.
    void vendingMachineReturn();

public:

    /// @brief The default constructor of Vending Machine.
    vendingMachineClass();
    // vendingMachineClass(const vendingMachineClass &source);
    // vendingMachineClass(const vendingMachineClass &&source);
    ~vendingMachineClass();
    /// @brief The menu containing instructions and the Balance value.
    void vendingMachineMenue();
    /// @brief The method responsible for processing input data and functionality.
    void vendingMachineFunc();
};


#endif