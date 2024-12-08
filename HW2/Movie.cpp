#include "Movie.h"
#include <iostream>
using namespace std;

namespace movies {
    Movie::Movie(int id, const string& title, int year, const string& director)
        : Media(id, title, year), director(director) {}

    string Movie::getDirector() const { return director; }

    void Movie::showInfo() const {
        cout << "Movie: " << title << " (" << year << "), Directed by: " << director << endl;
    }
}
