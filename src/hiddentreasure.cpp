#include <iostream>
#include <vector>
#include <string>
#include "hiddentreasure.h"
int main()
{
    int Treasurefound = 0, turn = 35;
    bool playermap[8][10] = {false}; //
    char basemap[8][10] = {
        {' ', ' ', ' ', ' ', '-', ' ', '-', ' ', '*', '-'},
        {' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' '},
        {' ', '-', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-'},
        {' ', ' ', '*', ' ', ' ', ' ', '-', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' '},
        {'*', ' ', ' ', ' ', '-', ' ', ' ', ' ', ' ', ' '}}; // Map of the hiddentreasure minigame blank space=nothing *=treasure and -=trap
while (Treasurefound <= 7 && turn > 0)
{
movement(basemap, playermap, turn, Treasurefound);
playervisionsmap(basemap, playermap);}
if (Treasurefound==7)
{
    cout << "I got it, better leave fast\n";
}
else 
cout << "I m doomed\n";
    return 0;
}