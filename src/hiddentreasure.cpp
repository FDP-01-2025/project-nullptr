#include <iostream>
#include <vector>
#include <string>
#include "hiddentreasure.h"
int main()
{
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
playermap[0][1]=true;
playermap[0][3]=true;
playermap[4][5]=true;
playervisionsmap(basemap, playermap);
return 0;


}