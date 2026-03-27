#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

class Player {
private:
    string name;
    int wins;
    int losses;

public:
    Player();
    Player(string n);
    ~Player();

    void addWin();
    int getWins() const;
    void addLoss();
    int getLosses() const;

    friend ostream& operator<<(ostream& os, const Player& p);
};

#endif
