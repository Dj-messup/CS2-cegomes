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
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            // Allocate a new Cell on the heap
            board[i][j] = new Cell();
            
            // Initialize the cell's position
            board[i][j]->x = i;
            board[i][j]->y = j;
            board[i][j]->state = 0;  // Initially, all cells are dead
            board[i][j]->numLiveNeighbors = 0;
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
    string filename;
    cout << "Enter the filename to read the board: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    for (int i = 0; i < boardSize; ++i) {
        getline(file, line);
        for (int j = 0; j < boardSize; ++j) 
        {
            if (line[j] == '1') {
                board[i][j]->state = 1;  // Cell is alive
            } else {
                board[i][j]->state = 0;  // Cell is dead
            }
        }
    }

    file.close();
}


/*
Function to print out all cells to cout
*/
void printCells(Cell* board[][10], int boardSize)
{
    for (int i = 0; i < boardSize; ++i) 
    {
        for (int j = 0; j < boardSize; ++j) 
        {
            if (board[i][j]->state == 1) 
            {
                cout << "1 ";
            } else 
            {
                cout << "0 ";
            }
        }
        cout << endl;  // Moved outside inner loop to ensure new line after each row
    }
}

/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/

void findNumNeighbors(Cell* board[][10], int boardSize, Cell* curCell) 
{
    // Reset the number of live neighbors
    curCell->numLiveNeighbors = 0;

    int x = curCell->x;
    int y = curCell->y;

    // Check cell to the upper-left
    if (x > 0 && y > 0) {
        if (board[x-1][y-1]->state == 1) {
            curCell->numLiveNeighbors += 1;
        }
    }

    // Check cell above
    if (x > 0) {
        if (board[x-1][y]->state == 1) {
            curCell->numLiveNeighbors += 1;
        }
    }

    // Check cell to the upper-right
    if (x > 0 && y < boardSize - 1) {
        if (board[x-1][y+1]->state == 1) {
            curCell->numLiveNeighbors += 1;
        }
    }

    // Check cell to the left
    if (y > 0) {
        if (board[x][y-1]->state == 1) {
            curCell->numLiveNeighbors += 1;
        }
    }

    // Check cell to the right
    if (y < boardSize - 1) {
        if (board[x][y+1]->state == 1) {
            curCell->numLiveNeighbors += 1;
        }
    }

    // Check cell to the lower-left
    if (x < boardSize - 1 && y > 0) {
        if (board[x+1][y-1]->state == 1) {
            curCell->numLiveNeighbors += 1;
        }
    }

    // Check cell below
    if (x < boardSize - 1) {
        if (board[x+1][y]->state == 1) {
            curCell->numLiveNeighbors += 1;
        }
    }

    // Check cell to the lower-right
    if (x < boardSize - 1 && y < boardSize - 1) {
        if (board[x+1][y+1]->state == 1) {
            curCell->numLiveNeighbors += 1;
        }
    }
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
    bool updated = false;
    Cell* newBoard[10][10];

    // Initialize new board
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            newBoard[i][j] = new Cell();
            newBoard[i][j]->x = i;
            newBoard[i][j]->y = j;
            newBoard[i][j]->state = board[i][j]->state;
        }
    }

    // // Update cell states based on Game of Life rules
    // for (int i = 0; i < boardSize; ++i) {
    //     for (int j = 0; j < boardSize; ++j) {
    //         findNumNeighbors(board, boardSize, board[i][j]);
    //         int liveNeighbors = board[i][j]->numLiveNeighbors;

    //         if (board[i][j]->state == 1) {
    //             // Rules for live cells
    //             if (liveNeighbors < 2 || liveNeighbors > 3) {
    //                 newBoard[i][j]->state = 0;  // Cell dies
    //                 updated = true;
    //             }
    //         } else {
    //             // Rule for dead cells
    //             if (liveNeighbors == 3) {
    //                 newBoard[i][j]->state = 1;  // Cell becomes alive
    //                 updated = true;
    //             }
    //         }
    //     }
    // }

    // // Copy new board to original board and delete temporary cells
    // for (int i = 0; i < boardSize; ++i) {
    //     for (int j = 0; j < boardSize; ++j) {
    //         board[i][j]->state = newBoard[i][j]->state;
    //         delete newBoard[i][j];
    //     }
    // }

    return updated;
}

// void readBoard(Cell* board[][10], int boardSize)
// {
//     string fileName;
//     cout << "Please enter the file name of the board you would like to read: ";
//     cin >> fileName;

//     // Open the file and check if it was successful
//     ifstream fin(fileName);
//     if (!fin) {
//         cerr << "Failed to open file: " << fileName << endl;
//         return;
//     }

//     // Use char instead of string to read individual characters
//     char temp;

//     // Loop through each cell in the board
//     for (int i = 0; i < boardSize; i++)
//     {
//         for (int j = 0; j < boardSize; j++)
//         {
//             // Read a single character
//             fin >> temp;

//             // Check if we've reached the end of the file
//             if (fin.eof()) break;

//             // Create a new Cell and populate it
//             Cell* someCell = new Cell();
//             someCell -> state = temp;
//             someCell -> x = i;
//             someCell -> y = j;
//             board[i][j] = someCell;
//         }

//         // Check again for EOF after each row
//         if (fin.eof()) break;
//     }

//     // Always close the file when done
//     fin.close();
// }