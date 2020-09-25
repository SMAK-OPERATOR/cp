#include "Bus.h"

// string getNum(Nbus *m) { return m->num; }

Nbus* Bus::add()
{
    string num;
    string nroad;
    string user;
    adds a;
    cout << "\nEnter the number of the bus \n Input:  ";
    fflush(stdin);
    getline(cin, a.bnum);
    cout << "\nEnter the name of the bus user \n Input:  ";
    fflush(stdin);
    getline(cin, a.buser);
    cout << "\nEnter the route number of bus \n Input:  ";
    fflush(stdin);
    getline(cin, a.bnroad);
    Nbus *elem = new Nbus();
    elem->num = a.bnum;
    elem->nroad = a.bnroad;
    elem->user = a.buser;
    elem->where = false;
    elem->next = nullptr;
    if (Bus::head == NULL)
    {
        head = elem;
        tail = elem;
    }
    else
    {
        tail->next = elem;
        tail = tail->next;
    }
    return elem;
}

Nbus* Bus::getHead() { return head; }

void Bus::printall()
{
    Nbus *pv = head;
    cout << endl;
    while (pv)
    {
        cout << "Num: " << pv->num << " Driver: " << setw(20) << left << pv->user << " NRoad: " << pv->nroad;
        if ((pv->where) == false)
            cout << " On base" << endl;
        else if ((pv->where) == true)
            cout << " On road" << endl;
        pv = pv->next;
    }
}

Nbus* Bus::findnum(string fnum)
{
    Nbus *pv = head;
    while (pv)
    {
        if (fnum == pv->num)
            break;
        else
            pv = pv->next;
    }
    return pv;
}

Nbus* Bus::stchange(Nbus *m)
{

    m->where = !(m->where);
    return m;
}

void Bus::printone(Nbus *m)
{
    Nbus *pv = m;
    cout << "Num: " << pv->num << " Driver: " << setw(20) << left << pv->user << " NRoad: " << pv->nroad;
    if ((pv->where) == false)
        cout << " On base" << endl;
    else if ((pv->where) == true)
        cout << " On road" << endl;
}

void Bus::printon(bool where)
{
    Nbus *pv = head;
    cout << endl;
    int kv = 0, kk = 0;
    while (pv)
    {
        if (pv->where == where)
        {
            cout << "\nNum: " << pv->num << " Driver: " << setw(20) << left << pv->user << " NRoad: " << pv->nroad;
            kv++;
        }
        kk++;
        pv = pv->next;
    }
    if (kk != kv)
        cout << "There are no buses with such parameter" << endl;
}