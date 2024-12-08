#include "Movie.h"

namespace movies 
{
    Movie::Movie(int id, string title, int year, string genre, float rating, string director) 
        : Media(id, title, year, genre, rating) 
    {
        this->director = director;
    }

    string Movie::displayInfo() 
    {
        return "ID: " + to_string(id) + " - " + title + " (" + 
               to_string(year) + ") - " + genre + " - Rating: " + 
               to_string(rating) + " - Director: " + director;
    }
}
