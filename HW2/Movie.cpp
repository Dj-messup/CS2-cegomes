#include "Movie.h"
#include <iostream>
using namespace std;

namespace movies {
    Movie::Movie(int id, string title, int year, string genre, float rating, string director)
        : Media(id, title, year, genre, rating) {
        this->director = director;
    }

    string Movie::displayInfo() 
    {
    string output = title;
    output += " (";
    output += to_string(year);
    output += ") - ";
    output += genre;
    output += " - Directed by: ";
    output += director;
    output += " - Rating: ";
    output += to_string(rating);
    return output;
    }
}
