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
    string d;
    string m;
    cout << "Welcome to Hangman!" << endl;
    
    cout << "Would you like to do Single or Multiplayer? ";
    getline(cin, m);
    
    for(int i = 0; i < m.size(); i++) {
        m[i] = tolower(m[i]);
    }
    
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
            easyMode();
        }
        else if(d == "medium") {
            mediumMode();
        }
        else if(d == "hard") {
            hardMode();
        }
        else if(d == "extra hard") {
            extraHardMode();
        }
        else if(d != "exit") {
            cout << "Invalid difficulty. Try again." << endl;
        }
        
    }
    return 0;
}
