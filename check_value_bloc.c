#include "sudoku.h"

int     check_value_bloc(int k, int i, int j, char **grille)
{
    int y;
    int z;
    int y2;
    int z2;

    y = i - (i % 3);
    y2 = y;
    z = j - (j % 3);
    z2 = z;
    while (y < y2 + 3)
    {
        z = z2;
        while (z < z2 + 3)
        {
            if (grille[y][z] == k + 48)
                return (0);
            z++;
        }
        y++;
    }
    return (1);
}
