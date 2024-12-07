#include <iostream>
#include "Database.h"
#include "Movie.h"
#include "Music.h"
#include "TVShow.h"

using namespace std;
using namespace movies;

void showMenu() {
    cout << "\n=== Movie Database Menu ===" << endl;
    cout << "1. Add a Movie" << endl;
    cout << "2. Remove a Movie" << endl;
    cout << "3. View All Movies" << endl;
    cout << "4. Save Movies to File" << endl;
    cout << "5. Exit" << endl;
    cout << "Please choose an option (1-5): ";
}

int main() {
    // Initialize database
    Database db("Movie Database", 1);

    // Load existing data from CSV files
    db.loadMoviesFromFile("movies.csv");
    db.loadMusicFromFile("music.csv");
    db.loadTVShowsFromFile("tvshows.csv");

    int choice;
    bool running = true;

    while (running) {
        // Show menu
        showMenu();
        cin >> choice;
        cin.ignore();  // Ignore leftover newline character

        switch (choice) {
            case 1: {
                // Add movie logic
                string imdbId, title, genre;
                int year;
                float rating;

                cout << "Enter IMDB ID: ";
                getline(cin, imdbId);
                cout << "Enter Title: ";
                getline(cin, title);
                cout << "Enter Year: ";
                cin >> year;
                cin.ignore();  // Ignore newline
                cout << "Enter Genre: ";
                getline(cin, genre);
                cout << "Enter Rating (0.0 - 10.0): ";
                cin >> rating;
                cin.ignore();  // Ignore newline

                Movie* newMovie = new Movie(imdbId, title, year, genre, rating);
                db.addMovie(newMovie);
                cout << "Movie added successfully!" << endl;
                break;
            }
            case 2: {
                // Remove movie logic
                string imdbId;
                cout << "Enter IMDB ID of the movie to remove: ";
                getline(cin, imdbId);
                db.removeMovie(imdbId);
                cout << "Movie removed successfully!" << endl;
                break;
            }
            case 3: {
                // View all movies
                db.displayAllMovies();
                break;
            }
            case 4: {
                // Save logic (this happens automatically after adding/removing)
                cout << "Data saved automatically after changes." << endl;
                break;
            }
            case 5: {
                // Exit
                running = false;
                break;
            }
            default:
                cout << "Invalid choice, try again." << endl;
                break;
        }
    }

    return 0;
}
