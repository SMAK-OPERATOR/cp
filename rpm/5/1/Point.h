#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point(double xx = 0, double yy = 0) : x(xx), y(yy) {}

    friend istream &operator>>(istream &in, Point &Point);
    friend ostream &operator<<(ostream &out, const Point &Point);
    friend double slength(Point a, Point b);
};