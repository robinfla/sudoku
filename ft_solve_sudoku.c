#include <string.h>
#include <stdio.h>
#include "sudoku.h"

int         count_numbers(char **grille)
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

int         ft_place(int i, int j, char **grille)
{
    int k;
    /* int i; */
    /* int j; */

    /* i = p / 9; */
    /* j = p % 9; */
    if (i == 9 && j == 0) {
        /* int d = 1; */
        /* while (++d < 10) */
        /* { */
        /*     puts(grille[d]); */
        /* } */
        return (1);
    }
    if (grille[i][j] != '.')
    {
        /* ft_place(p + 1, grille); */
        return(j < 9 ? ft_place(i, j + 1, grille) : ft_place(i + 1, 0, grille));
    }
    k = 1;
    while (k < 10)
    {
        if (CVB(k, i, j, grille) && CVC(k, j, grille) && CVL (k, i, grille))
        {
            grille[i][j] = k + 48;
            if (j < 9 ? ft_place(i, j + 1, grille) : ft_place(i + 1, 0, grille))
                /* if (ft_place(p + 1, grille)) */
                return(1);
            grille[i][j] = '.';
        }
        k++;
    }
    return (0);
}

char       **ft_solve_sudoku(int argc, char ** argv)
{
    int i;
    char str[] = "Erreur";

    i = -1;
    if (verif_grille(argc, argv) == 0)
    {
        while (str[i++])
            ft_putchar(str[i]);
        ft_putchar('\n');
        return (0);
    }
    ft_place(0, 0, argv);
    return (argv);

}

int         main(int argc, char **argv)
{
    int i;

    i = 1;
    ft_solve_sudoku(argc, argv + 1);
    while (i < 10)
    {
        puts(argv[i]);
        i++;
    }
    return (0);
}
