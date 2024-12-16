#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

// Draw Koch curve recursively
void drawKoch(int x1, int y1, int x2, int y2, int depth)
{
	if (depth == 0) {
		line(x1, y1, x2, y2); // Base case: Draw line
	} else {
		// Calculate the points dividing the line into three equal parts
		int x3 = (2 * x1 + x2) / 3;
		int y3 = (2 * y1 + y2) / 3;
		int x4 = (x1 + 2 * x2) / 3;
		int y4 = (y1 + 2 * y2) / 3;

		// Calculate the peak of the triangle
		double angle = M_PI / 3; // 60 degrees in radians
		int x5 = x3 + (x4 - x3) * cos(angle) - (y4 - y3) * sin(angle);
		int y5 = y3 + (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);

		drawKoch(x1, y1, x3, y3, depth - 1);
		drawKoch(x3, y3, x5, y5, depth - 1);
		drawKoch(x5, y5, x4, y4, depth - 1);
		drawKoch(x4, y4, x2, y2, depth - 1);
	}
}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	int x1 = 100, y1 = 300, x2 = 500, y2 = 300;
	int depth;

	cout << "Enter depth of Koch curve: ";
	cin >> depth;

	drawKoch(x1, y1, x2, y2, depth);

	delay(40000);
	closegraph();

	return 0;
}
