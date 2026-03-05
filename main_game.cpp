/*
    Authors: Madeline Littleton and Kylee Walker
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string d;
    cout << "Welcome to Hangman!" << endl;
    while(d != exit) {
        cout << "Difficulties:" << endl;
        cout << "Easy" << endl;
        cout << "Medium" << endl;
        cout << "Hard" << endl;
        cout << "Extra Hard" << endl;
        cout << "Exit" << endl;
    
        cout << "What difficulty would you like? ";
        getline(cin, d);
    }
    return 0;
}
