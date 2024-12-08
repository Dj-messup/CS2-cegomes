// main.cpp
#include <iostream>
#include "Database.h"
using namespace std;

int main() {
    Database db;
    db.loadFile("movies.csv");
    db.loadFile("tvshows.csv");
    db.loadFile("music.csv");
    
    int choice;
    cout << "Welcome to Media Database\n";
    
    while(true) {
        cout << "\nWhat would you like to do?\n";
        cout << "1. Show everything\n";
        cout << "2. Find something\n";
        cout << "3. Remove something\n";
        cout << "4. Quit\n";
        cout << "Choice: ";
        cin >> choice;
        
        if(choice == 1) {
            db.displayAll();
        }
        else if(choice == 2) {
            string title;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            db.searchByTitle(title);
        }
        else if(choice == 3) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            db.removeMedia(id);
        }
        else if(choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
    
    return 0;
}