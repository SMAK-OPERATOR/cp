#include "Bus.h"
#include "Nbus.h"

int main()
{
    system("cls");
    Bus bus;
    adds b;
    int z;
    do
    {
        cout << "\n 1 -> Show all buses \n 2 -> Status change \n 3 -> Show buses on base \n 4 -> Show buses on road \n 5 -> Add new bus \n 0 -> Exit \n";
        cout << "Input: ";
        cin >> z;
        switch (z)
        {
        case 1:
        {
            if (bus.getHead() == NULL)
                cout << "\n There are no buses\n";
            else
                bus.printall();
            break;
        }

        case 2:
        {
            cout << "\nEnter the number of bus\n" << endl;
            cout << "Input: ";
            string num1;
            fflush(stdin);
            getline(cin, num1);
            if (Nbus *k = bus.findnum(num1))
            {
                bus.printone(bus.stchange(k));
            }
            else
                cout << "\nThere's no buses with such number!\n";
            break;
        }

        case 3:
        {
            cout << "\nBuses on base: \n";
            bus.printon(false);
            break;
        }

        case 4:
        {
            cout << "\nBuses on road: \n";
            bus.printon(true);
            break;
        }

        case 5:
        {
            bus.add();
            break;
        }

        default:
            break;
        }
    } while (z != 0);
}
