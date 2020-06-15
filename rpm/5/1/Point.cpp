#include "Point.h"

ostream &operator<<(ostream &out, const Point &Point)
{
    out << "(" << Point.x << ";" << Point.y << ")" << endl;
    return out;
}

istream &operator>>(istream &in, Point &Point)
{
    in >> Point.x;
    in >> Point.y;
    return in;
}

double slength(Point a, Point b)
{
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}