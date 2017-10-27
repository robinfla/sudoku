#include "sudoku.h"

int     verif_numbers(char **grille)
{
    int i;
    int j;

    i = 0;
    while (i < 9)
    {
        j = 0;
        while (j < 9)
        {
            if (grille[i][j] != '.' && (grille[i][j] < 49 || grille[i][j] > 57))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int     verif_duplicates_lines(char **grille)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (i < 9)
    {
        int str[256] = {0};
        j = 0;
        while (j < 9)
        {
            if (grille[i][j] != '.')
            {
                if (str[(int)grille[i][j]] == 0)
                    str[(int)grille[i][j]] = 1;
                else
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

int     verif_duplicates_columns(char **grille)
{
    int i;
    int j;
    int k; 

    i = 0;
    while (i < 9)
    {
        j = 0;
        while (j < 9)
        {
            if (grille[i][j] != '.')
            {
                k = 1;
                while (i + k < 9)
                {
                    if (grille[i][j] == grille[i + k][j])
                        return (0);
                    else
                        k++;
                }
            }
            j++;
        }
        i++;
    }
    return (1);
}

int     verif_count_clues(char **grille)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (grille[i])
    {
        j = 0;
        while (grille[i][j])
        {
            if (grille[i][j] > 48 && grille[i][j] < 58)
                count ++;
            j++;
        }
        i++;
    }
    return (count);
}

int     verif_bloc(char **grille)
{
    int i;
    int j;
    int p;
    int k;

    k = 0;
    p = 0;
    i = p / 9;
    j = p % 9;
    while (p < 81)
    {
        k = grille[i][j] - 48;
        grille[i][j] = '.';
        if (check_value_bloc(k, i, j, grille) == 0)
            return (0);
        grille[i][j] = k + 48;
        p ++;
    }
    return (1);
}

int    verif_grille(int ac, char **av)
{
    int i;

    i = 0;
    if (ac != 10)
        return (0);
    while (i < 9)
    {
        if (ft_strlen(av[i]) < 9)
            return (0);
        i++;
    }
    if (verif_numbers(av) == 0 || verif_count_clues(av) < 17)
        return (0);
    if (verif_duplicates_lines(av) == 0 || verif_duplicates_columns(av) == 0)
        return (0);
    if (verif_bloc(av) == 0)
        return (0);
    return (1);
}
