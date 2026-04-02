/*
    Authors: Madeline Littleton and Kylee Walker
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "difficulties.h"
#include "hangman.h"
#include "player.h"

using namespace std;

int main()
{
    srand(time(0));

    string m;
    cout << "Welcome to Hangman!" << endl;

    cout << "Single or Multiplayer? ";
    getline(cin, m);

    for (int i = 0; i < m.size(); i++) {
        m[i] = tolower(m[i]);
    }

    if (m == "single") {
        string d;
        HumanPlayer singlePlayer("Player");

        while (d != "exit") {
            cout << endl;
            cout << "Difficulties:" << endl;
            cout << "Easy" << endl;
            cout << "Medium" << endl;
            cout << "Hard" << endl;
            cout << "Extra Hard" << endl;
            cout << "Exit" << endl;

            cout << "What difficulty would you like? ";
            getline(cin, d);

            for (int i = 0; i < d.size(); i++) {
                d[i] = tolower(d[i]);
            }

            try {
                if (d == "easy") {
                    Hangman game(easy(), singlePlayer);
                    game.play();
                }
                else if (d == "medium") {
                    Hangman game(medium(), singlePlayer);
                    game.play();
                }
                else if (d == "hard") {
                    Hangman game(hard(), singlePlayer);
                    game.play();
                }
                else if (d == "extra hard") {
                    Hangman game(extra_hard(), singlePlayer);
                    game.play();
                }
                else if (d != "exit") {
                    cout << "Invalid difficulty. Try again." << endl;
                }
            }
            catch (exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        }

        cout << endl;
        cout << "Final Session Stats:" << endl;
        cout << singlePlayer << endl;
    }
    else if (m == "multiplayer") {
        try {
            multiplayer_mode();
        }
        catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    else {
        cout << "Invalid mode." << endl;
    }

    return 0;
}
