#pragma once
#include "Nbus.h"

struct adds
{
    string bnum;
    string bnroad;
    string buser;
};

class Bus
{
    Nbus *head, *tail;

public:
    Bus()
    {
        head = NULL;
        tail = NULL;
    }
    Nbus *add();
    Nbus *getHead();
    void printall();
    Nbus *findnum(string fnum);
    Nbus *stchange(Nbus *m);
    void printone(Nbus *m);
    void printon(bool where);
};