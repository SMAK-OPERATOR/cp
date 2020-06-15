#include "input.hpp"

long long int get_long_int()
{
    long long int a;
    while(true)
    {
        cin >> a;
        if(!cin)
        {
            cout << "Invalid input, try using int values" << endl;
            cin.clear();
            while (cin.get() != '\n');
        }
        else break;
    }
    return a;
}

int get_int()
{
    int a;
    while(true)
    {
        cin >> a;
        if(!cin)
        {
            cout << "Invalid input, try using int values" << endl;
            cin.clear();
            while (cin.get() != '\n');
        }
        else break;
    }
    return a;
}

string get_char()
{
    int k=1;
    char a[30];
    char b[30];
    while(k==1)
    {
        int j=0;
        cin.getline(a, 30);
        int l=strlen(a);
        for(int i=0; i<l; i++)
        {
            if(a[i]!=' ')
            {
                b[j]=a[i];
                j++;
            }
        }
        b[j]='\0';
        if (b[0]=='\0')
        {
            cout << "Empty input!" << endl;
        }
        else
        {
            k--;
            return b;
        }
    }
    return 0;
}