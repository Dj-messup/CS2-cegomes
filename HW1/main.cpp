#include "database.h"
#include "movie.h"
#include <iostream>

using namespace movies;

void showMenu() {
    std::cout << "1. Add Movie" << std::endl;
    std::cout << "2. Remove Movie" << std::endl;
    std::cout << "3. Display All Movies" << std::endl;
    std::cout << "4. Search Movie by Title" << std::endl;
    std::cout << "5. Search Movie by Genre" << std::endl;
    std::cout << "6. Save Database to File" << std::endl;
    std::cout << "7. Exit" << std::endl;
}

int main() {
    Database db("MovieDB", 1);
    int choice;
    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string id, title, genre, director;
                int year;
                double rating;
                std::cout << "Enter IMDb ID: ";
                std::cin >> id;
                std::cout << "Enter Title: ";
                std::cin.ignore();
                getline(std::cin, title);
                std::cout << "Enter Year: ";
                std::cin >> year;
                std::cout << "Enter Genre: ";
                std::cin.ignore();
                getline(std::cin, genre);
                std::cout << "Enter Rating: ";
                std::cin >> rating;
                std::cout << "Enter Director: ";
                std::cin.ignore();
                getline(std::cin, director);

                Movie* newMovie = new Movie(id, title, year, genre, rating, director);
                db.addMovie(newMovie);
                break;
            }
            case 2: {
                std::string id;
                std::cout << "Enter IMDb ID of movie to remove: ";
                std::cin >> id;
                db.removeMovie(id);
                break;
            }
            case 3:
                db.displayAllMovies();
                break;
            case 4: {
                std::string title;
                std::cout << "Enter movie title: ";
                std::cin.ignore();
                getline(std::cin, title);
                db.searchMoviesByTitle(title);
                break;
            }
            case 5: {
                std::string genre;
                std::cout << "Enter movie genre: ";
                std::cin.ignore();
                getline(std::cin, genre);
                db.searchMoviesByGenre(genre);
                break;
            }
            case 6: {
                std::string filename;
                std::cout << "Enter filename to save database: ";
                std::cin >> filename;
                db.saveToFile(filename);
                break;
            }
            case 7:
                std::cout << "Exiting" << std::endl;
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    } while (choice != 7);

    return 0;
}
