#include <iostream>
#include "figures.h"
#include <vector>
int main()
{
    std::vector<Figure_ID> vect = {{false,1,3, "Just a line"}, {true,2,10, "BIG line"}};
    std::vector<IFigure*> FVect;
    FVect.push_back(IFigure::FactoryMethod(1, vect));
    FVect[0]->GetInfo();//ssssadsa
    return 0;
}