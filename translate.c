
#include "bsq.h"

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
    int x;
	int y;
	int i;
	int j;
	
	x = square->x;
	y = square->y;
	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
            ft_get_char(grid[i][j], square);
            if (j == x - 1)
                write(1, "\n", 1);
		}
	}
}