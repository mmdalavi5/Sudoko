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

// Selects a random Sudoku puzzle and copies it to table.
void get_random_sudoku(int table[SIZE][SIZE]) {
    srand((unsigned int)time(nullptr));
    int randomIndex = rand() % 10;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            table[i][j] = sudoku[randomIndex][i][j];
}

// Prints the Sudoku grid centered on the terminal.
// The grid starts at (start_row, start_col) and each cell occupies 4 columns.
void print_sudoku(int table[SIZE][SIZE], int start_row, int start_col) {
    clear_screen();
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

// Allows navigation with WASD. The grid is redrawn centered,
// and the currently selected cell is highlighted in red.
// When the user presses a number key, the value is only changed if the cell is empty.
void play_sudoku(int table[SIZE][SIZE]) {
    int x = 0, y = 0; // starting position at the top-left cell
    char ch;
    while (true) {
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

        ch = getch();
        switch (ch) {
            case 'w': // move up
                if (y > 0) y--;
                break;
            case 's': // move down
                if (y < SIZE - 1) y++;
                break;
            case 'a': // move left
                if (x > 0) x--;
                break;
            case 'd': // move right
                if (x < SIZE - 1) x++;
                break;
            case 'q': // quit
                return;
            case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                // Only update the cell if it's currently empty.
                if (table[y][x] == 0)
                    table[y][x] = ch - '0';
                break;
            default:
                break;
        }
    }
}

int main() {
    init_clui();
    int table[SIZE][SIZE];
    get_random_sudoku(table);
    play_sudoku(table);
    quit();
    return 0;
}
