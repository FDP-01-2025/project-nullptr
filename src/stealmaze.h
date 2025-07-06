#ifndef STEALMAZE_H
#define STEALMAZE_H
#include <iostream>
using namespace std;

void seemaze(char mazebase[20][20], int xcoord, int ycoord)
{
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
            if (i == ycoord && j == xcoord)
            {
                cout << 'P';
            }
            else
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
bool playingmaze(char mazebase[20][20], int xcoordi, int ycoordi)
{
    int movescount=80;
    char movement;
    while (movescount>0)
    {
        seemaze(mazebase, xcoordi, ycoordi);
        cin >> movement;
        int Xx = xcoordi, Yy = ycoordi;
        if (movement == 'W' || movement == 'w')
            Yy--;
        else if (movement == 'S' || movement == 's')
            Yy++;
        else if (movement == 'A' || movement == 'a')
            Xx--;
        else if (movement == 'D' || movement == 'd')
            Xx++;

        if (Xx < 0 || Xx >= 20 || Yy < 0 || Yy >= 20)
        {
            cout << "I cant escape in that way!\n";
            continue;
        }
        if (mazebase[Yy][Xx] == '#')
        {
            cout << "Thats a wall!\n";
            continue;
        }

        if (mazebase[Yy][Xx] == 'W')
        {
            cout << "I escaped!\n";
            return true;
        }

        xcoordi = Xx;
        ycoordi = Yy;
        movescount--;
        
    }
    cout << "No more moves. I got caught!\n";
    return false;
}

#endif