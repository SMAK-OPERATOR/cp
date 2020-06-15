#pragma once
#include "Point.h"

class Triangle : public Point
{
protected:
    Point fp, sp, thp;

public:
    Triangle(Point fpfp = 0, Point spsp = 0, Point thpthp = 0) : fp(fpfp), sp(spsp), thp(thpthp) {}

    friend istream &operator>>(istream &in, Triangle &Triangle);
    friend ostream &operator<<(ostream &out, const Triangle &Triangle);

    void returnpoints();
    bool efpist();
    void angles();
    double perim();
    double area();
    bool checktry();
    void returnangles();
    friend bool checkequal(Triangle a, Triangle b);

    void outlength() { cout << "The length of the sides of the triangle is " << slength(fp, sp) << ", " << slength(sp, thp) << ", " << slength(fp, thp) << endl; }
};
