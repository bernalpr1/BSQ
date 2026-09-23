
#include "../includes/bsq.h"

void    ft_get_char (int num, t_square *square)
{
    char    c;

    if (num == -1)
        c = square->ful;
    else if (num == 0)
        c = square->obs;
    else
    	c = square->emp;
    write (1, &c, 1);
}
void    ft_translater(int **grid, t_square *square)
{
    	int i;
	int j;
	
	i = -1;
	while (++i < square->y)
	{
		j = -1;
		while (++j < square->x)
            		ft_get_char(grid[i][j], square);
                write(1, "\n", 1);
	}
}
