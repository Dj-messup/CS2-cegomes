#pragma once
#include "Media.h"
#include <string>  
using namespace std;  

namespace tvshows {

    class Tvshow : public media::Media {
    private:
        string genre;       // Genre of the TV show
        double rating;      // Rating of the TV show
        int numEpisodes;    // Number of episodes

    public:
        // Constructor
        Tvshow(int id, string title, int year, string genre, double rating, int numEpisodes);

        // Getter and Setter for genre
        string getGenre() const;
        void setGenre(const string& genre);

        // Getter and Setter for rating
        double getRating() const;
        void setRating(double rating);

        // Getter and Setter for numEpisodes
        int getNumEpisodes() const;
        void setNumEpisodes(int numEpisodes);

        // Overridden function from Media class to display TV show info
        string displayInfo() const;
    };

}
