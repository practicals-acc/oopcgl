#include <iostream>
#include <graphics.h>
#include <cmath>

void dda_lda(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;

	int step = (std::abs(dx) >= std::abs(dy) ? std::abs(dx) : std::abs(dy));
	/* OR
	if (std::abs(dx) >= std::abs(dy)) {
		step = std::abs(dx);
	} else {
		step = std::abs(dy);
	}
	*/

	float xinc = dx / (float) step;
	float yinc = dy / (float) step;
	/* Using slope to calculate xinc and yinc
	float slope = dy / dx;
	if (slope <= 1) {
		// when dx >= dy (theta or angle of line less than or equal to 45 degrees)
		xinc = dx;
		yinc = slope;
	} else if (slope > 1) {
		// when dx < dy (theta or angle of line greater than 45 degrees)
		xinc = 1/slope;
		yinc = dy;
	}
	*/


	float xi = x1, yi = y1;
	for (int i = 0; i < step; i++) {
		putpixel(std::round(xi), std::round(yi), WHITE);
		// OR (plot point or display (x, y) values of each point with and without rounding)
		// std::cout << "Point " << (i + 1) << ": " << std::round(xi) << ", " << std::round(yi) << std::endl;
		// std::cout << "Point " << (i + 1) << ": " << xi << ", " << yi << std::endl;
		xi += xinc;
		yi += yinc;
	}
}

/*
int main()
{
	int gd = DETECT;
	int gm;

	initgraph(&gd, &gm, NULL);

	dda_lda(25, 30, 150, 190);

	delay(60000);
	closegraph();
	return 0;
}
*/
