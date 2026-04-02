/*
    Authors: Madeline Littleton and Kylee Walker
*/

#include "player.h"

using namespace std;

Player::Player() {
    name = "Player";
    wins = 0;
    losses = 0;
}

Player::Player(string n) {
    name = n;
    wins = 0;
    losses = 0;
}

Player::~Player() {
}

void Player::addWin() {
    wins++;
}

int Player::getWins() const {
    return wins;
}

void Player::addLoss() {
    losses++;
}

int Player::getLosses() const {
    return losses;
}

string Player::getName() const {
    return name;
}

ostream& operator<<(ostream& os, const Player& p) {
    os << p.name << " | "
       << "\033[32mWins: " << p.wins << "\033[0m"
       << " | "
       << "\033[31mLosses: " << p.losses << "\033[0m";
    return os;
}

HumanPlayer::HumanPlayer() : Player("Player") {
}

HumanPlayer::HumanPlayer(string n) : Player(n) {
}

HumanPlayer::~HumanPlayer() {
}
