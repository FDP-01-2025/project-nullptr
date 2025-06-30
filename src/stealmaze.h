#ifndef STEALMAZE_H
#define STEALMAZE_H
#include <iostream>
using namespace std;

void seemaze(char mazebase[20][20]){
        cout << "+";
    for (int i = 0; i < 20; i++)
        cout << "-";
    {
        cout << "+" << endl;
    }
    for (int i = 0; i < 20; i++)
    {
        cout << "|";
        for (int j = 0; j < 20; j++)
        {
         cout << mazebase[i][j];
        }
        cout << "|" << endl;
    }
    cout << "+";
    for (int i = 0; i < 20; i++)
        cout << "-";
    {
        cout << "+" << endl;
    }
}
#endif