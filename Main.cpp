#include "clui.h"
#include <ctime>

#define SIZE 9

// 10 prebuilt Sudoku puzzles.
// A 0 represents an empty cell.
int sudoku[10][SIZE][SIZE] = {
    // Puzzle 1
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    },
    // Puzzle 2
    {
        {0, 0, 0, 2, 6, 0, 7, 0, 1},
        {6, 8, 0, 0, 7, 0, 0, 9, 0},
        {1, 9, 0, 0, 0, 4, 5, 0, 0},
        {8, 2, 0, 1, 0, 0, 0, 4, 0},
        {0, 0, 4, 6, 0, 2, 9, 0, 0},
        {0, 5, 0, 0, 0, 3, 0, 2, 8},
        {0, 0, 9, 3, 0, 0, 0, 7, 4},
        {0, 4, 0, 0, 5, 0, 0, 3, 6},
        {7, 0, 3, 0, 1, 8, 0, 0, 0}
    },
    // Puzzle 3
    {
        {0, 2, 0, 6, 0, 8, 0, 0, 0},
        {5, 8, 0, 0, 0, 9, 7, 0, 0},
        {0, 0, 0, 0, 4, 0, 0, 0, 0},
        {3, 7, 0, 0, 0, 0, 5, 0, 0},
        {6, 0, 0, 0, 0, 0, 0, 0, 4},
        {0, 0, 8, 0, 0, 0, 0, 1, 3},
        {0, 0, 0, 0, 2, 0, 0, 0, 0},
        {0, 0, 9, 8, 0, 0, 0, 3, 6},
        {0, 0, 0, 3, 0, 6, 0, 9, 0}
    },
    // Puzzle 4
    {
        {0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 8, 0, 0, 0, 7, 0, 9, 0},
        {6, 0, 2, 0, 0, 0, 5, 0, 0},
        {0, 7, 0, 0, 6, 0, 0, 0, 0},
        {0, 0, 0, 9, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 4, 0},
        {0, 0, 5, 0, 0, 0, 6, 0, 3},
        {0, 9, 0, 4, 0, 0, 0, 7, 0},
        {0, 0, 6, 0, 0, 0, 0, 0, 0}
    },
    // Puzzle 5
    {
        {0, 0, 0, 0, 0, 0, 0, 1, 2},
        {0, 0, 0, 0, 3, 5, 0, 0, 0},
        {0, 0, 8, 0, 0, 0, 4, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 0, 8},
        {0, 0, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, 1, 0, 0, 0, 7, 0, 0},
        {0, 0, 0, 3, 8, 0, 0, 0, 0},
        {2, 4, 0, 0, 0, 0, 0, 0, 0}
    },
    // Puzzle 6
    {
        {1, 0, 0, 0, 0, 7, 0, 9, 0},
        {0, 3, 0, 0, 2, 0, 0, 0, 8},
        {0, 0, 9, 6, 0, 0, 5, 0, 0},
        {0, 0, 5, 3, 0, 0, 9, 0, 0},
        {0, 1, 0, 0, 8, 0, 0, 0, 2},
        {6, 0, 0, 0, 0, 4, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 4, 0, 0, 0, 0, 0, 0, 7},
        {0, 0, 7, 0, 0, 0, 3, 0, 0}
    },
    // Puzzle 7
    {
        {0, 2, 0, 0, 0, 0, 0, 6, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 5},
        {0, 1, 0, 0, 8, 0, 9, 0, 0},
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 7, 0, 0, 0, 0, 0},
        {0, 0, 6, 0, 0, 0, 0, 0, 1},
        {0, 0, 2, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 6, 0, 0, 0},
        {0, 5, 0, 0, 0, 0, 0, 8, 0}
    },
    // Puzzle 8
    {
        {9, 0, 0, 0, 0, 0, 0, 7, 0},
        {0, 0, 0, 4, 2, 0, 1, 0, 0},
        {0, 8, 0, 0, 0, 0, 0, 3, 0},
        {0, 0, 7, 0, 0, 1, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {6, 0, 0, 7, 0, 0, 8, 0, 0},
        {0, 7, 0, 0, 0, 0, 0, 5, 0},
        {0, 0, 9, 0, 3, 6, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 2}
    },
    // Puzzle 9
    {
        {2, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 7, 0, 0, 0, 9, 0, 0},
        {0, 0, 0, 4, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 6, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 0, 0, 0},
        {0, 0, 5, 0, 0, 0, 8, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 3}
    },
    // Puzzle 10
    {
        {0, 0, 0, 2, 0, 0, 0, 6, 0},
        {0, 0, 1, 0, 0, 0, 7, 0, 0},
        {0, 3, 0, 0, 9, 0, 0, 0, 8},
        {0, 0, 0, 7, 0, 0, 0, 0, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 4, 0, 0, 0},
        {7, 0, 0, 0, 2, 0, 0, 5, 0},
        {0, 0, 6, 0, 0, 0, 1, 0, 0},
        {0, 8, 0, 0, 0, 9, 0, 0, 0}
    }
};

// Copies a random Sudoku puzzle into the provided table.
void get_random_sudoku(int table[SIZE][SIZE]) {
    srand((unsigned int)time(nullptr));
    int randomIndex = rand() % 10;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            table[i][j] = sudoku[randomIndex][i][j];
}

// Prints the Sudoku grid centered on the terminal.
// The grid is drawn starting at (start_row, start_col) with each cell taking up 4 columns.
void print_sudoku(int table[SIZE][SIZE], int start_row, int start_col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cursor_to_pos(start_row + i, start_col + j * 4);
            if (table[i][j] == 0) {
                change_color(COLOR_CYAN);
                printf(" . ");
            } else {
                change_color(COLOR_GREEN);
                printf("%3d", table[i][j]);
            }
        }
    }
    reset_color();
}

// Runs the main game loop. A timer counts down from timeLimit (in seconds)
// and is displayed in the top left corner. The grid is drawn centered, and the
// currently selected cell is highlighted in red. When a number is entered,
// the cell is updated only if the corresponding cell in the original puzzle was zero.
void play_sudoku(int table[SIZE][SIZE], int original[SIZE][SIZE], int timeLimit) {
    int x = 0, y = 0;  // starting position at the top-left cell
    char ch;
    time_t startTime = time(NULL);
    
    while (true) {
        // Calculate time remaining.
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
        
        // Display the remaining time in the top-left corner.
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
        
        print_sudoku(table, start_row, start_col);
        
        // Highlight the current cell.
        cursor_to_pos(start_row + y, start_col + x * 4);
        change_color(COLOR_RED);
        if (table[y][x] == 0)
            printf(" . ");
        else
            printf("%3d", table[y][x]);
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
                // Only update the cell if the original puzzle had a 0.
                if (original[y][x] == 0)
                    table[y][x] = ch - '0';
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
    int original[SIZE][SIZE];
    get_random_sudoku(table);
    // Copy the chosen puzzle into a separate original board.
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            original[i][j] = table[i][j];
    
    play_sudoku(table, original, timeLimit);
    
    quit();
    return 0;
}
