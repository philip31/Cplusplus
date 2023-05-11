#include "Movies.hpp"

Movies::Movies()
{
}

Movies::Movies(Movies &source)
{
    for (Movie &m : source.list_movies)
    {
        this->add_movie(m.get_name(), m.get_rating(), m.get_watched());
    }
    cout << "Movies copied" << endl;
}


Movies::Movies(Movies &&source)
{
    
    for (Movie &m : source.list_movies)
    {
        this->add_movie(m.get_name(), m.get_rating(), m.get_watched());

    }
    cout << "Movies moved" << endl;
}



Movies::~Movies()
{
}

void Movies::add_movie(string name, Rating rating, int watched)
{

    for (const Movie &m : list_movies) // use a reference instead of a copy
    {
        if (m.get_name() ==  name)
        {
            cout << "Movie " << name << " exists already" << endl;
            return;
        }
    }
    
    list_movies.push_back(Movie(name, rating, watched));
    cout << "Movie " << name << " has been created"<< endl;
}

void Movies::watch_movie(string name)
{
    for (Movie &m : list_movies) // use a reference instead of a copy
    {
        if (m.get_name() ==  name)
        {

            m.watch_movie();
            cout << "Movie's " << name << " watchcount has been incremented to " << m.get_watched() << " times" << endl;
            return;
        }
    }
    
    cout << "There is no movie with name " << name << endl;
}
    
void Movies::display() const
{
    cout << "[ ";
    
    if (list_movies.size() > 0)
        for (const Movie &m : list_movies) // use a reference instead of a copy
        {
            cout << "\"" << m.get_name() << "\" ";

        }
     
    cout << "]" << endl;
}