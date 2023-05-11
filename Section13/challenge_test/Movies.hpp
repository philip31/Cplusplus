#ifndef MOVIES_HPP
#define MOVIES_HPP

#include "Movie.hpp"
#include <vector>


using namespace std;

class Movies
{
public:
    vector<Movie> list_movies;
    
public:

    Movies();
    Movies(Movies &);
    Movies(Movies &&);
    
    void add_movie(string, Rating, int);
    void watch_movie(string);
    void display() const;
    
    
    ~Movies();

};

#endif // MOVIES_HPP
