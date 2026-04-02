#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>
#include "player.h"

using namespace std;

class Hangman {
private:
    string secretWord;
    string guessedWord;
    vector<char> guessedLetters;
    int wrongGuesses;
    int maxWrong;
    HumanPlayer& player;

    bool alreadyGuessed(char guess) const;
    bool containsLetter(char guess);
    void updateWord(char guess);
    void displayWord() const;
    void displayGuessedLetters() const;
    void printHangman() const;

public:
    Hangman(string word, HumanPlayer& p);
    ~Hangman();

    void play();
    bool playerWon() const;
};

#endif
