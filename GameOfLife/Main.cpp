#include <iostream>
#include <string>
#include "gameOfLife.h"

using namespace std;

int main(int argc, char* argv[])
{
    int stage = 0;
    bool boardChanged = true;
    size_t boardSize = 10;
    Cell* board[10][10];

    initCells(board, boardSize);
    readBoard(board, boardSize);

    while(boardChanged) 
    {
        clearScreen();
        cout << "Stage: " << stage << endl;

        printCells(board, boardSize);
        boardChanged = updateCellState(board, boardSize);

        cin.get();
        stage++;
    }

    // Clean up board if cells were allocated on the heap
    // Clean up dynamically allocated memory for the board
    for (int i = 0; i < boardSize; ++i) 
    {
        for (int j = 0; j < boardSize; ++j) 
        {
            delete board[i][j];  // Deallocate each Cell object
        }
    }


    return 0;
}