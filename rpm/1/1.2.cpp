#include <iostream>
#include <math.h>

using namespace std;

float kust(int M)
{
	float sum = 0;
	float kol = 0;
	int k;
	int m = 0;
	do
	{
		if(abs(M) < 10)
		{
			sum = sum + M;
			kol++;
			m = 1;
		}
		else if (abs(M)> 10)
		{
			k = M % 10;
			sum = sum + k;
			kol++;
			M = M / 10;
		}
	}
	while(m != 1);
	return(sum/kol);
}

int main()
{
	int N; 
	cout << "Enter number of elements" << endl;
	cin >> N;
	int M[N];
	float sr;
	cout << "Enter elements" << endl;
	for(int i = 0;i != N;i++)
		cin >> M[i];
	for(int i = 0;i != N;i++)
	{
		sr = kust(M[i]);
		printf("%3.2f ",sr);
	}
}

