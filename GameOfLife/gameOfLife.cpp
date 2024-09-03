#include "gameOfLife.h"
/* You are only allowed to modify gameOfLife.cpp functions. 
If you create the individual cells on the heap, you must add 
the cleanup code inside of main.cpp (this is the only acceptable
modification to main.cpp). Do not add any libraries to any file!
*/
// create structs 

/*
Function to clear terminal depending on OS
*/
void clearScreen()
{
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

/*
Function to initialize all cells in the board.
Takes in 2D array of pointers and size of array
Should create structs and populate the array
*/
void initCells(Cell* board[][10],/*parameters*/ int boardSize)
{//my attempt  
    for (int i = 0; i < boardSize; ++i)
     {
        for (int j = 0; j < boardSize; ++j) 
        {
            // Allocate a new Cell on the heap
            board[i][j] = new Cell();
            
            // Initialize the cell's position
            board[i][j]->x = i;
            board[i][j]->y = j;
            
            // Initialize the cell's state (dead = 0, alive = 1)
            board[i][j]->state = 0;  // default set here
        }
    }
}

/*
Function to read the board from a file
Prompt for the file to read inside of the function
Structure of file should consist of 10 lines of 0 or 1 to indicate cell state
*/
void readBoard(Cell* board[][10], int boardSize) 
{

}

/*
Function to print out all cells to cout
*/
void printCells(Cell* board[][10], int boardSize)
{

}

/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/
void findNumNeighbors(Cell* board[][10], int boardSize, Cell* curCell) 
{

}

/*
Function to update each cell's state based on number of neighbors
Must use following rules:

Any live cell with fewer than two live neighbors dies, as if by underpopulation.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by overpopulation.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Return if you updated cells or not to break out of while loop from main.
*/
bool updateCellState(Cell* board[][10], int boardSize) 
{
    return false;
}