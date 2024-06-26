
#include "vendingMachineClass.h"

vendingMachineClass::vendingMachineClass()
:balance{0}, inputChar{0}
{
    cout << endl;
    cout << "The Vending Machine is on and ready to get your order !" << endl;
    cout << endl;
}

vendingMachineClass::~vendingMachineClass()
{
    cout << endl;
    cout << "The Vending Machine is off and out of order" << endl;
    cout << endl;
}

void vendingMachineClass::vendingMachineMenue()
{
    cout << "/*********************************************************/" << endl;
    cout << endl;
    cout << "Current balance is : " << balance << "€ ." << endl;
    cout << "You can enter money to the machine (Supported : 1€, 2€, 5€, 10€)" << endl;
    cout << "You can get Cola(c), Lemonade(l), Water(w) with entering key" << endl;
    cout << "If you want to cancel enter (x)" << endl;
    cout << endl;
    cout << "/*********************************************************/" << endl;

}

void vendingMachineClass::vendingMachineFunc()
{
    uint32_t temp = 0;

    cin.get(inputChar, sizeof(inputChar));
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This method used here to terminate the need for processing further buffer values.
    
    temp = vendingMachineInt(inputChar); // Processing the short string for Numerical value.

    cout << "/*********************************************************/" << endl;

    if(((inputChar[0] == 'c') ||  // Scanning for the character value.
       (inputChar[0] == 'l') ||
       (inputChar[0] == 'w')) && 
       (static_cast<uint32_t>(inputChar[1]) == 0))
       {
            if (balance >= everyDrinkCost)
            {
                balance -= everyDrinkCost;

                cout << endl;

                if(inputChar[0] == 'c')
                cout << "You can grab your Cola. Enjoy !" << endl;

                else if(inputChar[0] == 'l')
                cout << "You can grab your Lemonade. Enjoy !" << endl;

                else if(inputChar[0] == 'w')
                cout << "You can grab your Water. Enjoy !" << endl;

                cout << endl;

                vendingMachineReturn();
            }

            else
            {
                cout << endl;
                cout << "Not enough balance !!!" << endl;
                cout << "Please increase your balance" << endl;
                cout << endl;  
            }
       }

    else if((temp == coins[0]) || // Scanning for the Numerical value.
            (temp == coins[1]) ||
            (temp == coins[2]) ||
            (temp == coins[3]))
    {
        balance += temp;
        cout << endl;
        cout << "Amount of " << temp << "€ added to balance." << endl;
        cout << endl;
    }

    else if((inputChar[0] == 'x') && 
            (static_cast<uint32_t>(inputChar[1]) == 0)) // Canceling the Order and calculating the remaining amount according to standard Coins.
    {
        if(balance)
        {
            cout << endl;
            cout << "Oparation cancelled !" << endl;
            cout << endl;

            vendingMachineReturn();
        }

        else
        {
            cout << endl;
            cout << "Nothing to return !" << endl;
            cout << endl;
        }

    }

    else // Not supported input.
    {
        cout << endl;
        cout << "Input is not supported" << endl;
        cout << endl;
    }

    cout << "/*********************************************************/" << endl;
}

uint32_t vendingMachineClass::vendingMachineInt(const char *str)
{
    uint32_t tempVar = 0;

    for (size_t i = 0; (str[i] >= '0') && (str[i] <= '9'); i++)
    {
        if (str[i] >= '0' && str[i] <= '9') 
        {
            tempVar = tempVar * 10 + (str[i] - '0');
        } 

        else
        {
            break;
        }
    }

    return tempVar;
}

void vendingMachineClass::vendingMachineReturn()
{
    uint32_t temp = 0;
            
    for (auto i : coins)
    {
        temp = balance / i;

        if (temp)
        {
            balance -= temp * i;

            cout << endl;
            cout << "You receieve " << temp << "x of " << i << " € ." << endl;
            cout << endl;
        }

        else if (!(balance % i))
        {
            break;
        }
    }
}