#include <iostream>
#include <vector>
#include <string>
#include "hiddentreasure.h"
bool playhiddentreasure()
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
    cout << "\033[35m" 
     << "                                                                                                                                         \n"
     << "                ,,        ,,        ,,                                          ,,                     ,,                               \n"
     << "`7MMF'  `7MMF'  db      `7MM      `7MM                     `7MM\"\"\"Mq.           db              mm     db                               \n"
     << "  MM      MM              MM        MM                       MM   `MM.                          MM                                      \n"
     << "  MM      MM  `7MM   ,M\"\"bMM   ,M\"\"bMM  .gP\"Ya `7MMpMMMb.    MM   ,M9 ,6\"Yb.  `7MM  `7MMpMMMb.mmMMmm `7MM  `7MMpMMMb.  .P\"Ybmmm ,pP\"Ybd \n"
     << "  MMmmmmmmMM    MM ,AP    MM ,AP    MM ,M'   Yb  MM    MM    MMmmdM9 8)   MM    MM    MM    MM  MM     MM    MM    MM :MI  I8   8I   `\" \n"
     << "  MM      MM    MM 8MI    MM 8MI    MM 8M\"\"\"\"\"\"  MM    MM    MM       ,pm9MM    MM    MM    MM  MM     MM    MM    MM  WmmmP\"   `YMMMa. \n"
     << "  MM      MM    MM `Mb    MM `Mb    MM YM.    ,  MM    MM    MM      8M   MM    MM    MM    MM  MM     MM    MM    MM 8M        L.   I8 \n"
     << ".JMML.  .JMML..JMML.`Wbmd\"MML.`Wbmd\"MML.`Mbmmd'.JMML  JMML..JMML.    `Moo9^Yo..JMML..JMML  JMML.`Mbmo.JMML..JMML  JMML.YMMMMMb  M9mmmP' \n"
     << "                                                                                                                      6'     dP         \n"
     << "                                                                                                                      Ybmmmd'           \n"
     << "\033[0m"; 

    while (Treasurefound < 7 && turn > 0)
    {
        movement(basemap, playermap, turn, Treasurefound);
        playervisionsmap(basemap, playermap);
    }
    if (Treasurefound == 7) // win condition
    {
        cout << "\033[32mI got it, better leave fast\033[0m\n";
        return true;
    }
    else
        cout << "\033[31mI m doomed\033[0m\n";
    return false;
}