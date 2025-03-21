#include "clui.h"
#include <ctime>

// Define Sudoku table size
#define SIZE 9

// Predefined Sudoku tables
int sudoku[10][SIZE][SIZE] = {
    {{5, 3, 0, 0, 7, 0, 0, 0, 0},
     {6, 0, 0, 1, 9, 5, 0, 0, 0},
     {0, 9, 8, 0, 0, 0, 0, 6, 0},
     {8, 0, 0, 0, 6, 0, 0, 0, 3},
     {4, 0, 0, 8, 0, 3, 0, 0, 1},
     {7, 0, 0, 0, 2, 0, 0, 0, 6},
     {0, 6, 0, 0, 0, 0, 2, 8, 0},
     {0, 0, 0, 4, 1, 9, 0, 0, 5},
     {0, 0, 0, 0, 8, 0, 0, 7, 9}},
    
};

// Function to select a random Sudoku table
void get_random_sudoku(int table[SIZE][SIZE])
{
    srand((unsigned int)time(nullptr));
    int randomIndex = rand() % 10;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            table[i][j] = sudoku[randomIndex][i][j];
        }
    }
}

// Function to print the Sudoku grid
void print_sudoku(int table[SIZE][SIZE])
{
    clear_screen();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cursor_to_pos(i + 1, j * 4 + 1); // Positioning each cell
            if (table[i][j] == 0)
            {
                change_color(COLOR_CYAN);
                printf(" . ");
            }
            else
            {
                change_color(COLOR_GREEN);
                printf("%3d", table[i][j]);
            }
        }
        reset_color();
        printf("\n");
    }
}

// Function to navigate and edit Sudoku table
void play_sudoku(int table[SIZE][SIZE])
{
    int x = 0, y = 0;
    char ch;
    while (true)
    {
        cursor_to_pos(y + 1, x * 4 + 1);
        change_color(COLOR_RED);
        printf("%3d", table[y][x]);
        reset_color();

        ch = getch();
        switch (ch)
        {
        case 'w': // Move up
            if (y > 0)
                y--;
            break;
        case 's': // Move down
            if (y < SIZE - 1)
                y++;
            break;
        case 'a': // Move left
            if (x > 0)
                x--;
            break;
        case 'd': // Move right
            if (x < SIZE - 1)
                x++;
            break;
        case 'q': // Quit
            return;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            table[y][x] = ch - '0';
            break;
        }
        print_sudoku(table);
    }
}

// Main function
int main()
{
    init_clui();
    int table[SIZE][SIZE];
    get_random_sudoku(table);
    print_sudoku(table);
    play_sudoku(table);
    quit();
    return 0;
}
