#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;
double f(double x) {
 
    return   x*x*x + 3*x +1;
}
 
double f1(double x) {
 
    return   3*x*x + 3;
}
 
double f2(double x) {
 
    return   6*x;
}
 
int main() {
    int n=0;
    double a,b,c,eps;
    a = 0;
    b = -0.5;
    eps = 0.001;
    if(f(a)*f2(a)>0) c=a;
    else c=b;
    do {
        c=c-f(c)/f1(c);
        n+=1;
        cout << n << "   " << c << "   " << fabs(f(c)) << endl;
    }
    while (fabs(f(c))>=eps);
    system("pause");    
}