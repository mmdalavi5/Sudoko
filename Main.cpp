#include "clui.h"
#include <ctime>

#define SIZE 9

// Status codes for a cell.
#define STATUS_CLUE    -1  // cell originally provided as a clue
#define STATUS_NONE     0  // editable cell, no entry or not yet validated
#define STATUS_CORRECT  1  // user entered the correct answer
#define STATUS_WRONG    2  // user entered a wrong answer

// 10 completed sudokus. For demonstration, they are all the same.
// You can replace these with different solved boards.
int sudoku[10][SIZE][SIZE] = {
    {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    },
    {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    },
    {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    },
    {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    },
    {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    },
    {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    },
    {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    },
    {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    },
    {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    }
};

// This function selects one random complete sudoku,
// copies it into both 'solution' and 'table', and then randomly removes 50 cells
// (by setting them to 0) in 'table'. It also sets up the 'editable' array.
// (Cells that become 0 are editable by the user.)
void get_random_sudoku(int table[SIZE][SIZE], int solution[SIZE][SIZE], bool editable[SIZE][SIZE]) {
    // Choose a random puzzle (0 to 9)
    srand((unsigned int)time(nullptr));
    int randomIndex = rand() % 10;
    // Copy the chosen complete puzzle into solution and table.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            solution[i][j] = sudoku[randomIndex][i][j];
            table[i][j] = sudoku[randomIndex][i][j];
        }
    }
    // Randomly remove 50 cells from table.
    int count = 0;
    while (count < 50) {
        int r = rand() % SIZE;
        int c = rand() % SIZE;
        if (table[r][c] != 0) {
            table[r][c] = 0;
            count++;
        }
    }
    // Mark editable cells.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (table[i][j] == 0)
                editable[i][j] = true;
            else
                editable[i][j] = false;
        }
    }
}

// Prints the Sudoku grid centered on the terminal.
// Each cell is displayed according to the following rules:
// - Clue cells (non–editable) are printed in the default color (white).
// - Editable cells that are still blank are printed as " . " in white.
// - If an editable cell has been filled by the user:
//      • If the entered value is correct (matches solution), it is printed in green.
//      • If incorrect, it is printed in red.
void print_sudoku(int table[SIZE][SIZE], bool editable[SIZE][SIZE], int cellStatus[SIZE][SIZE],
                  int start_row, int start_col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cursor_to_pos(start_row + i, start_col + j * 4);
            // If the cell is blank, display a dot.
            if (table[i][j] == 0) {
                // Print blank cells in default (white) color.
                reset_color();
                printf(" . ");
            } else {
                // For editable cells, check the status.
                if (editable[i][j]) {
                    if (cellStatus[i][j] == STATUS_CORRECT) {
                        change_color(COLOR_GREEN);
                    } else if (cellStatus[i][j] == STATUS_WRONG) {
                        change_color(COLOR_RED);
                    } else {
                        reset_color(); // STATUS_NONE: no color change (white)
                    }
                    printf("%3d", table[i][j]);
                } else {
                    // For clue (non–editable) cells, simply print in default.
                    reset_color();
                    printf("%3d", table[i][j]);
                }
            }
        }
    }
    reset_color();
}

// Runs the main game loop. A timer (depending on difficulty) counts down in seconds
// and is displayed at the top left corner. The grid is redrawn centered,
// and the user may navigate with WASD.
// When the user enters a digit in an editable cell, it is compared with the solution;
// if the guess is correct, the cell will afterward be printed in green;
// if not, in red.
void play_sudoku(int table[SIZE][SIZE], int solution[SIZE][SIZE], bool editable[SIZE][SIZE],
                 int cellStatus[SIZE][SIZE], int timeLimit) {
    int x = 0, y = 0;  // starting position (row, col)
    char ch;
    time_t startTime = time(NULL);

    while (true) {
        // Calculate remaining time.
        time_t now = time(NULL);
        int elapsed = now - startTime;
        int remaining = timeLimit - elapsed;
        if (remaining <= 0) {
            clear_screen();
            int totalRows = get_window_rows();
            int totalCols = get_window_cols();
            cursor_to_pos(totalRows / 2, (totalCols - 10) / 2);
            change_color(COLOR_RED);
            printf("Time's up!");
            reset_color();
            delay(3000);
            return;
        }

        // Always display the remaining time at the top–left corner.
        cursor_to_pos(1, 1);
        change_color(COLOR_YELLOW);
        int minutes = remaining / 60;
        int seconds = remaining % 60;
        printf("Time left: %02d:%02d", minutes, seconds);
        reset_color();

        // Calculate centering offsets for the grid.
        int totalRows = get_window_rows();
        int totalCols = get_window_cols();
        int start_row = (totalRows - SIZE) / 2;
        int start_col = (totalCols - (SIZE * 4)) / 2;

        print_sudoku(table, editable, cellStatus, start_row, start_col);

        // Highlight the current cell with a blue background.
        cursor_to_pos(start_row + y, start_col + x * 4);
        change_background_color(BG_BLUE);
        // When reprinting the currently selected cell, obey its displayed status.
        if (table[y][x] == 0) {
            printf(" . ");
        } else {
            if (editable[y][x]) {
                if (cellStatus[y][x] == STATUS_CORRECT) {
                    change_color(COLOR_GREEN);
                } else if (cellStatus[y][x] == STATUS_WRONG) {
                    change_color(COLOR_RED);
                } else {
                    reset_color();
                }
            } else {
                reset_color();
            }
            printf("%3d", table[y][x]);
        }
        reset_color();

        // Process user input.
        ch = getch();
        switch (ch) {
            case 'w':  // move up
                if (y > 0) y--;
                break;
            case 's':  // move down
                if (y < SIZE - 1) y++;
                break;
            case 'a':  // move left
                if (x > 0) x--;
                break;
            case 'd':  // move right
                if (x < SIZE - 1) x++;
                break;
            case 'q':  // quit
                return;
            case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                // Only allow changes in cells that were originally blank.
                if (editable[y][x]) {
                    int guess = ch - '0';
                    table[y][x] = guess;
                    if (guess == solution[y][x])
                        cellStatus[y][x] = STATUS_CORRECT;
                    else
                        cellStatus[y][x] = STATUS_WRONG;
                }
                break;
            default:
                break;
        }
    }
}

int main() {
    init_clui();
    
    // Ask the user for a difficulty level.
    clear_screen();
    cursor_to_pos(1, 1);
    change_color(COLOR_YELLOW);
    printf("Select difficulty level:\n");
    printf("1. Easy (3 minutes)\n");
    printf("2. Normal (2 minutes)\n");
    printf("3. Hard (1.5 minutes)\n");
    printf("Enter your choice (1-3): ");
    reset_color();

    char difficulty = getch();
    int timeLimit = 180; // default to Easy (3 minutes)
    switch (difficulty) {
        case '1': timeLimit = 180; break;
        case '2': timeLimit = 120; break;
        case '3': timeLimit = 90; break;
        default:  timeLimit = 180; break;
    }
    
    // Clear the screen before starting the game.
    clear_screen();
    
    int table[SIZE][SIZE];
    int solution[SIZE][SIZE];
    bool editable[SIZE][SIZE];
    int cellStatus[SIZE][SIZE];

    // Get a random completed sudoku and remove 50 cells.
    get_random_sudoku(table, solution, editable);

    // Initialize cellStatus: clue cells get STATUS_CLUE; editable cells get STATUS_NONE.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (editable[i][j])
                cellStatus[i][j] = STATUS_NONE;
            else
                cellStatus[i][j] = STATUS_CLUE;
        }
    }
    
    play_sudoku(table, solution, editable, cellStatus, timeLimit);
    quit();
    return 0;
}
