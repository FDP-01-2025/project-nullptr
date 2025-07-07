#ifndef INTROMENU_H
#define INTROMENU_H
#include <iostream>
#include "logo.h"
using namespace std;
bool intromenu()
{
    int start;
    showlogo();
    cout << "Welcome to Three Steal\n";
    cout << "Press any number from 1-9 to start\n";
    cout << "Press 0 to endgame\n";
    cin >> start;
    if (start == 0)
    {
        return false;
    }
    else
    return true;
}

#endif