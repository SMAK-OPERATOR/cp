#include <cmath>
#include <iostream>

using namespace std;

int is_prime(int x)
{
	if (x == 0)
		return 2;
	if (((x%2==0)||(x%3==0))&&(x!=2)&&(x!=3))
		return 0;
	else if(x != 1)
		return 1;
	return 2;
}

int main()
{
	int n, s, l;
	float k;
	cout << "Enter size of matrix" << endl;
	cin >> n;
	int a[n][n];
	cout << "Enter matrix" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int j = 0; j < n; j++)
	{
		if(j%2!=0)
		{
			s = 0;
			l = 0;
			for (int i = 0; i < n; i++)
			{
				if (is_prime(a[i][j])==0)
				{
					s+=a[i][j];
					l++;
				}
			}
			if (l>0)
			{
			k=s/l;
			printf("%4.1f ", k);
			}
			else if ( l == 0)
			printf ("%4.1f",s);
		}
		else if(j%2 == 0)
		{
			s = 0;
			l = 0;
			for (int i = 0; i < n; i++)
			{
				if (is_prime(a[i][j])==1)
				{
					s+=a[i][j];
					l++;
				}
			}
			if (l>0)
			{
			k=s/l;
			printf("%4.1f ", k);
			}
			else if ( l == 0)
			printf ("%4.1f",s);
		}
	}
	cout << endl;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d ", a[i][j]);
		}
		cout << endl;
	}
	return 0;
}

