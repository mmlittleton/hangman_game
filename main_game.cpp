/*
    Authors: Madeline Littleton and Kylee Walker
*/

#include <iostream>
#include <string>
#include <cctype>
#include <difficulties.h>
using namespace std;

int main()
{
    string m;
    cout << "Welcome to Hangman!" << endl;
    
    cout << "Single or Multiplayer? ";
    getline(cin, m);
    
    for(int i = 0; i < m.size(); i++) {
        m[i] = tolower(m[i]);
    }
    
    if (m == "single") {
        string d;
        while(d != "exit") {
            cout << "Difficulties:" << endl;
            cout << "Easy" << endl;
            cout << "Medium" << endl;
            cout << "Hard" << endl;
            cout << "Extra Hard" << endl;
            cout << "Exit" << endl;
    
            cout << "What difficulty would you like? ";
            getline(cin, d);
        
            for(int i = 0; i < d.size(); i++) {
                d[i] = tolower(d[i]);
            }
    
            if(d == "easy") {
                easy();
            }
            else if(d == "medium") {
                medium();
            }
            else if(d == "hard") {
                hard();
            }
            else if(d == "extra hard") {
                extra_hard();
            }
            else if(d != "exit") {
                cout << "Invalid difficulty. Try again." << endl;
            }
        }
    }
    else if (m == "multiplayer") {
        multiplayer_mode();
    }
    else {
        cout << "Invalid mode." << endl;
    }
    return 0;
}
