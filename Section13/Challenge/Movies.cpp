#include "Movies.hpp"

Movies::Movies()
{
}

Movies::~Movies()
{
}

void Movies::add_movie(string name, Rating rating, int watched)
{

    for (const Movie *m : list_movies) // use a reference instead of a copy
    {
        if (m->get_name() ==  name)
        {
            cout << "Movie " << name << " exists already" << endl;
            return;
        }
    }
    
    Movie *temp = new Movie(name, rating, watched);
    list_movies.push_back(temp);
    cout << "Movie " << name << " has been created"<< endl;
}

void Movies::watch_movie(string name)
{
    for (Movie *m : list_movies) // use a reference instead of a copy
    {
        if (m->get_name() ==  name)
        {

            m->watch_movie();
            cout << "Movie's " << name << " watchcount has been incremented to " << m->get_watched() << " times" << endl;
            return;
        }
    }
    
    cout << "There is no movie with name " << name << endl;
}
    
void Movies::display() const
{
    cout << "[ ";
    
    if (list_movies.size() > 0)
        for (const Movie *m : list_movies) // use a reference instead of a copy
        {
            cout << "\"" << m->get_name() << "\" ";

        }
     
    cout << "]" << endl;
}