#include <unistd.h>
#include "sudoku.h"

void		ft_putchar(char c);
void		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
		}
        ft_putchar('\n');
}
