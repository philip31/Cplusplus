#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector<int> vector1;
    vector<int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);
    
    cout << "elements in vector1 \n"<< "first element: " << vector1.at(0) << "\nsecond element: " << vector1.at(1) << endl;
    cout << "size of vector1: " << vector1.size() << endl;
    cout << endl;

    vector2.push_back(100);
    vector2.push_back(200);
    
    cout << "elements in vector2 \n"<< "first element: " << vector2.at(0) << "\nsecond element: " << vector2.at(1) << endl;
    cout << "size of vector1: " << vector2.size() << endl;
    cout << endl;
    
    vector<vector<int>> vector_2d;
    
    // when you add a vector to another, you make a copy of it in memory, this is why vector1.at(0) = 1000; does not change the value whithin vector_2d
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    
    cout << "elements in vector_2d \n"<< "first element from vector1: " << vector_2d.at(0).at(0) << "\nsecond element: " << vector_2d.at(0).at(1) << endl;
    cout << "first element from vector2: " << vector_2d.at(1).at(0) << "\nsecond element: " << vector_2d.at(1).at(1) << endl;
    cout << endl;
    
    vector1.at(0) = 1000;
    
    cout << "elements in vector_2d after modifs \n"<< "first element from vector1: " << vector_2d.at(0).at(0) << "\nsecond element: " << vector_2d.at(0).at(1) << endl;
    cout << "first element from vector2: " << vector_2d.at(1).at(0) << "\nsecond element: " << vector_2d.at(1).at(1) << endl;
    cout << endl;
    
    cout << "elements in vector1 \n"<< "first element: " << vector1.at(0) << "\nsecond element: " << vector1.at(1) << endl;
    cout << endl;
}
