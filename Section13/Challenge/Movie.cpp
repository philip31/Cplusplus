#include "Movie.hpp"


Movie::Movie(string name, Rating rating, int watched)
    :  name{name},  rating{rating}, watched{watched}
{
}

Movie::Movie(Movie &source)
    :Movie(source.get_name(), source.get_rating(), source.get_watched())
{
    cout << "copy created of " << source.get_name() << endl;
}

Movie::~Movie()
{
}

void Movie::watch_movie()
{
    watched ++;
}

