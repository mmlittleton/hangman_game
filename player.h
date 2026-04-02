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
    virtual ~Player();

    void addWin();
    int getWins() const;
    void addLoss();
    int getLosses() const;
    string getName() const;

    friend ostream& operator<<(ostream& os, const Player& p);
};

class HumanPlayer : public Player {
public:
    HumanPlayer();
    HumanPlayer(string n);
    ~HumanPlayer();
};

#endif
