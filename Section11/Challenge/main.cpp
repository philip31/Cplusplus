#include <iostream>
#include <vector>
#include <string>

using namespace std;


void display_menu();
char read_selection();
void print_list(vector<int> &);
void add_number(vector<int> &);
void display_mean(const vector<int> &);
void display_smallest(const vector<int> &);
void display_largest(const vector<int> &);
void find_occurences(const vector<int> &);




int main(){
    vector<int> vec {};
    bool quit {false};
    
    do {
        display_menu();

        switch (read_selection()) {
 
            case 'P': {
                print_list(vec);
                break;
            }
            
            case 'A': {
                add_number(vec); 
                break;
            }
 
            case 'M': {
                display_mean(vec);
                break;
            }
 
            case 'S': {
                display_smallest(vec);
                break;
            }
 
            case 'L': {
                display_largest(vec);
                break;
            }
 
            case 'Q': {
                quit = true;
                cout << "Quitting..." << endl;
                break;
            }
 
            case 'F': {
                find_occurences(vec);
                break;
            }
                   
            default : cout << "Unknown selection, please try again" << endl;
        }
        
    } while (!quit);
    
    return 0;
}

void display_menu()
{
    cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display de smallest number" << endl;
        cout << "L - Display de largest number" << endl;
        cout << "F - Find number of occurences" << endl;
        cout << "Q - Quit" << endl << endl;
        cout << "Enter your choice: ";
}

char read_selection()
{
    char choice {};
    string options {"pamslfq"};
    cin >> choice;
    
    if (options.find(choice) != string::npos)
    {
        choice = toupper(choice); 
    }
    
    return choice;
}

void add_number(vector<int> &v)
{
    cout << endl << "Insert an integer: ";
    int num {};
    cin >> num;
    
    bool ok {true};
    for (auto element : v) {
        if (element == num) {
            cout << "Number " << num << " already in list" << endl;
            ok = false;
            break;
        }
    }
    if (ok) {
        v.push_back(num);
        cout << num << " was added" << endl; 
    }
}

void display_mean(const vector<int> &v)
{
    if (v.size()) {
        double mean {0.0};
        for (auto element : v) {
            mean += element;
        }
        mean /= v.size();
        cout << "The mean is: " << mean << endl;
    } else {
        cout << "Unable to calculate the mean - no data" << endl;
    }
}

void display_smallest(const vector<int> &v)
{
    if (v.size()) {
        int smallest {v[0]};
        if (v.size() > 1){
            for (int i {1}; i < v.size(); ++i) {
                if (smallest > v.at(i))
                    smallest = v.at(i);
            }
        }
        cout << "The smallest number is " << smallest << endl;
    } else cout << "Unable to display smallest - no data" << endl;
}

void display_largest(const vector<int> &v)
{
    if (v.size()) {
        int largest {v[0]};
        if (v.size() > 1){
            for (int i {1}; i < v.size(); ++i) {
                if (largest < v.at(i))
                    largest = v.at(i);
            }
        }
        cout << "The largest number is " << largest << endl;
    } else cout << "Unable to display largest - no data" << endl;
}

void find_occurences(const vector<int> &v)
{
    int num {0};
    cout << "Find element: ";
    cin >> num;
    
    int occurence {0};
    for (auto element : v) {
        if (element == num)
            occurence++;
    }
    cout << "The number occured " << occurence << " times" << endl;
}

void print_list(vector<int> &v)
{
    if (v.size()) {
        cout << "[ ";
        for (auto elements : v) {
            cout << elements << " ";
        }
        cout << "]" << endl;
    } else {
        cout << "[] - the list is empty" << endl;
    }
}