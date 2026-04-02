/*
    Authors: Madeline Littleton and Kylee Walker
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include "difficulties.h"
#include "hangman.h"
#include "player.h"

using namespace std;

string loadWord(string fileName) {
    ifstream file(fileName);
    if (!file.is_open()) throw runtime_error("File error");

    vector<string> words;
    string line;

    while (getline(file, line)) {
        if (!line.empty()) {
            for (char& c : line) c = tolower(c);
            words.push_back(line);
        }
    }

    if (words.empty()) throw runtime_error("Empty file");

    return words[rand() % words.size()];
}

string easy() { return loadWord("easy.txt"); }
string medium() { return loadWord("medium.txt"); }
string hard() { return loadWord("hard.txt"); }
string extra_hard() { return loadWord("extra_hard.txt"); }

void multiplayer_mode() {
    string setterName, guesserName, word;

    cout << "Setter name: ";
    getline(cin, setterName);

    cout << "Guesser name: ";
    getline(cin, guesserName);

    HumanPlayer setter(setterName);
    HumanPlayer guesser(guesserName);

    cout << setter.getName() << ", enter word: ";
    getline(cin, word);

    for (char& c : word) c = tolower(c);

    for (int i = 0; i < 50; i++) cout << endl;

    Hangman game(word, guesser);
    game.play();

    if (game.playerWon()) setter.addLoss();
    else setter.addWin();

    cout << endl << "Final Session Stats:" << endl;
    cout << guesser << endl;
    cout << setter << endl;
}
