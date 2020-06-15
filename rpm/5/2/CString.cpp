#include "CString.h"

ostream &operator<<(ostream &out, const CString &CString)
{
    out << CString.data;
    return out;
}

istream &operator>>(istream &in, CString &CString)
{
    in >> CString.data;
    return in;
}

void CString::showbin()
{
    for (char a : this->data)
    {
        int b[10],i;
        int n = (static_cast<int>(a));
        for(i = 0; n > 0; i++)    
        {    
            b[i] = n % 2;    
            n= n / 2;  
        }    
        for(i = i - 1 ;i >= 0 ;i--)    
        {    
            cout << b[i];    
        }    
        cout << ' ';
    }
}

void CString::showoct()
{
    for (char a : this->data)
        cout << oct << static_cast<int>(a) << ' ';
}

void CString::showhex()
{
    for (char a : this->data)
        cout << hex << static_cast<int>(a) << ' ';
}

