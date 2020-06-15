// Составить программу, которая содержит динамическую информацию о наличии автобусов в автобусном парке.
// Сведения о каждом автобусе включают:
// •	номер автобуса;
// •	фамилию и инициалы водителя;
// •	номер маршрута;
// •	признак того, где находится автобус — на маршруте или в парке.
// Программа должна обеспечивать:
// •	начальное формирование данных обо всех автобусах в видесписка;
// •	при выезде каждого автобуса из парка вводится номер автобуса, и программа устанавливает значение признака «автобус на маршруте»;
// •	при въезде каждого автобуса в парк вводится номер автобуса, и программа устанавливает значение признака «автобус в парке»;
// •	по запросу выдаются сведения об автобусах, находящихся в парке, или об автобусах, находящихся на маршруте.



#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>

using namespace std;

    struct bus
    {
        char num[21];
        char user[21];
        char nroad[21];
        bool where; // 0 - дома , 1 - на маршруте
        bus* next;
        bus* prev;
    };

    bus* first(char num[21], char user[21],char nroad[21])
    {
        bus* g = new bus;
        strcpy(g->num,num);
        strcpy(g->user,user);
        strcpy(g->nroad,nroad);
        g->where = false;
        g->next = g->prev = nullptr;
        return g;
    }

    void add (bus** m, char num[21],char user[21],char nroad[21])
    {
        bus* g = new bus;
        strcpy(g->num,num);
        strcpy(g->user,user);
        strcpy(g->nroad,nroad);
        g->where = false;
        g->next = nullptr;
        g->prev = *m;
        (*m)->next = g;
        *m = g;
    }

    bus* findnum(bus* const k, char num[21])
    {
        bus* g = k;
        while (g)
        {
            if(strcmp(g->num,num) == 0) 
                break;
            g = g->next;
        }
        return g;
    }




int main()
{
    char num[100];
    char nroad[100];
    char user[100];
    char tnum[21];
    char tuser[21];
    char tnroad[21];
    int j = 0;
    cout << "Enter the number of the first bus \n Input:  ";
    fflush(stdin);
    cin.getline(num,100);
    for (int i = 0; num[i] != '\0'; i++)
        {
            if (num[i] != ' ')
            {
                tnum[j] = num[i];
                j++;
            }
        }
    tnum[j]='\0';
    cout << "\nEnter the name of the first bus user \n Input:  ";
    fflush(stdin);
    cin.getline(user,100);
    j = 0;
    for (int i = 0; user[i] != '\0'; i++)
            {
                if ((user[i] == ' ') && (user[i+1] != ' '))
                {
                    tuser[j] = user[i];
                    j++;
                }
                else if (user[i] != ' ')
                {
                    tuser[j] = user[i];
                    j++;
                }

            }
    tuser[j]='\0';
    cout << "\nEnter the route number of first bus \n Input:  ";
    fflush(stdin);
    cin.getline(nroad,100);
    j = 0;
    for (int i = 0; nroad[i] != '\0'; i++)
            {
                if (nroad[i] != ' ')
                {
                    tnroad[j] = nroad[i];
                    j++;
                }
            }
    tnroad[j]='\0';
    bus* m = first(tnum,tuser,tnroad);
    bus* ml = m;

    // add(&ml,"2","Vladimir Pirovski","2");
    // add(&ml,"3","Ignatiy Czarev","3");
    // add(&ml,"4","Daniil Sotnikov","4");
    // add(&ml,"5","Valeriy Galahov","5");

int z;
char num1[11];
do
{
    cout << "\n 1 -> Show all buses \n 2 -> Status change \n 3 -> Show buses on base \n 4 -> Show buses on road \n 5 -> Add new bus \n 0 -> Exit \n";
    cout << "Input: ";
    cin >> z;
    int kk = 0,kv = 0;
    switch(z)
    {
        case(1):
        {
            bus* pv = m;
            cout << endl;
            while (pv)
            {
                cout << "Num: " << pv->num << " Driver: " << setw(20) << left << pv->user << " NRoad: " << pv->nroad;
                if ((pv->where) == false)
                    cout << " On base" << endl;
                else if ((pv->where) == true)
                    cout << " On road" << endl;
                pv = pv->next;
            }   
            break;
            cout << endl;
        }

        case(2):
        {
            cout << "Enter the number of bus" << endl;
            fflush(stdin);
            cin.getline(num1,21);
            if(bus* pv = findnum(m, num1))
            {
                pv->where = !(pv->where);
                cout << "Num: " << pv->num << " Driver: " << setw(20) << left << pv->user << " NRoad: " << pv->nroad;
                if ((pv->where) == false)
                    cout << " On base" << endl;
                else if ((pv->where) == true)
                    cout << " On road" << endl;
            }
            else
                cout << "There's no buses with such number!\n";
            break;
        }
        
        case(3):
        {
            cout << "\nBuses on base:\n";
            bus* pv = m;
            cout << endl;
            while (pv)
            {
                kv++;
                if ((pv->where) == false)
                    cout << "Num: " << pv->num << " Driver: " << setw(20) << left << pv->user << " NRoad: " << pv->nroad << " On base" << endl;
                else
                kk++;
                pv = pv->next;
            }
            if (kv == kk)
                cout << "There are no buses on road" << endl;   
            break;
        }

        case(4):
        {
            cout << "\nBuses on road:\n";
            bus* pv = m;
            cout << endl;
            while (pv)
            {
                kv++;
                if ((pv->where) == true)
                    cout << "Num: " << pv->num << " Driver: " << setw(20) << left << pv->user << " NRoad: " << pv->nroad << " On road" << endl;
                else
                kk++;
                pv = pv->next;
            }
            if (kv == kk)
                cout << "There are no buses on road" << endl;
            break;
        }

        case(5):
        {
            cout << "Enter the number of the bus \n Input:  ";
            fflush(stdin);
            cin.getline(num,100);
            j = 0;
            for (int i = 0; num[i] != '\0'; i++)
                {
                    if (num[i] != ' ')
                    {
                        tnum[j] = num[i];
                        j++;
                    }
                }
            tnum[j]='\0';
            cout << "\nEnter the name of the first bus user \n Input:  ";
            fflush(stdin);
            cin.getline(user,100);
            j = 0;
            for (int i = 0; user[i] != '\0'; i++)
                {
                    if ((user[i] == ' ') && (user[i+1] != ' '))
                    {
                        tuser[j] = user[i];
                        j++;
                    }
                    else if (user[i] != ' ')
                    {
                        tuser[j] = user[i];
                        j++;
                    }

                }
            tuser[j]='\0';
            cout << "\nEnter the route number of first bus \n Input:  ";
            fflush(stdin);
            cin.getline(nroad,100);
            j = 0;
             for (int i = 0; nroad[i] != '\0'; i++)
                    {
                        if (nroad[i] != ' ')
                        {
                            tnroad[j] = nroad[i];
                            j++;
                        }
                    }
            tnroad[j]='\0';
            add(&ml,tnum,user,tnroad);

        }

        default:
        cout << "Exiting" << endl;
        break;
    }
}while(z!=0);
  
    system("pause");
}