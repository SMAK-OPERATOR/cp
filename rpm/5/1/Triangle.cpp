#include "Triangle.h"

void Triangle::returnpoints() { cout << "\nPoints x,y: \n" << "   "  << fp << "   " << sp << "   " << thp << endl; }

ostream &operator<<(ostream &out, const Triangle &Triangle)
{
    out << "(" << Triangle.fp << ";" << Triangle.sp << ";" << Triangle.thp << ")" << endl;
    return out;
}

istream &operator>>(istream &in, Triangle &Triangle)
{
    in >> Triangle.fp;
    in >> Triangle.sp;
    in >> Triangle.thp;
    return in;
}

bool Triangle::efpist()
{
    double b[3] = {slength(fp, sp), slength(sp, thp), slength(fp, thp)};
    // cout << b[0] << endl << b[1] << endl << b[2] << endl;
    if (((b[0] + b[1]) > b[2]) && ((b[0] + b[2]) > b[1]) && ((b[2] + b[1]) > b[0]))
        return true;
    else
        return false;
}

void Triangle::angles()
{
    double b[3] = {slength(fp, sp), slength(sp, thp), slength(fp, thp)};
    cout << "Angles: " << acos((pow(b[0], 2) + pow(b[1], 2) - pow(b[2], 2)) / (2 * b[0] * b[1])) * 180 / 3.14 << "  " << acos((pow(b[0], 2) + pow(b[2], 2) - pow(b[1], 2)) / (2 * b[0] * b[2])) * 180 / 3.14 << "  " << acos((pow(b[1], 2) + pow(b[2], 2) - pow(b[0], 2)) / (2 * b[1] * b[2])) * 180 / 3.14 << endl;
}

double Triangle::perim()
{
    double b[3] = {slength(fp, sp), slength(sp, thp), slength(fp, thp)};
    return b[0] + b[1] + b[2];
}

double Triangle::area()
{
    double b[3] = {slength(fp, sp), slength(sp, thp), slength(fp, thp)};
    double p = perim() / 2;
    return sqrt(p * (p - b[0]) * (p - b[1]) * (p - b[2]));
}

bool Triangle::checktry()
{
    double b[3] = {slength(fp, sp), slength(sp, thp), slength(fp, thp)};
    if ((b[0] == b[1] == b[2]) && (b[0] != 0))
        return true;
    else
        return false;
}

bool checkequal(Triangle a, Triangle b)
{
    double c[3] = {slength(a.fp, a.sp), slength(a.sp, a.thp), slength(a.fp, a.thp)};
    double d[3] = {slength(b.fp, b.sp), slength(b.sp, b.thp), slength(b.fp, b.thp)};
    double buff = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 2; j > i; j--)
        {
            if (c[j] < c[j - 1])
            {
                buff = c[j - 1];
                c[j - 1] = c[j];
                c[j] = buff;
            }
        }
    }
    buff = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 2; j > i; j--)
        {
            if (d[j] < d[j - 1])
            {
                buff = d[j - 1];
                d[j - 1] = d[j];
                d[j] = buff;
            }
        }
    }
    if ((c[0] == d[0]) && (c[1] == d[1]) && (c[2] == d[2]))
        return true;
    else
        return false;
}