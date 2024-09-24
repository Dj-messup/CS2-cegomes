/* Background:
Learning how to create a simple database using classes will aid in understanding additional concepts with object oriented programming. We will be creating a database to track movies with a number of various fields including title, genre, release year, rating, etc.

Tasks:
Create a folder named HW1 under your Assignments folder.
Create a main.cpp as the front driver for your program.
Create a movie.h, movie.cpp, database.h, database.cpp for your program.
Create a Makefile and configure it to compile with all cpp files.
Using techniques discussed in class and in the labs, create the following:
A namespace called movies
A class called Movie
Each movie should have the following variables: imdb title id, title, year, genre, rating and director. 
There should be appropriate methods to get and set variables and all variables should be private.
Assume that all variables will have one value for each movie, i.e. only one director or only one genre type.
A class called Database
You will typically have one database for this assignment
The database should have the following variables: name, db_id, array for Movies (as pointers)
The database should have the following functionality:
Add movie, remove movie (given ID), display all movies, search for movie given title or genre and print out a table of them.
For this assignment, your database can create an array of 100 movies (ie movies::Movies* movieList[100];) and assume that there will never be more than 100 movies tracked at one time.
Read in the movies from a file
You can use a sample list of movies from here: https://github.com/jeremybergen/CSCI112/tree/main/Assignments/HW1 feel free to add your own movies to the list
You should have a simple menu driven interface to allow a user to manually add in movies, delete movies, print out movies or write out the entire database to a different CSV file. This should be coded inside of main.
Update README.md
Submit screenshot to D2L of program running
All code must be uploaded to GitHub
Follow standard coding styles including adding comments as necessary to clarify complex sections of code*/


