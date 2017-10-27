#ifndef __FT_SUDOKU_H__
# define __FT_SUDOKU_H__

# define CVB(x, y, z, w) (check_value_bloc(x, y, z, w) == 1)
# define CVL(x, y, w) (check_value_lines(x, y, w) == 1)
# define CVC(x, z, w) (check_value_columns(x, z, w) == 1)

int     check_value_bloc(int k, int i, int j, char **grille);
int     ft_strlen(char *str);
void    ft_putnbr(int nb);
void    ft_putchar(char c);
int     verif_grille(int argc, char **argv);
int     check_value_columns(int k, int j, char **grille);
int     check_value_lines(int k, int i, char **grille);
#endif
