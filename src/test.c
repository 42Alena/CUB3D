#include <math.h>
#include <stdio.h>
int main()
{

	char	map[50][50] = {{1,1,1,1,1},\
						{1,0,0,0,1},\
						{1,0,0,0,1},\
						{1,2,0,0,1},\
						{1,1,1,1,1}};
	double posX = 1.5, posY = 1.5;  //x and y start position
	double dirX = 0, dirY = 1; //initial direction vector
	double planeX = 0, planeY = 0.1; //the 2d raycaster version of camera plane
	for(int x = 0, w = 1; x < w; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / w - 1; //x-coordinate in camera space
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)posX;
		int mapY = (int)posY;
		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		printf("%f camera %f raydirY %f deltaY\n", cameraX, rayDirY, deltaDistY);
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		printf("sideY:%f sideX:%f\n", sideDistY, sideDistX);
		//perform DDA
		while(hit == 0)
		{
			printf("%d\n", hit);
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				printf("side:%f\n", sideDistY);
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(map[mapX][mapY] > 0) hit = 1;
		}
	}
}