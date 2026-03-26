#include "player.h"

using namespace std;

Player::Player() {
    name = "Player";
    wins = 0;
}

Player::Player(string n) {
    name = n;
    wins = 0;
}

Player::~Player() {
}

void Player::addWin() {
    wins++;
}

int Player::getWins() const {
    return wins;
}

ostream& operator<<(ostream& os, const Player& p) {
    os << p.name << " wins: " << p.wins;
    return os;
}
