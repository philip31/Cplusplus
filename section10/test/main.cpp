#include <iostream>
#include <string>

using namespace std;

int main(){

    string inserted_string {};
    
    cout << "Insert a string: ";
    cin >> inserted_string;
    cout << endl;
   
    size_t piramid_base_length = inserted_string.length() * 2 - 1;

    string string_to_print {};
    int contor {0};
    
    while (string_to_print.length() < piramid_base_length)
    {
        string_to_print.clear();
        
        bool string_ready {false};
        bool go_reverse {false};
        int i {0};
        
        while (!string_ready)
        {
            if (contor == i)
            {
                go_reverse = true;
            }
            
            if (go_reverse)
            {
                string_to_print += inserted_string.at(i--);
            } 
            else
            {
                string_to_print += inserted_string.at(i++);
            }
               
            if (i == -1)
                string_ready = true;
        }

        int n {piramid_base_length - string_to_print.length()}; 

        string spaces {};
        
        for (size_t j = 0; j < n/2; ++j)
            spaces += " ";

            
        cout << spaces << string_to_print << spaces << endl;
        contor++;
    }

    return 0;
}
