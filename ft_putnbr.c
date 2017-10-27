#include "sudoku.h"
#include <unistd.h>

void		ft_putnbr(int nb);


void		ft_putnbr(int nb)
{
	int i;
	char array[10];

	i = 0;
	if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
	if (nb == 0)
		{
			ft_putchar(48);
		}
	while (nb > 0)
		{
			array[i] = nb % 10;
			i++;
			nb /= 10;
		}
	while (i > 0)
		{
			i--;
			ft_putchar(array[i] + 48);
		}
}
