#ifndef SAVESYSTEM_H
#define SAVESYSTEM_H

#include <iostream>
#include <fstream>

struct saveData {
    int lives;
    int currentStage;
};

inline void saveProgress(const saveData& data) {
    ofstream file("gameSaveFile.txt");
    if (file.is_open()) {
        file << data.lives << endl;
        file << data.currentStage << endl;
        file.close();
    }
}

inline bool loadProgress(saveData& data) {
    ifstream file("gameSaveFile.txt");
    if (file.is_open()) {
        file >> data.lives;
        file >> data.currentStage;
        file.close();
        return true;
    }
    return false;
}

inline void promptToSave(int lives, int stage) {
    char saveOpt;
    cout<<"Do you want to save your progress? [Y/N]: ";
    cin >> saveOpt;
    if (saveOpt == 'Y' || saveOpt == 'y') {
        saveProgress({lives, stage});
        cout << "Progress saved.\n";
    }
}

#endif