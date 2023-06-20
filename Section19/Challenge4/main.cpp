#include <iostream>
#include <string>
#include <fstream>



using namespace std;

int main(){
    ofstream out_file {"../romeoandjuliet_out.txt"};
    ifstream in_file {"../romeoandjuliet.txt"};
    
    if(!out_file || !in_file)
    {
        cerr << "ERROR" << endl;
        return 1;
    }
    
    int line_nr{0};
    string output{};
    string aux{};
    
    while(!in_file.eof())
    {
        getline(in_file,aux);
        output = to_string(++line_nr);
        output += '\t';
        output += aux;
        out_file << output;
    }
    
    in_file.close();
    out_file.close();
    
    return 0;
}
