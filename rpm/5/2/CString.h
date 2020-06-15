#pragma once
#include <iostream>
#include <string>

using namespace std;
using std::string;

class CString
{
private:
    string data;
public:
    CString(){};
    friend istream &operator>>(istream &in, CString &CString);
    friend ostream &operator<<(ostream &out, const CString &CString);
    void showbin();
    void showoct();
    void showhex();

};