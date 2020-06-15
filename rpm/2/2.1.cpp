#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char m[255];
	int i = 0;
	cout << "Enter string" << endl;
	char buf;
	int ii;
	int kol = 0;
	cin.getline(m, 255);
	int nbuf = -1;
	int f = 0;
	do
	{
		if ((m[i] != ' ')&&(m[i] != ',')&&(m[i] != '.'))
		{
			buf = m[i];
			nbuf = i;
			f = 1;
		}
		i++;
	}
	while(f != 1);
	int ads = strlen(m);
	for(i = 0;m[i] != '\0';i++)
	{ 
		if(((m[i] == ' ')||(m[i] == ',')||(m[i] == '.')||(m[i+1] == '\0')||(ads == 1))&&(i>=nbuf))
		{
			f = i-1;
			if ((m[i+1] == '\0')&&((m[i] != ' ')&&(m[i] != ',')&&(m[i] != '.')))
			f = i;
			if(m[f]== buf)
			{
				//cout << "buf = " << buf << endl;
				//cout << "m = " << m[i] << endl;
				//cout << "nbuf = " << nbuf << endl;
				//cout << "i = " << i << endl;
				f = i;
				if ((m[i+1] == '\0')&&((m[i] != ' ')&&(m[i] != ',')&&(m[i] != '.')))
				f = i+1;
				for(ii = nbuf;ii!=(f);ii++)
				{
					cout << m[ii];
				}
				cout << endl;
				kol++;
				nbuf = -1;
				ii = i;
				f = 0;
				do
				{
					if ((m[ii] != ' ')&&(m[ii] != ',')&&(m[ii] != '.'))
					{
						buf = m[ii];
						nbuf = ii;
						f = 1;
					}
					ii++;
				}
				while(f != 1);
			}
			else
			{
				ii = i;
				f = 0;
				do
				{
					if ((m[ii] != ' ')&&(m[ii] != ',')&&(m[ii] != '.'))
					{
						buf = m[ii];
						nbuf = ii;
						f = 1;
					}
					ii++;
				}
				while(f != 1);
			}
		}
	}
	cout << "kol = " << kol << endl;
}
