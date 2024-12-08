#include "Database.h"
#include <iostream>
using namespace std;

int main() {
    Database db;

    // try loading files first
    bool filesOk = true;
    if(!db.loadFile("movies.csv")) {
        cout << "Warning: had trouble with movies.csv\n";
        filesOk = false;
    }
    if(!db.loadFile("tvshows.csv")) {
        cout << "Warning: had trouble with tvshows.csv\n";
        filesOk = false;
    }
    if(!db.loadFile("music.csv")) {
        cout << "Warning: had trouble with music.csv\n";
        filesOk = false;
    }

    if(!filesOk) {
        cout << "Some files didn't load right but we'll keep going\n";
    }

    // variables we need for the menu
    int choice;
    string title;  // moved outside switch
    int id;        // moved outside switch

    do {
        cout << "\nMedia Database Menu:\n";
        cout << "1. Show all\n";
        cout << "2. Search\n";
        cout << "3. Remove\n";
        cout << "4. Quit\n";
        cout << "Pick one: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                db.displayAll();
                break;
                
            case 2:
                cout << "Enter title: ";
                getline(cin, title);
                db.searchByTitle(title);
                break;
                
            case 3:
                cout << "Enter ID: ";
                cin >> id;
                db.removeMedia(id);
                db.saveToFiles();  // save changes
                break;
                
            case 4:
                cout << "Bye!\n";
                break;
                
            default:
                cout << "That's not a choice!\n";
        }
    } while(choice != 4);

    return 0;
}