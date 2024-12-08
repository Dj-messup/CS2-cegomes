#pragma once
#include <string>
using namespace std;

namespace media {
    class Media {
    protected:
        int id;
        string title;
        int year;

    public:
        Media(int id, const string& title, int year);
        virtual ~Media() = default;

        int getId() const;
        string getTitle() const;
        int getYear() const;
        virtual void showInfo() const = 0;
    };
}

