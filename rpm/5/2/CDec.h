#include "CString.h"

class CDec
{
private:
    int idata;
public:
    CDec(int a = 0):idata(a){};
    friend istream &operator>>(istream &in, CDec &CDec);
    friend ostream &operator<<(ostream &out, const CDec &CDec);
    void showbin();
    void showoct();
    void showhex();
};