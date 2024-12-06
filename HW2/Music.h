#pragma once

#include "Media.h"

namespace music {

    class Music : public media::Media {
    private:
        std::string composer;
        std::string genre;
        int numTracks;
        double totalPlaytime;

    public:
        // Constructor
        Music(int id, std::string title, int year, std::string composer, std::string genre, int numTracks, double totalPlaytime);

        // Getters and Setters
        std::string getComposer() const;
        void setComposer(const std::string& composer);

        std::string getGenre() const;
        void setGenre(const std::string& genre);

        int getNumTracks() const;
        void setNumTracks(int numTracks);

        double getTotalPlaytime() const;
        void setTotalPlaytime(double totalPlaytime);

        // displayInfo (overridden from Media class)
        std::string displayInfo() const;
    };

}
