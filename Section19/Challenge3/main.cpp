// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    ifstream in_file {"../romeoandjuliet.txt"};
    
    if(!in_file)
    {
        cerr << "No file found" << endl;
        return 1;
    }
    
    cout << "enter a word : ";
    string word{};
    cin >> word;
    string current_word{};
    int occurences {0};
    while (!in_file.eof())
    {
        in_file >> current_word;
        current_word.find(word) != string::npos? occurences++:0;
    }

    in_file.close();
    cout << "Number of occurences for word "<< word <<" : " << occurences << endl;
    
    cout << endl;
    return 0;
}

