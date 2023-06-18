// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void print (string student, string score)
{
    cout << setw(15) << left << student << setw(5) << right << score << endl;
}

void print (string student, double score)
{
    cout << setw(15) << left << student << setw(5) << right << score << endl;
}

void print_line()
{
    cout << setw(20) << setfill('-') << "" << endl << setfill(' ');
}

int main() {
    
    
    ifstream in_file {"../responses.txt"};
    
    if (!in_file)
    {
        cerr << "Could not find file" << endl;
        return 1;
    }
    
    string correct_responses {};
    in_file >> correct_responses;
    
    string kid_name{};
    string kid_responses{};
    int score {0};
    int nr_kids {0};
    double average {0.0};
   
    
    print("Student", "Score");
    print_line();
    
    
    while(!in_file.eof())
    {
        in_file >> kid_name >> kid_responses;
        for (int i {0}; i < correct_responses.size(); ++i)
        {
           correct_responses.at(i) == kid_responses.at(i)? ++score : 0;
        }
        print(kid_name, score);
        nr_kids++;
        average += score;
        score = 0;
    }
    
    print_line();
    average /= nr_kids;
    print("Average score", average); 
    return 0;
}

