#include <iostream>

using namespace std;

int main(){
    const int priceSmallRoom {25};
    const int priceLargeRoom {35};
    const float taxRate {0.06};
    const int daysValid {30};

    cout << "How many small rooms would you like cleaned? ";

    int nrSmallRooms {1};
    
    cin >> nrSmallRooms;
    cout << "\nHow many large rooms would you like cleaned? ";

    int nrLargeRooms {1};
    cin >> nrLargeRooms;

    cout << "\nNumber of small rooms: " << nrSmallRooms;
    cout << "\nNumber of large rooms: " << nrLargeRooms;
    cout << "\nPrice per small room: $ " << priceSmallRoom;
    cout << "\nPrice per large room: $ " << priceLargeRoom;

    int cost = nrSmallRooms * priceSmallRoom + nrLargeRooms * priceLargeRoom;
    cout << "\nCost: $" << cost;

    float taxAmount =  cost * taxRate;
    cout << "\nTax: $" << taxAmount;

    cout << "\n================================================";

    cout << "\nTotal estimate: $" << cost + taxAmount;
    cout << "\nThis estimate is valid for " << daysValid << " days\n";
}
