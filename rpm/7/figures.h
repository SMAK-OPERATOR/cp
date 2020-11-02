#include <string>
#include <vector>
struct Figure_ID
{
    bool IsFigureSuper;
    int ID, QoC;
    std::string DoF;
};
class IFigure
{
protected:
    int ID;
    int QoC; //Quantity of cells
    std::string DoF; //Description of figure
public:
    virtual ~IFigure() = default;
    virtual void GetInfo() const = 0;
    static IFigure* FactoryMethod(int id, std::vector<Figure_ID> &vect);
};


class CommonFigure : public IFigure
{
public:
    virtual void GetInfo() const override;
};


class SuperFigure : public IFigure
{
public:
    virtual void GetInfo() const override;
};


