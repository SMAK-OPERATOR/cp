#include <fstream>
#include <string>
#include <iostream>

class Writer
{
public:
    // std::string alphabet = {"qwertyuiopasdfghjklzxcvbnm{};\'\"&#^+/1234567890-=.><*"};
    std::string content;
    Writer() = default;
    Writer(std::istream &);
    void write(std::ofstream &);
    virtual ~Writer() = default;
};
