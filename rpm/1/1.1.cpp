#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	
	int x;
	cout << "Enter x" << endl;
	cin >> x;
	int y1 = pow(x,3);
	int y2 = pow(x,3) + 1;
	float y3 = 1 / (1 + pow(x,2));
	cout << "y1 = " << y1 << endl << "y2 = " << y2 << endl << "y3 = " << y3 << endl;
	if (y1 < 0)
		cout << "y1 is odd" << endl;
	else if (y1 >= 0) 
		cout << "y1 is even" << endl;
	if (y2 < 0)
		cout << "y2 is odd" << endl;
	else if (y2 >= 0) 
		cout << "y2 is even" << endl;
	if (y3 < 0)
		cout << "y3 is odd" << endl;
	else if (y3 >= 0) 
		cout << "y3 is even" << endl;
}

