#ifndef HIDDENTREASURE_H
#define HIDDENTREASURE_H
using namespace std;
void playervisionsmap(char basemap[8][10], bool playermap[8][10])//show the map that the player is discovering
{
    cout << "   ";
    for (int col = 0; col < 10; col++)
    {
        cout << col << " ";
    }
    cout << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << i << "  ";
        for (int j = 0; j < 10; j++)
        {
            if (playermap[i][j])
            {
                cout << basemap[i][j] << " ";
            }
            else
            {
                cout << "? ";
            }
        }
        cout << endl;
    }
}
void guidesystem(char basemap[8][10], int row, int column) //the system guides the player to know what could be nearby
{
    bool treasurenearby = false;
    bool trapnearby = false;
    if (row > 0)
    {
        if (basemap[row - 1][column] =='*')
        {
            treasurenearby = true;
        }
        if (basemap[row - 1][column] == '-')
        {
            trapnearby = true;
        }
    }
    if (row < 7)
    {
        if (basemap[row + 1][column] == '*')
        {
            treasurenearby = true;
        }
        if (basemap[row + 1][column] == '-')
        {
            trapnearby = true;
        }
    }
    if (column > 0)
    {
        if (basemap[row][column - 1] == '*')
        {
            treasurenearby = true;
        }
        if (basemap[row][column - 1] == '-')
        {
            trapnearby = true;
        }
    }
    if (column < 9)
    {
        if (basemap[row][column + 1] == '*')
        {
            treasurenearby = true;
        }
        if (basemap[row][column + 1] == '-')
        {
            trapnearby = true;
        }
    }

    if (treasurenearby)
    {
        cout << "I got a good feelin, a very well prized painting is nearby.\n";
    }
    if (trapnearby)
    {
        cout << "Something bad might happen in this zone.\n";
    }
}
void movement( //the palyer enters the space he wants to reveal
    char basemap[8][10],
    bool playermap[8][10],
    int &turn,
    int &Treasurefound)

{
    cout << "Where should I go? (enter two number for coordinates y=0-7, x=0-9)\n";
    int row, column;
    cin >> row >> column;
    if (row >= 0 && row < 8 && column >= 0 && column < 10)
    {
        if (!playermap[row][column])
        {
            playermap[row][column] = true;
            if (basemap[row][column] == '*')
            {
                cout << "I better steal this painting.\n";
                Treasurefound = Treasurefound + 1;
                turn = turn - 1;
                cout << "I got " << Treasurefound << " of the 7 painting I need\n";
                cout << "I have " << turn << " left before the alarm detects me\n";
            }
            else if (basemap[row][column] == '-')
            {
                cout << "Oh no, this was a fake.\n";
                turn = turn - 3;
                cout << "I have " << turn << " left before the alarm detects me\n";
            }
            else
            {
                cout << "Nothing here, better keep searching\n";
                turn = turn - 1;
                cout << "I have " << turn << " left before the alarm detects me\n";
                guidesystem(basemap, row, column);
            }
        }

        else
        {
            cout << "I ve already searched here\n";
        }
    }
    else
    {
        cout << "I can search in that way, i need trie with some coordinate of the map\n";
    }
}


#endif