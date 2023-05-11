#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>
#include <iostream>

using namespace std;

enum Rating{
    G, PG, PG_13, R
};

class Movie
{
private:
    string name;
    Rating rating;
    int watched;
    
public:
    Movie(string, Rating, int);
    Movie(Movie &);
    
    int get_watched() const { return watched; };
    string get_name() const { return name; };
    Rating get_rating() const { return rating; };
    void watch_movie();
    
    
    
    ~Movie();

};

#endif // MOVIE_HPP
