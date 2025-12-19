#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 8;  // Board size
const int MINES = 10; // Number of mines

struct Cell {
    bool isMine;
    bool isRevealed;
    bool isFlagged;
    int adjacentMines;
};

vector<vector<Cell>> board(SIZE, vector<Cell>(SIZE));

void initializeBoard() {
    srand(time(0));
    int placedMines = 0;

    while (placedMines < MINES) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (!board[x][y].isMine) {
            board[x][y].isMine = true;
            placedMines++;
        }
    }

    // Calculate adjacent mine counts
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].isMine) continue;
            int count = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = i + dx, ny = j + dy;
                    if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny].isMine)
                        count++;
                }
            }
            board[i][j].adjacentMines = count;
        }
    }
}

void printBoard(bool reveal = false) {
    cout << "   ";
    for (int i = 0; i < SIZE; i++) cout << i << " ";
    cout << "\n";

    for (int i = 0; i < SIZE; i++) {
        cout << i << " |";
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].isFlagged) {
                cout << "F ";  // Flagged cells
            } else if (reveal || board[i][j].isRevealed) {
                if (board[i][j].isMine)
                    cout << "* ";  // Mines
                else if (board[i][j].adjacentMines == 0)
                    cout << ". ";  // Empty cells with no adjacent mines
                else
                    cout << board[i][j].adjacentMines << " ";  // Numbers indicating adjacent mines
            } else {
                cout << "# ";  // Unrevealed cells
            }
        }
        cout << "\n";
    }
}


void revealCell(int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y].isRevealed || board[x][y].isFlagged)
        return;

    board[x][y].isRevealed = true;

    if (board[x][y].adjacentMines == 0) {  // Flood fill for empty cells
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                revealCell(x + dx, y + dy);
            }
        }
    }
}

bool checkWin() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j].isMine && !board[i][j].isRevealed)
                return false;
        }
    }
    return true;
}

void playGame() {
    initializeBoard();
    bool gameOver = false;

    while (!gameOver) {
        printBoard();
        int x, y;
        char action;
        cout << "Enter x y (R for reveal, F for flag): ";
        cin >> x >> y >> action;

        if (action == 'R') {
            if (board[x][y].isMine) {
                cout << "Game Over! You hit a mine.\n";
                printBoard(true);
                gameOver = true;
            } else {
                revealCell(x, y);
                if (checkWin()) {
                    cout << "Congratulations! You won!\n";
                    printBoard(true);
                    gameOver = true;
                }
            }
        } else if (action == 'F') {
            board[x][y].isFlagged = !board[x][y].isFlagged;
        }
    }
}

int main() {
    playGame();
    return 0;
}