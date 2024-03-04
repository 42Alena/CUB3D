#include <stdio.h>

void	bresenham(int x1, int y1, int x2, int y2)
{
	int m_new = 2 * (y2 - y1);
	int slope_error_new = m_new - (x2 - x1);
	for (int x = x1, y = y1; x <= x2; x++)
	{
		printf("(%d, %d)\n", x, y);
		slope_error_new += m_new;
		if (slope_error_new >= 0)
		{
			y++;
			slope_error_new -= 2 * (x2 - x1);
		}
	}
}

int	main()
{
	int x1 = 3, y1 = 2, x2 = 15, y2 = 5;

	bresenham(x1, y1, x2, y2);
}