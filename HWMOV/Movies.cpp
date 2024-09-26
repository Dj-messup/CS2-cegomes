/*#include <iostream>
#include <cassert>
#include "library.h"

// Global variables
Book library[MAX_BOOKS];
int numBooks = 0;

// Function definitions
void displayMenu() {
    std::cout << "Welcome to the Library Management System" << std::endl;
    std::cout << "1. Add a Book" << std::endl;
    std::cout << "2. Remove a Book" << std::endl;
    std::cout << "3. Display All Books" << std::endl;
    std::cout << "4. Search for a Book" << std::endl;
    std::cout << "5. Borrow a Book" << std::endl;
    std::cout << "6. Return a Book" << std::endl;
    std::cout << "7. Exit" << std::endl;
}

void addBook() {
    if (numBooks < MAX_BOOKS) {
        std::cout << "Enter book title: ";
        std::cin.ignore();
        getline(std::cin, library[numBooks].title);
        std::cout << "Enter author name: ";
        getline(std::cin, library[numBooks].author);
        library[numBooks].available = true; // Mark book available
        numBooks++; // Increment count of books
        std::cout << "Book added successfully." << std::endl;
    } else {
        std::cout << "Library is full. Cannot add more books." << std::endl;
    }
}

// Function to return a book
void returnBook() {
    if (numBooks > 0) {
        std::string title;
        std::cout << "Enter the title of the book to return: ";
        std::cin.ignore();
        getline(std::cin, title);
        bool found = false;
        for (int i = 0; i < numBooks; i++) {
            if (library[i].title == title && !library[i].available) {
                library[i].available = true; // Book is now available
                std::cout << "Book returned successfully." << std::endl;
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Book not found in the library or already returned." << std::endl;
        }
    } else {
        std::cout << "Library is empty. No books to return." << std::endl;
    }
}

// Function to search for a book by title or author
void searchBook() {
    if (numBooks > 0) {
        std::string searchTerm;
        std::cout << "Enter title or author to search: ";
        std::cin.ignore();
        getline(std::cin, searchTerm);
        bool found = false;
        for (int i = 0; i < numBooks; i++) {
            if (library[i].title.find(searchTerm) != std::string::npos || library[i].author.find(searchTerm) != std::string::npos) {
                std::cout << "Book found:" << std::endl;
                std::cout << "Title: " << library[i].title << ", Author: " << library[i].author;
                if (library[i].available) {
                    std::cout << " (Available)" << std::endl;
                } else {
                    std::cout << " (Not Available)" << std::endl;
                }
                found = true;
            }
        }
        if (!found) {
            std::cout << "Book not found in the library." << std::endl;
        }
    } else {
        std::cout << "Library is empty. No books to search." << std::endl;
    }
}

// Function to borrow a book
void borrowBook() {
    if (numBooks > 0) {
        std::string title;
        std::cout << "Enter the title of the book to borrow: ";
        std::cin.ignore();
        getline(std::cin, title);
        bool found = false;
        for (int i = 0; i < numBooks; i++) {
            if (library[i].title == title && library[i].available) {
                library[i].available = false; // Book is now unavailable
                std::cout << "Book borrowed successfully." << std::endl;
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Book not found in the library or not available for borrowing." << std::endl;
        }
    } else {
        std::cout << "Library is empty. No books to borrow." << std::endl;
    }
}

// Function to display all books in the library
void displayAllBooks() {
    if (numBooks > 0) {
        std::cout << "List of books in the library:" << std::endl;
        for (int i = 0; i < numBooks; i++) {
            std::cout << "Title: " << library[i].title << ", Author: " << library[i].author;
            if (library[i].available) {
                std::cout << " (Available)" << std::endl;
            } else {
                std::cout << " (Not Available)" << std::endl;
            }
        }
    } else {
        std::cout << "Library is empty. No books to display." << std::endl;
    }
}

// Function to remove a book from the library
void removeBook() {
    if (numBooks == 0) {
        std::cout << "Library is empty. No books to remove." << std::endl;
        return;
    }
    std::string title;
    std::cout << "Enter the title of the book to remove: ";
    std::cin.ignore();
    getline(std::cin, title);
    bool found = false;
    for (int i = 0; i < numBooks; i++) {
        if (library[i].title == title) {
            // Shift books to fill the gap
            for (int j = i; j < numBooks - 1; j++) {
                library[j] = library[j + 1];
            }
            numBooks--; // Decrement the count of books
            std::cout << "Book removed successfully." << std::endl;
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Book not found in the library." << std::endl;
    }
}
*/