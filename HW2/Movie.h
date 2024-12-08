#pragma once
#include "Media.h"
using namespace std;

namespace movies {
    class Movie : public media::Media {
        string director;

    public:
        Movie(int id, const string& title, int year, const string& director);
        string getDirector() const;
        void showInfo() const override;
    };
}
