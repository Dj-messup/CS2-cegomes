#include "Database.h"  // Database class
#include "Movie.h"     // Movie class
#include <iostream>
#include <string>

int main() {
    // create DB object
    movies::Database db("My Movie Database", 1);

    int choice;  // stores menu choice
    do {
        // Display menu
        std::cout << "Menu:\n1. Add Movie\n2. Remove Movie\n3. Display All Movies\n4. Search by Title\n5. Search by Genre\n6. Save to File\n7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // add movie to DB
                std::string id, title, genre, director;
                int year;
                double rating;

                std::cout << "Enter IMDb ID: ";
                std::cin >> id;
                std::cout << "Enter Title: ";
                std::cin.ignore();  // clear input buffer
                getline(std::cin, title);
                std::cout << "Enter Year: ";
                std::cin >> year;
                std::cout << "Enter Genre: ";
                std::cin.ignore();  // clear 
                getline(std::cin, genre);
                std::cout << "Enter Rating: ";
                std::cin >> rating;
                std::cout << "Enter Director: ";
                std::cin.ignore();  // clear
                getline(std::cin, director);

                // Create movie and add it to the DB
                movies::Movie* newMovie = new movies::Movie(id, title, year, genre, rating, director);  // req: dynamically alloc Movie obj
                db.addMovie(newMovie);  // add Movie to DB
                break;
            }
            case 2: {
                // remove movie by IMDB ID
                std::string id;
                std::cout << "Enter IMDb ID of movie to remove: ";
                std::cin >> id;
                db.removeMovie(id);  //remove Movie from DB by ID
                break;
            }
            case 3:
                // print all movies
                db.displayAllMovies();  //display Movies in DB
                break;
            case 4: {
                // search movie by title
                std::string title;
                std::cout << "Enter movie title: ";
                std::cin.ignore();  // clear
                getline(std::cin, title);
                db.searchMoviesByTitle(title); 
                break;
            }
            case 5: {
                // search movie by genre
                std::string genre;
                std::cout << "Enter movie genre: ";
                std::cin.ignore();  // clear
                getline(std::cin, genre);
                db.searchMoviesByGenre(genre); 
                break;
            }
            case 6: {
                // write DB to file
                std::string filename;
                std::cout << "Enter filename to save database: ";
                std::cin >> movies.csv;
                db.saveToFile(movies.csv);
                break;
            }
            case 7:
                // Exit
                std::cout << "Exiting" << std::endl;
                break;
            default:
                // Handle invalid input
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    } while (choice != 7);  // loop until user exits

    return 0;
}
