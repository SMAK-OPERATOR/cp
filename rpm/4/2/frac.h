#pragma once
#include <iostream>
#include <cmath>
using namespace std;


class Frac{

    int num;
    int denum;

    public:

    Frac(int n = -1 , int d = -1 ) : num(n), denum(d) {}

    void setValues(int a, int b) {num = a, denum = b;}

    void  printValues(){cout << num << "/" << denum << endl;}

    friend Frac operator+(Frac a, Frac b);
    friend Frac operator*(Frac a, Frac b);
    friend Frac operator-(Frac a, Frac b);

    friend istream& operator>> (istream &in, Frac &Frac);
    friend ostream& operator<< (ostream &out, const Frac &Frac);

    friend Frac reverse(Frac a);
    friend void proper(Frac a);
};

