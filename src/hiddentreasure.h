#ifndef HIDDENTREASURE_H
#define HIDDENTREASURE_H
using namespace std;
void playervisionsmap(char basemap[8][10], bool playermap[8][10])
{
    cout << "   ";
    for (int col = 0; col < 10; col++) {
        cout << col << " ";
    }
    cout << endl;

    for (int i = 0; i < 8; i++) {
        cout << i << "  "; 
        for (int j = 0; j < 10; j++) {
            if (playermap[i][j]) {
                cout << basemap[i][j] << " ";
            } else {
                cout << "? ";
            }
        }
        cout << endl;
    }
}
#endif