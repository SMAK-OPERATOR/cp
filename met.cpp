#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
const double epsilon = 0.001;
 
double f(double x)
{
    return x*x*x- 3*x - 1;
}
 
int main()
{
    double a, b, c;
    a = -0.5;
    b = 0;
    int i = 1;
    while (b - a > epsilon){
        c = (a + b) / 2;
        cout << setw(3) << left << i << "   "  << setw(10) << left <<  c << "   " << setw(10) << left << b - a  << endl;

        if(f(b) * f(c) < 0)
        {
            a = c;
            i++;
        }
        else
        {
            i++;
            b = c;
        }
            
    }
    cout << setw(3) << left <<  i << "   " << setw(10) << left << (a + b) / 2 << "   " << setw(10) << left << b - a  << endl;

    system("pause");
}