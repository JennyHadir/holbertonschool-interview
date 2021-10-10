#include "menger.h"
/**
* menger - draws a 2D Menger Sponge
* @level: level of the Menger Sponge to draw
* Return: Void
**/
void menger(int level)
{
	int i, j, size, row, col;
	char c;

	if (level >= 0)
    {
        size = pow(3, level);
	    for (i = 0; i < level_size; i++)
	    {
		    for (j = 0; j < level_size; j++)
		    {
			    c = '#';
			    row = i;
			    col = j;
			    while (row != 0 || col != 0)
			    {
				    if ((row % 3 == 1) && (col % 3 == 1))
				    {
					    c = ' ';
				    }
				    row /= 3;
				    col /= 3;
			    }
			    printf("%c", c);
		    }
		    printf("\n");
	    }
    }
}