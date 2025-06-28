#ifndef HIDDENTREASURE_H
#define HIDDENTREASURE_H
using namespace std;
void playervisionsmap(char basemap[8][10], bool playermap[8][10])
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
void movement(
    char basemap[8][10],
    bool playermap[8][10],
    int &turn,
    int &Treasurefound)

    {
        cout << "Where should I go.\n";
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