# Terminal Minesweeper Game

A terminal-based implementation of the classic **Minesweeper** game developed in **C++**. The game features random mine placement, recursive cell revealing, flagging functionality, and win/loss detection, providing an interactive command-line gaming experience.

---

## Project Overview

This project recreates the classic Minesweeper game in a command-line interface. Players reveal cells while avoiding hidden mines. The game automatically calculates adjacent mine counts, supports flagging suspected mines, and uses a recursive flood-fill algorithm to reveal connected empty cells.

---

## Features

- Random mine placement on an 8 × 8 game board
- Automatic calculation of adjacent mine counts
- Recursive flood-fill algorithm for revealing empty cells
- Flag and unflag cells to mark suspected mines
- Win detection when all safe cells are revealed
- Loss detection when a mine is uncovered
- Interactive terminal-based gameplay

---

## Technologies Used

- **Language:** C++
- **Concepts:** Structures, Vectors, Recursion, Random Number Generation, Functions
- **Libraries:** `<iostream>`, `<vector>`, `<cstdlib>`, `<ctime>`

## Gameplay

The game begins with an **8 × 8** board containing **10 hidden mines**. The player reveals cells while avoiding mines. If an empty cell with no adjacent mines is revealed, neighbouring cells are automatically uncovered using a recursive flood-fill algorithm.

### Symbols

| Symbol | Description |
|--------|-------------|
| `#` | Hidden cell |
| `.` | Revealed empty cell |
| `1-8` | Number of adjacent mines |
| `F` | Flagged cell |
| `*` | Mine |

### Player Input

```
Enter x y (R for reveal, F for flag):
```

Example:

```
2 5 R
```

Reveals the cell at row **2**, column **5**.

```
4 3 F
```

Places or removes a flag at row **4**, column **3**.

---

## Game Logic

- Generates an **8 × 8** board with **10 randomly placed mines**.
- Computes the number of adjacent mines for every non-mine cell.
- Revealing a mine immediately ends the game.
- Revealing an empty cell recursively uncovers neighbouring empty cells.
- The player wins by revealing all non-mine cells.

---

## Sample Output

```
   0 1 2 3 4 5 6 7
0 |# # # # # # # #
1 |# # # # # # # #
2 |# # # # # # # #
3 |# # # # # # # #
4 |# # # # # # # #
5 |# # # # # # # #
6 |# # # # # # # #
7 |# # # # # # # #

Enter x y (R for reveal, F for flag):
```

---

## Future Enhancements

- Multiple difficulty levels
- First-click safety guarantee
- Timer and score tracking
- Colored terminal output
- Menu-driven interface
- Save and load game functionality

---

## License

This project is licensed under the **MIT License**.
