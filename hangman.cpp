/*
    Authors: Madeline Littleton and Kylee Walker
*/

#include <iostream>
#include <cctype>
#include "hangman.h"

using namespace std;

Hangman::Hangman(string word, HumanPlayer& p) : player(p) {
    secretWord = word;
    guessedWord = "";
    wrongGuesses = 0;
    maxWrong = 6;

    for (int i = 0; i < secretWord.size(); i++) {
        secretWord[i] = tolower(secretWord[i]);
        if (secretWord[i] == ' ') guessedWord += ' ';
        else guessedWord += '_';
    }
}

Hangman::~Hangman() {}

bool Hangman::alreadyGuessed(char guess) const {
    for (char c : guessedLetters) {
        if (c == guess) return true;
    }
    return false;
}

bool Hangman::containsLetter(char guess) {
    for (char c : secretWord) {
        if (c == guess) return true;
    }
    return false;
}

void Hangman::updateWord(char guess) {
    for (int i = 0; i < secretWord.size(); i++) {
        if (secretWord[i] == guess) guessedWord[i] = guess;
    }
}

void Hangman::displayWord() const {
    cout << "Word: ";
    for (char c : guessedWord) cout << c << ' ';
    cout << endl;
}

void Hangman::displayGuessedLetters() const {
    cout << "Guessed letters: ";
    for (char c : guessedLetters) cout << c << ' ';
    cout << endl;
}

void Hangman::printHangman() const {
    string stages[7] = {
        "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="
    };
    cout << stages[wrongGuesses] << endl;
}

void Hangman::play() {
    while (wrongGuesses < maxWrong && guessedWord != secretWord) {
        printHangman();
        displayWord();
        displayGuessedLetters();

        string input;
        cout << "Enter one letter: ";
        getline(cin, input);

        if (input.size() != 1 || !isalpha(input[0])) continue;

        char guess = tolower(input[0]);

        if (alreadyGuessed(guess)) continue;

        guessedLetters.push_back(guess);

        if (containsLetter(guess)) updateWord(guess);
        else wrongGuesses++;
    }

    printHangman();
    displayWord();

    if (guessedWord == secretWord) {
        cout << "You won! The word was " << secretWord << endl;
        player.addWin();
    } else {
        cout << "You lost! The word was " << secretWord << endl;
        player.addLoss();
    }

    cout << "Current Stats:" << endl;
    cout << player << endl;
}

bool Hangman::playerWon() const {
    return guessedWord == secretWord;
}
