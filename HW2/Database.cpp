database2:#include "Database.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

namespace database 
{

    // Constructor to initialize the database with a name and ID
    Database::Database(const string& dbName, int dbId)
        : name(dbName), dbId(dbId) {}

    // Destructor to delete all media objects and free memory
    Database::~Database() 
    {
        for (auto media : mediaList)
        {
            delete media;  // Delete each media object
        }
    }

    // Load media items from a file
    void Database::loadMediaFromFile(const string& filename) 
    {
        ifstream fin(filename);  // Open the file for reading
        if (!fin) 
        {
            cout << "Error opening file: " << filename << endl;
            return;  // Stop if file can't be opened
        }

        string line;
        while (getline(fin, line))
        {
            stringstream ss(line);
            string type, id, title, year, genre, extra1, extra2;
            getline(ss, type, ',');
            getline(ss, id, ',');
            getline(ss, title, ',');
            getline(ss, year, ',');
            getline(ss, genre, ',');

                if (type == "Movie") 
                {
                    getline(ss, extra1, ','); // Rating
                    getline(ss, extra2);     // Director
                    addMedia(new Movie(id, title, year, genre, stod(extra1), extra2));
                } else if (type == "TV") 
                {
                    getline(ss, extra1, ','); // Rating
                    getline(ss, extra2);     // Episodes
                    addMedia(new TvShow(id, title, year, genre, stod(extra1), stoi(extra2)));
                } else if (type == "Music") 
                {
                    getline(ss, extra1, ','); // Composer
                    getline(ss, extra2, ','); // Tracks
                    string totalPlaytime;
                    getline(ss, totalPlaytime);
                    addMedia(new Music(id, title, year, genre, extra1, stoi(extra2), stod(totalPlaytime)));
                }
            }
            fin.close();  // Close the file
        }

    // Add a media item to the database
    void Database::addMedia(Media* newMedia) 
    {
        mediaList.push_back(newMedia);  // Add media to list

        // Save the media to its specific file
        ofstream fout;
        if (dynamic_cast<Movie*>(newMedia)) 
            {
                fout.open("movies.csv", ios::app);
            } else if (dynamic_cast<TvShow*>(newMedia)) 
            {
                fout.open("tvshows.csv", ios::app);
            } else if (dynamic_cast<Music*>(newMedia)) 
            {
                fout.open("music.csv", ios::app);
            }

            if (fout) 
            {
                fout << newMedia->getType() << ","
                     << newMedia->getId() << ","
                    << newMedia->getTitle() << ","
                    << newMedia->getYear() << ","
                     << newMedia->getGenre() << ","
                    << newMedia->getExtra1() << ","
                    << newMedia->getExtra2() << endl;
                fout.close();
            }
    }      

    // Remove a media item from the database by its ID
    void Database::removeMediaById(const string& id) 
    {
        for (auto it = mediaList.begin(); it != mediaList.end(); ++it) 
            {
            if ((*it)->getId() == id) 
                {
                    cout << "Removing: " << (*it)->getTitle() << endl;
                    delete *it;
                    mediaList.erase(it);
                    break;
                }
            }

        // Update all relevant files
        updateFile("movies.csv", id);
        updateFile("tvshows.csv", id);
        updateFile("music.csv", id);
    }

    // Helper function to update files after deletion
    void Database::updateFile(const string& filename, const string& id) 
    {   
        ifstream fin(filename);
        ofstream fout("temp.csv");

        string line;
        while (getline(fin, line)) 
        {
            if (line.find(id) == string::npos) 
            {
                fout << line << endl;
            }
        }

        fin.close();
        fout.close();
        remove(filename.c_str());
        rename("temp.csv", filename.c_str());
    }

    // Display all media items of a specific type
    void Database::displayMediaByType(const string& type)  
    {
        cout << "Displaying " << type << " list:\n";
        for (auto media : mediaList) 
        {
            if (media->getType() == type) 
                {
                media->displayInfo();
                }
        }
    }

    // Write the entire database to a unified file
    void Database::writeDatabaseToFile(const string& filename) 
    {
    ofstream fout(filename);
    if (!fout) {
        cout << "Error creating file: " << filename << endl;
        return;
    }

    fout << "Media Database\n";
    for (auto media : mediaList) {
        fout << media->toString() << endl;
    }
    fout.close();
    cout << "Database written to " << filename << endl;
    }

} // namespace database