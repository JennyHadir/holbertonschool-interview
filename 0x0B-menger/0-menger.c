#include "menger.h"
/**
* menger - draws a 2D Menger Sponge
* @level: level of the Menger Sponge to draw
* return - nothing
**/
void menger(int level)
{
	int i, j, level_size, x, y;
	char c;

	if (level < 0)
		return;

	level_size = pow(3, level);
	for (i = 0; i < level_size; i++)
	{
		for (j = 0; j < level_size; j++)
		{
			c = '#';
			x = i;
			y = j;
			while (x > 0 || y > 0)
			{
				if ((x % 3 == 1) && (y % 3 == 1))
				{
					c = ' ';
				}
				x /= 3;
				y /= 3;
			}
			printf("%c", c);
		}
		printf("\n");
	}
}
