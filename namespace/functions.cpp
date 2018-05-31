#include <iostream>
#include "header.h"
using std::cout;
using std::endl;


void BestComImpl::SimpleFunc ()
{
    cout << "BestCom's function" << endl;
    PrettyFunc();

    ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc ()
{
    cout << "Ohhhh so pretty :DDDD" << endl;
}

void ProgComImpl::SimpleFunc ()
{
    cout << "ProgCom's function" << endl;
}
