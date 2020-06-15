#pragma once
#include "Triangle.h"

class TryTri : public Triangle
{
private:
    double med;

public:
    TryTri(double m = 0) : med(m){};
    double returnmed();
};
