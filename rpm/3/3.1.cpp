//Создайте структуру Треугольник с тремя элементами a, b, c – длины 3-х сторон. Найдите, у какого из трех заданных треугольников площадь наибольшая?

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	struct tri
	{
		float a;
		float b;
		float c;
		float p;
		float s;
	};
	tri z[3];
	int a;
	int k;
	for(int i = 0;i != 3;i++)
	{
		do{
			do{
				fflush(stdin);
				cin.clear();
				cout << "Enter a" << endl;
				cin >> z[i].a;
				if ((!(cin)))
				{
					k = 1;
					cout << "Invalid input, try again" << endl;
				}
				else
					k = 0;
        	}while(k == 1);
			do{
				fflush(stdin);
				cin.clear();
				cout << "Enter b" << endl;
				cin >> z[i].b;
				if ((!(cin)))
				{
					k = 1;
					cout << "Invalid input, try again" << endl;
				}
				else
					k = 0;
        	}while(k == 1);
			do{
				fflush(stdin);
				cin.clear();
				cout << "Enter c" << endl;
				cin >> z[i].c;
				if ((!(cin)))
				{
					k = 1;
					cout << "Invalid input, try again" << endl;
				}
				else
					k = 0;
        	}while(k == 1);						
			z[i].p = (z[i].a+z[i].b+z[i].c)/2;
			if (((z[i].a + z[i].b) > z[i].c) && ((z[i].a + z[i].c) > z[i].b) && ((z[i].c + z[i].b) > z[i].a))
				{
					a = 1;
					cout <<"The triangle exsists\n";
				}

			else{
					a = 0;
					cout << "The triangle doesn't exsist, try again\n" << endl;
				}
		}while(a == 0);
	}
	float S = -1;
		for(int i = 0;i != 3;i++)
	{
		z[i].s = sqrt(z[i].p * (z[i].p - z[i].a) * (z[i].p - z[i].b) * (z[i].p - z[i].c));
		if (S < z[i].s)
		S = z[i].s;
		cout << z[i].s << endl;
	}
	cout << "The biggest S is " << S << endl;
	system("pause");
}
