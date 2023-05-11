#include "Movie.hpp"


Movie::Movie(string name, Rating rating, int watched)
    :  name{name},  rating{rating}, watched{watched}
{
}


Movie::~Movie()
{
}

void Movie::watch_movie()
{
    watched ++;
}

