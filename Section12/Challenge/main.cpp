#include <iostream>
using namespace std;


int *apply_all(const int * const , const int, const int * const , const int);

void print(const int * const, const int);

int main(){
    int array1[] {1, 2, 3, 4, 5};
    int array2[] {10, 20, 30};
    
    cout << "\nArray 1: ";
    print(array1,5);
    
    cout << "\nArray 2: ";
    print(array2,3);
    
    int *results = apply_all(array1, 5, array2, 3);
    cout << "\nResult: ";
    print(results, 15);
    
    delete [] results;
    return 0;
}

int *apply_all(const int * const arr1, const int size1, const int * const arr2,const int size2)
{
    int *new_array = new int[size1 * size2];
    int contor{0};
    
    for (int i{0}; i < size2; ++i)
    {
        for(int j{0}; j < size1; ++j)
        {
            new_array[contor] = arr1[j] * arr2[i];
            contor++;
        }
    }
    return new_array;
}

void print(const int * const arr, const int size)
{
    cout << "\n[ ";
    for(int i{0}; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}
