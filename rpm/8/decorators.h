#include "writer.h"
#include "vector"
class IDecorator : public Writer
{
protected:
    Writer *writer;

public:
    IDecorator(Writer *);
    virtual void change() = 0;
};

class HtmlDecorator : public IDecorator
{
public:
    HtmlDecorator(Writer *);
    virtual void change() override;
};

class LineDecorator : public IDecorator
{
private:
    friend std::string StoI(int I);
public:
    LineDecorator(Writer *);
    virtual void change() override;
};

class CPPDecorator : public IDecorator
{
private:
    friend std::vector<std::string> FromSpaceToSpace(std::string);
public:
    CPPDecorator(Writer *);
    virtual void change() override;
};
