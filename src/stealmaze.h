#ifndef STEALMAZE_H
#define STEALMAZE_H
#include <iostream>
using namespace std;

void seemaze(char mazebase[20][20], int xcoord, int ycoord)//Show the maze
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
bool playingmaze(char mazebase[20][20], int xcoordi, int ycoordi)//the player move around the maze
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
            cout << "\033[32mI escaped!\033[0m\n";
            return true;
        }

        xcoordi = Xx;
        ycoordi = Yy;
        movescount--;//removes a move per turn
        
    }
    cout << "\033[31mNo more moves. I got caught!\033[0m\n";
    return false;
}

#endif