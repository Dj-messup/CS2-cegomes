#pragma once
#include "Media.h"
using namespace std;

namespace music {
    class Music : public media::Media {
        string artist;

    public:
        Music(int id, const string& title, int year, const string& artist);
        string getArtist() const;
        void showInfo() const override;
    };
}


