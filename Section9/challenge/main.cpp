#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vec {};
    bool quit {false};
    
    do {
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display de smallest number" << endl;
        cout << "L - Display de largest number" << endl;
        cout << "F - Find number of occurences" << endl;
        cout << "Q - Quit" << endl << endl;
        cout << "Enter your choice: ";
        
        char choice {0};
        cin >> choice;
        switch (choice) {
            case 'p':
            case 'P': 
                if (vec.size()) {
                    cout << "[ ";
                    for (auto elements : vec) {
                        cout << elements << " ";
                    }
                    cout << "]" << endl;
                } else {
                    cout << "[] - the list is empty" << endl;
                }
                break;
            
            case 'a':
            case 'A': {
                cout << endl << "Insert an integer: ";
                int inserted_integer {};
                cin >> inserted_integer;
                bool ok {true};
                for (auto element : vec) {
                    if (element == inserted_integer) {
                        cout << "Number " << inserted_integer << " already in list" << endl;
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    vec.push_back(inserted_integer);
                    cout << inserted_integer << " was added" << endl; 
                }
                break;
            }
            case 'm':
            case 'M': {
                if (vec.size()) {
                    double mean {0.0};
                    for (auto element : vec) {
                        mean += element;
                    }
                    mean /= vec.size();
                    cout << "The mean is: " << mean << endl;
                } else {
                    cout << "Unable to calculate the mean - no data" << endl;
                }
                break;
            }
            case 's':
            case 'S': {
                if (vec.size()) {
                    int smallest {vec[0]};
                    if (vec.size() > 1){
                        for (int i {1}; i < vec.size(); ++i) {
                            if (smallest > vec.at(i))
                                smallest = vec.at(i);
                        }
                    }
                    cout << "The smallest number is " << smallest << endl;
                } else cout << "Unable to display smallest - no data" << endl;
                break;
            }
            case 'l':
            case 'L': {
                if (vec.size()) {
                    int largest {vec[0]};
                    if (vec.size() > 1){
                        for (int i {1}; i < vec.size(); ++i) {
                            if (largest < vec.at(i))
                                largest = vec.at(i);
                        }
                    }
                    cout << "The largest number is " << largest << endl;
                } else cout << "Unable to display largest - no data" << endl;
                break;
                break;
            }
            case 'q':
            case 'Q': {
                quit = true;
                cout << "Quitting..." << endl;
                break;
            }
            case 'f':
            case 'F': {
                int find_element {0};
                cout << "Find element: ";
                cin >> find_element;
                int occurence {0};
                for (auto element : vec) {
                    if (element == find_element)
                        occurence++;
                }
                cout << "The number occured " << occurence << " times" << endl;
            }
                
                
            default : cout << "Unknown selection, please try again" << endl;
        }
  
    } while (!quit);
    
    return 0;
}
