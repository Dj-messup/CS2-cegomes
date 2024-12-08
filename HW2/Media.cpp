#include "Media.h"

namespace media {
    Media::Media(int id, const string& title, int year, const string& genre, float rating) {
        this->id = id;
        this->title = title;
        this->year = year;
        this->genre = genre;
        this->rating = rating;
    }
}