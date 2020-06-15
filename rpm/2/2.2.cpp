#include <iostream>
#include <cmath>
using namespace std;

void func(float x, int n)
{
	if (n != 0)
	{
		float k = 1/(2*x-1);
		printf("%3.2f ",k);
		if (x!=n)
		{
			x++;
			func(x,n);
		}
	}
}

int main()
{
	int n; 
	cout << "Enter n" << endl;
	cin >> n;
	func(1,abs(n));
}
