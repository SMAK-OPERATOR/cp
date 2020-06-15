#include "frac.h"

int main(){
    Frac a, b, c;
    cout << "Enter the numerator and denominator for the first fraction:\nInput:  ";
    cin >> a;
    cout << "\nEnter the numerator and denominator for the second fraction:\nInput:  ";
    cin >> b;
    cout << "\nEnter the numerator and denominator for the third fraction:\nInput:  ";
    cin >> c;
    cout << "Fractions you've input: \n" << a << b << c << endl;
    Frac ra = a + b;
    Frac rb = a - c;
    Frac rc = rb * ra;
    cout << "R = " << rc;
    proper(rc);
    cout << "1/R = " << reverse(rc);
    proper(reverse(rc));
    system("pause");
}