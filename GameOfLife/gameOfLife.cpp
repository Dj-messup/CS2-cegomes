#include "gameOfLife.h"

/*
Function to clear terminal depending on OS
*/

void clearScreen()
{
    //using "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/*
Function to initialize all cells in the board. 
Takes in 2D array of pointers and size of array
Should create structs and populate the array
*/

void initCells(Cell* board[][10], int boardSize)
{

}

/*
Function to read
*/