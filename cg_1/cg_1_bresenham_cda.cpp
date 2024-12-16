#include <graphics.h>

void plot_circle_symmetry(int xc, int yc, int x, int y)
{
	putpixel(xc + x, yc + y, WHITE); // Octant 1
	putpixel(xc - x, yc + y, WHITE); // Octant 2
	putpixel(xc + x, yc - y, WHITE); // Octant 8
	putpixel(xc - x, yc - y, WHITE); // Octant 7
	putpixel(xc + y, yc + x, WHITE); // Octant 3
	putpixel(xc - y, yc + x, WHITE); // Octant 4
	putpixel(xc + y, yc - x, WHITE); // Octant 6
	putpixel(xc - y, yc - x, WHITE); // Octant 5
}

void bresenham_cda(int xc, int yc, int r)
{
	int xi = 0, yi = r;
	int dp = 3 - 2 * r;
	while (xi <= yi) {
		plot_circle_symmetry(xc, yc, xi, yi);
		if (dp < 0) {
			dp = dp + 4 * xi + 6;
		} else {
			dp = dp + 4 * (xi - yi) + 10;
			// update y after calculating the next dp using old x,y
			yi--;
		}
		// update x after calculating the next dp using old x,y
		xi++;
		delay(20);
	}
}

int main()
{
	int gd = DETECT;
	int gm;
	initgraph(&gd, &gm, NULL);

	bresenham_cda(100, 100, 60);

	delay(60000);
	closegraph();
	return 0;
}
