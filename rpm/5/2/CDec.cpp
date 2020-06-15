#include "CDec.h"

istream &operator>>(istream &in, CDec &CDec)
{
    in >> CDec.idata;
    return in;
}

ostream &operator<<(ostream &out, const CDec &CDec)
{
    out << dec << CDec.idata;
    return out;
}

void CDec::showbin()
{
    int b[10],i;
    int n = idata;
    for(i = 0; n > 0; i++)    
    {    
        b[i] = n % 2;    
        n= n / 2;  
    }    
    for(i = i - 1 ;i >= 0 ;i--)    
    {    
        cout << b[i];    
    }    
}

void CDec::showoct()
{
    cout << oct << idata;
}

void CDec::showhex()
{
    cout << hex << idata;
}