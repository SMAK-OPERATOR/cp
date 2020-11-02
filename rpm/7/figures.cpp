#include "figures.h"
#include <algorithm>
#include <iostream>
IFigure *IFigure::FactoryMethod(int id, std::vector<Figure_ID> &vect)
{
    IFigure *p;
    for (auto i : vect)
    {
        if (i.ID == id)
        {
            if (i.IsFigureSuper == true)
            {
                p = new SuperFigure();
            }
            else
            {
                p = new CommonFigure();///sssss
            }
            p->ID = i.ID;
            p->QoC = i.QoC;
            p->DoF = i.DoF;
            return p;
        }
    }
    std::cout << "There is no figure with this ID" << std::endl;
    return nullptr;
}

void CommonFigure::GetInfo() const
{
    std::cout << "This is common figure. Id is equal " << ID << '\n'
              << "Quantity of cells is equal " << QoC << '\n'
              << "Descrption of figure " << DoF << std::endl;
}

void SuperFigure::GetInfo() const
{
    std::cout << "This is super figure. Id is equal " << ID << '\n'
              << "Quantity of cells is equal " << QoC << '\n'
              << "Descrption of figure " << DoF << std::endl;
}