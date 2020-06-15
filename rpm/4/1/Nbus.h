#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
using std::string;
class Nbus
{
private:
    string num;
    string nroad;
    string user;
    bool where;
    Nbus *next;
public:
    friend class Bus;
};