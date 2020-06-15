#include "frac.h"

int check(int a, int b) {
	a = abs(a);
	b = abs(b);
	while (a > 0 && b > 0) 
    {
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}
	return a + b;
}

void proper(Frac a)
{
    if (a.num < a.denum)
        cout << "The Fraction is proper\n";
    else if (a.num > a.denum)
        cout << "The Fractoin is improper\n";
}

ostream& operator<< (ostream &out, const Frac &Frac)
{
    out << Frac.num << "/" << Frac.denum << endl;
    return out;
}

istream& operator>> (istream &in, Frac &Frac)
{
    in >> Frac.num;
    in >> Frac.denum;
    return in;
}

Frac operator*(Frac a, Frac b)
{
    int n = a.num * b.num;
    int de = a.denum * b.denum;
    return Frac (n / check(n,de),de / check(n,de));
}

Frac operator+(Frac a, Frac b)
{
    if (a.denum != b.denum)
        {
            int k = a.denum;
            a.num = a.num * b.denum;
            a.denum = a.denum * b.denum;
            b.num = b.num * k;
            b.denum = b.denum * k;
        }
    int m = a.num + b.num;
    return Frac (m / check(m,a.denum),a.denum / check(m,a.denum));
}

Frac operator-(Frac a, Frac b)
{
    if (a.denum != b.denum)
        {
            int k = a.denum;
            a.num = a.num * b.denum;
            a.denum = a.denum * b.denum;
            b.num = b.num * k;
            b.denum = b.denum * k;
        }
    int m = a.num - b.num;
    return Frac (m / check(m,a.denum),a.denum / check(m,a.denum));
}

Frac reverse(Frac a)
{
    int m = a.denum;
    a.denum = a.num;
    a.num = m;
    return Frac (m / check(m,a.denum),a.denum / check(m,a.denum));
}