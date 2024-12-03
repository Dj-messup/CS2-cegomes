#include "media.h"

namespace media {
    Media::Media(int id, const std::string& title, int year) : id(id), title(title), year(year) {}

    int Media::getId() const { return id; }
    std::string Media::getTitle() const { return title; }
    int Media::getYear() const { return year; }

    void Media::setId(int id) { this->id = id; }
    void Media::setTitle(const std::string& title) { this->title = title; }
    void Media::setYear(int year) { this->year = year; }
}
