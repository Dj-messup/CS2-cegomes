#pragma once
#include "Media.h"
using namespace std;

namespace tvshows {
    class TvShow : public media::Media {
        int seasons;

    public:
        TvShow(int id, const string& title, int year, int seasons);
        int getSeasons() const;
        void showInfo() const override;
    };
}

