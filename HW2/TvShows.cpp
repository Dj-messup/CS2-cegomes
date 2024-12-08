#include "TvShows.h"
#include <iostream>
using namespace std;

namespace tvshows 
{
    TvShow::TvShow(int id, string title, int year, string genre, 
                   float rating, int episodes)
        : Media(id, title, year, genre, rating) 
        {
        this->numEpisodes = episodes;
        }

    string TvShow::displayInfo() 
    {
        string info = "TV Show: ";
        info += title;
        info += " (" + to_string(year) + ")";
        info += "\n  Genre: " + genre;
        info += "\n  Rating: " + to_string(rating);
        info += "\n  Episodes: " + to_string(numEpisodes);
        return info;
    }
}