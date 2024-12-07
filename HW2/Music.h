#pragma once

#include "Media.h"
#include <string>

using namespace std;

namespace music {

    class Music : public media::Media {
    private:
        string composer;      // Composer of the music
        string genre;         // Genre of the music
        int numTracks;        // Number of tracks in the album
        double totalPlaytime; // Total playtime of the album in minutes

    public:
        // Constructor
        Music(int id, string title, int year, string composer, string genre, int numTracks, double totalPlaytime);

        // Getters and Setters
        string getComposer() const;
        void setComposer(const string& composer);

        string getGenre() const;
        void setGenre(const string& genre);

        int getNumTracks() const;
        void setNumTracks(int numTracks);

        double getTotalPlaytime() const;
        void setTotalPlaytime(double totalPlaytime);

        // displayInfo (overridden from Media class)
        string displayInfo() const;
    };

}

