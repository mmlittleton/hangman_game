#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
string word
string extra_hard(){
  srand(time(0));
    std::ifstream file("extra_hard.txt");
    std::string line;
    int targetLine = rand() % 6) + 1; // The specific line you want to read
    int currentLine = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            currentLine++;
            word=line;
        }
        file.close();
    }
}
string hard(){
  srand(time(0));
    std::ifstream file("hard.txt");
    std::string line;
    int targetLine = rand() % 6) + 1; // The specific line you want to read
    int currentLine = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            currentLine++;
            word=line;
        }
        file.close();
    }
}
string medium(){
    srand(time(0));
    std::ifstream file("medium.txt");
    std::string line;
    int targetLine = rand() % 6) + 1; // The specific line you want to read
    int currentLine = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            currentLine++;
            word=line;
        }
        file.close();
    }
}
string easy(){
    srand(time(0));
    std::ifstream file("easy.txt");
    std::string line;
    int targetLine = rand() % 6) + 1; // The specific line you want to read
    int currentLine = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            currentLine++;
            word=line;
        }
        file.close();
    };
}
