#include "Media.h"
#include <iostream>
using namespace std;

namespace media {
    Media::Media(int id, const string& title, int year) : id(id), title(title), year(year) {}

    int Media::getId() const { return id; }
    string Media::getTitle() const { return title; }
    int Media::getYear() const { return year; }
}

