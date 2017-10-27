#include "sudoku.h"

int     check_value_columns(int k, int j, char **grille)
{
    int i;

    i = 0;
    while (i < 9)
    {
        if (grille[i][j] == k + 48)
            return (0);
        i++;
    }
    return (1);
}
