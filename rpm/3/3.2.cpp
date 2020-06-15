
// Описать структуру с именем WORKER, содержащую следующие поля: фамилия и инициалы работника; название занимаемой̆ должности; год поступления на работу. 
// Написать программу, выполняющую следующие действия:
// •	ввод с клавиатуры данных в массив;
// •	записи должны быть размещены по алфавиту;
// •	вывод на дисплей фамилий работников, чей стаж работы в организации превышает значение, введенное с клавиатуры;
// •	если таких работников нет, вывести на дисплей соответствующее сообщение.



#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    struct worker
    {
        char name[21];
        char pos[21];
        int year;
        int k;
    };
    int n;
    char name[100];
    char pos[100];
    int k;
    int j;
    do{
		fflush(stdin);
		cin.clear();
        cout << "Enter amount of workers: ";
        cin >> n;
		if ((!(cin)))
		{
			k = 1;
			cout << "Invalid input, try again" << endl;
		}
		else
			k = 0;
    }while(k == 1);
    worker z[n];
    for(int i = 0;i != n;i++)
    {
        if (i == 0)
            cout << "\nFirst worker \n";
        else
            cout << "\nNext worker \n";
        fflush(stdin);
        cin.clear();
        cout << "\nEnter name: ";
        cin.getline(name,100);
        j = 0;
        for (int m = 0; name[m] != '\0'; m++)
            {
                if ((name[m] == ' ') && (name[m+1] != ' '))
                {
                    z[i].name[j] = name[m];
                    j++;
                }
                else if ((name[m] != ' ') && (name[m] != '0') && (name[m] != '1') && (name[m] != '2') && (name[m] != '3') && (name[m] != '4') && (name[m] != '5') && (name[m] != '6') && (name[m] != '7') && (name[m] != '8') && (name[m] != '9'))
                {
                    z[i].name[j] = name[m];
                    j++;
                }
            }
        z[i].name[j]='\0';
        fflush(stdin);
        cin.clear();
        cout << "\nEnter Posititon: ";
        cin.getline(pos,100);
        j = 0;
        for (int m = 0; pos[m] != '\0'; m++)
            {
                if (pos[m] != ' ')
                {
                    z[i].pos[j] = pos[m];
                    j++;
                }
            }
        z[i].pos[j]='\0';
        do{
            fflush(stdin);
            cin.clear();
            cout << "\nEnter year of employment: ";
            cin >> z[i].year;
            if ((z[i].year > 2020) || (z[i].year < 0) || (!(cin)))
            {
                k = 1;
                cout << "Invalid input, try again" << endl;
            }
            else
                k = 0;
        }while(k == 1);
    }
    worker buf;
    char alp[27] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0;i != n;i++)
    {
        int j = 0;
        do
        {
            if(z[i].name[0] == alp[j])
            {
                z[i].k = j+1;
                // cout << z[i].k << endl;
                j = 27;
            }
            j++;
        } while (j != 28);
    }
    for(int i = 0; i != n - 1;i++)
    {
        for (int j = n - 1; j != i; j--)
        {
            if(z[j].k < z[j-1].k)
            {
                strcpy(buf.name,z[j-1].name);
                strcpy(buf.pos , z[j-1].pos);
                buf.year = z[j-1].year;
                buf.k = z[j-1].k;

                strcpy(z[j-1].name , z[j].name);
                strcpy(z[j-1].pos , z[j].pos);
                z[j-1].year = z[j].year;
                z[j-1].k = z[j].k;
                
                strcpy(z[j].name , buf.name);
                strcpy(z[j].pos , buf.pos);
                z[j].year = buf.year;
                z[j].k = buf.k;
            }
        }
    }
    cout << endl;
    for(int i = 0;i != n;i++ )
    {
        cout << z[i].name << " ";
        cout << z[i].pos << " ";
        cout << z[i].year << " ";
        // cout << z[i].k << endl;
        cout << endl;
    }
    int st;
    cout << "\nEnter with what experience show workers " << endl;
    cin >> st;
    int m = 0;
    for(int i = 0;i != n; i++)
    {
        if((2020 - z[i].year) > st )
        {
            cout << z[i].name << endl;;
            m = 1;
        }
    }
    if (m == 0)
    cout << "There are no workers with such work experience" <<endl;
    system("pause");
}