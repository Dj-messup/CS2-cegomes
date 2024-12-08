#pragma once
#include <string>
using namespace std;

namespace media {
    class Media {
    protected:
        int id;
        string title;
        int year;
        string genre;
        float rating;

    public:
        Media(int id, const string& title, int year, const string& genre, float rating);
        
        int getId() { return id; }
        string getTitle() { return title; }
        int getYear() { return year; }
        string getGenre() { return genre; }
        float getRating() { return rating; }
        
        virtual string displayInfo() = 0;  // Pure virtual function
    };
}

