#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <iostream>

namespace media 
{
    class Media 
    {
    protected:
        int id;
        std::string title;
        int year;

    public:
        // Constructor
        Media(int id, const std::string& title, int year);

        // Virtual destructor to allow proper cleanup
        virtual ~Media() {}

        // Getters and Setters
        int getId() const;
        std::string getTitle() const;
        int getYear() const;

        void setId(int id);
        void setTitle(const std::string& title);
    }
}
