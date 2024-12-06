#ifndef MEDIA_H
#define MEDIA_H

#include <string>

namespace media {
    class Media {
    protected:
        int id;
        std::string title;
        int year;

    public:
        Media(int id, std::string title, int year)
            : id(id), title(title), year(year) {}

        virtual ~Media() {}

        virtual std::string displayInfo() const = 0; // Pure virtual function
        // Getters and setters for the attributes
        int getId() const { return id; }
        std::string getTitle() const { return title; }
        int getYear() const { return year; }
    };
}

#endif // MEDIA_H
