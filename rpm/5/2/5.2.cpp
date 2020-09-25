#include "CString.h"
#include "CDec.h"

int main()
{
    CString a;
    cout << "Enter a word\nInput: ";
    cin >> a;
    cout << "\nString in hex: ";
    a.showhex();
    cout << "\nString in oct: ";
    a.showoct();
    cout << "\nString in bin: ";
    a.showbin();
    CDec b;
    cout << "\nEnter a number\nInput: ";
    cin >> b;
    cout << "\nNumber in hex: ";
    b.showhex();
    cout << "\nNumber in oct: ";
    b.showoct();
    cout << "\nNumber in bin: ";
    b.showbin();
    cout << endl;
    system("pause");
}