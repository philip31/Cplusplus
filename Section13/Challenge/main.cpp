#include <iostream>
#include "Movies.hpp"

#include <chrono>
using namespace std;



int main(){
    auto begin = std::chrono::high_resolution_clock::now();
    Movies my_movies;
    
    my_movies.display();
    
    my_movies.add_movie("Big", PG_13, 0);       //OK
    my_movies.add_movie("Star Wars", PG, 0);    //OK
    my_movies.add_movie("Cinderella", PG, 0);   //OK

    
    my_movies.add_movie("Cinderella", PG, 0);   //NOT OK
    
    my_movies.watch_movie("Big");               // FOUND
    my_movies.watch_movie("s");                 //NOT FOUND
    
    
    my_movies.display();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    
    cout << "it took " << elapsed.count() << endl;
    
}
