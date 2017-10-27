#include "sudoku.h"

int     check_value_lines(int k, int i, char **grille)
{
    int j;

    j = 0;
    while (j < 9)
    {
        if (grille[i][j] == k + 48)
            return (0);
        j++;
    }
    return (1);
}
