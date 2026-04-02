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

Hangman::~Hangman() {
}

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
    for (char c : guessedWord) {
        cout << c << ' ';
    }
    cout << endl;
}

void Hangman::displayGuessedLetters() const {
    cout << "Guessed letters: ";
    for (char c : guessedLetters) {
        cout << c << ' ';
    }
    cout << endl;
}

void Hangman::printHangman() const {
    string color;

    if (wrongGuesses == 0) {
        color = "\033[32m";
    }
    else if (wrongGuesses == 1) {
        color = "\033[92m";
    }
    else if (wrongGuesses == 2) {
        color = "\033[33m";
    }
    else if (wrongGuesses == 3) {
        color = "\033[93m";
    }
    else if (wrongGuesses == 4) {
        color = "\033[91m";
    }
    else {
        color = "\033[31m";
    }

    string stages[7] = {
        "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="
    };

    cout << color << stages[wrongGuesses] << "\033[0m" << endl;
}

void Hangman::play() {
    while (wrongGuesses < maxWrong && guessedWord != secretWord) {
        printHangman();
        displayWord();
        displayGuessedLetters();

        string input;
        cout << "Enter one letter: ";
        getline(cin, input);

        if (input.size() != 1 || !isalpha(input[0])) {
            cout << "Invalid guess. Enter one letter only." << endl;
            continue;
        }

        char guess = tolower(input[0]);

        if (alreadyGuessed(guess)) {
            cout << "You already guessed that letter." << endl;
            continue;
        }

        guessedLetters.push_back(guess);

        if (containsLetter(guess)) {
            updateWord(guess);
            cout << "\033[32mCorrect!\033[0m" << endl;
        }
        else {
            wrongGuesses++;
            cout << "\033[31mIncorrect!\033[0m" << endl;
        }

        cout << endl;
    }

    printHangman();
    displayWord();

    if (guessedWord == secretWord) {
        cout << "\033[32mYou won! The word was " << secretWord << "\033[0m" << endl;
        player.addWin();
    }
    else {
        cout << "\033[31mYou lost! The word was " << secretWord << "\033[0m" << endl;
        player.addLoss();
    }

    cout << "Current Stats:" << endl;
    cout << player << endl;
}

bool Hangman::playerWon() const {
    return guessedWord == secretWord;
}

bool Hangman::playerWon() const {
    return guessedWord == secretWord;
}
