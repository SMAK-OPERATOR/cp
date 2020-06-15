#include "TryTri.h"
#include "Point.h"
#include "Triangle.h"

int main()
{
    cout << "Input amount of non-equilateral triangles:\nInput: ";
    int amount[2];
    cin >> amount[0];
    cout << "Input amount of equilateral triangles:\nInput: ";
    cin >> amount[1];
    Triangle a[amount[0]];
    TryTri b[amount[1]];

    for (int k = 0; k < amount[0]; k++)
    {
        int i = 0;
        do
        {
            cout << "\nInput coordinates of non-equilateral triangle:\nInput: ";
            Point l[3];
            cin >> a[k];
            if (a[k].efpist() == true)
                i = 0;
            else if (a[k].efpist() == false)
            {
                i = 1;
                cout << "The triangle doesn't exist, try again";
            }
            else if (a[k].checktry() == true)
            {
                i = 1;
                cout << "The triangle is equilateral, try again";
            }
        } while (i == 1);
    }

    for (int k = 0; k != amount[1]; k++)
    {
        int i = 0;
        do
        {
            cout << "\nInput coordinates of equilateral triangle:\nInput: ";
            cin >> b[k];
            if (b[k].efpist() == true)
                i = 0;
            else if (b[k].efpist() == false)
            {
                i = 1;
                cout << "The triangle doesn't exist, try again\n";
            }
            else if (b[k].checktry() == false)
            {
                i = 1;
                cout << "The triangle is non-equilateral, try again";
            }

        } while (i == 1);
    }

    if (amount[0] != 0)
    {
        for (int m = 0; m < amount[0]; m++)
        {
            cout << m + 1 << "Non-equilateral Triangle: \n";
            a[m].returnpoints();
            a[m].outlength();
            a[m].angles();
            cout << "Perimeter is " << a[m].perim() << endl;
            cout << "Area of triangle is " << a[m].area() << endl;
        }
    }
    else
        cout << "\nThere are no Non-equilateral Triangles\n";

    if (amount[1] != 0)
    {
        for (int m = 0; m < amount[1]; m++)
        {
            cout << m + 1 << " Equilateral Triangle: \n";
            b[m].returnpoints();
            a[m].outlength();
            b[m].angles();
            cout << "Perimeter is " << b[m].perim() << endl;
            cout << "Area of triangle is " << b[m].area() << endl;
        }
    }
    else
        cout << "\nThere are no equilateral Triangles\n";

    int koleq = 0;
    for (int m = 0; m < amount[0] - 1; m++)
    {
        for (int j = amount[0] - 1; j > m; j--)
        {
            if ((checkequal(a[m], a[j])) == true)
            {
                if (m != j)
                {
                    cout << "Triangle " << m << " equal to " << j << endl;
                    koleq++;
                }
            }
        }
    }
    if (koleq == 0)
        cout << "\nThere are no equal triangles\n";
    if (amount[1] != 0)
    {
        double max = 0;
        int nmax = -1;
        for (int m = 0; m < amount[1]; m++)
        {
            if (max < b[m].returnmed())
            {
                max = b[m].returnmed();
                nmax = m + 1;
            }
        }
        cout << "\n"
             << nmax << " Equilateral triangle has the largest median, it's = " << max << endl;
    }
    system("pause");
}