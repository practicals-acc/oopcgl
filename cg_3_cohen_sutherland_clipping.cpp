#include <iostream>
#include <graphics.h>

// Defining region codes
const int INSIDE = 0;	// 0000
const int LEFT = 1;	// 0001
const int RIGHT = 2;	// 0010
const int BOTTOM = 4;	// 0100
const int TOP = 8;	// 1000

// Defining x_max, y_max and x_min, y_min for clipping rectangle
double x_max, y_max, x_min, y_min;

void draw_window(double xmin, double ymin, double xmax, double ymax)
{
	// Syntax: void rectangle(int left, int top, int right, int bottom);
	rectangle(xmin, ymax, xmax, ymin);
	/* OR
	line(xmin, ymin, xmax, ymin);
	line(xmin, ymax, x_max, y_max);
	line(xmin, ymin, xmin, ymax);
	line(xmax, ymin, xmax, ymax);
	*/
}


// Function to compute region code for a point(x, y)
int computeCode(double x, double y)
{
	// Initialized as being inside (0000)
	int code = INSIDE;

	if (x < x_min)		// to the left of window
		code |= LEFT;
	else if (x > x_max)	// to the right of window
		code |= RIGHT;
	if (y > y_min)		// below the window 
		code |= BOTTOM;
	else if (y < y_max)	// above the window
		code |= TOP;

	return code;
}

void cohenSutherlandClip(double x1, double y1, double x2, double y2)
{
	// Compute region codes for P1, P2
	int code1 = computeCode(x1, y1);
	std::cout << "Initial Region Code for P1: " << code1 << std::endl;
	int code2 = computeCode(x2, y2);
	std::cout << "Initial Region Code for P2: " << code2 << std::endl;

	// Initialize line as outside the window
	bool accept = false;

	while (true)
	{
		if ((code1 == 0) && (code2 == 0)) {
			// If both endpoints lie within rectangle
			accept = true;
			break;
		} else if (code1 & code2) {
			// If both endpoints are outside rectangle, in same region
			std::cout << "Both end points of the line lie outside the window" << std::endl;
			break;
		} else {
			// Some segment of line lies within the window
			int code_out;
			double x, y;

			// At least one endpoint is outside the window, pick it.
			if (code1 != 0)
				code_out = code1;
			else
				code_out = code2;

			// Find intersection point; using formulas:
			// y = y1 + slope * (x - x1)
			// x = x1 + (1 / slope) * (y - y1)
			if (code_out & TOP) {
				// point is above the clip window
				x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
				y = y_max;
			}
			else if (code_out & BOTTOM) {
				// point is below the clip window
				x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
				y = y_min;
			}
			else if (code_out & RIGHT) {
				// point is to the right of the clip window
				y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
				x = x_max;
			}
			else if (code_out & LEFT) {
				// point is to the left of the clip window
				y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
				x = x_min;
			}

			// Intersection point x,y is found, replace point
			// outside window by intersection point
			if (code_out == code1) {
				x1 = x;
				y1 = y;
				code1 = computeCode(x1, y1);
			} else {
				x2 = x;
				y2 = y;
				code2 = computeCode(x2, y2);
			}
		}
	}

	if (accept) {
		std::cout << "Line accepted from " << x1 << ", "
			<< y1 << " to " << x2 << ", " << y2 << std::endl;
		// Here the user can add code to display the rectangle
		// along with the accepted (portion of) lines

		setcolor(WHITE);
		draw_window(x_min, y_min, x_max, y_max);
		setcolor(GREEN);
		line(x1, y1, x2, y2);

	} else {
		std::cout << "Line rejected" << std::endl;
		setcolor(WHITE);
		draw_window(x_min, y_min, x_max, y_max);
		setcolor(RED);
		outtextxy(10, 10, "Line is outside the clipping window!");
	}
}

int main()
{
	int gd = DETECT, gm;

	initgraph (&gd, &gm, NULL);

	std::cout << "Enter the coordinates of the clipping window (xmin, ymin, xmax, ymax): ";
	std::cin >> x_min >> y_min >> x_max >> y_max;

	int x1, y1, x2, y2;
	std::cout << "Enter the coordinates of the line (x1, y1, x2, y2): ";
	std::cin >> x1 >> y1 >> x2 >> y2;

	// Visualize before clipping
	setcolor(WHITE);
	draw_window(x_min, y_min, x_max, y_max);
	setcolor(RED);
	line(x1, y1, x2, y2);
	outtextxy(10, 10, "Before Clipping");
	delay(4000);
	cleardevice();
	
	cohenSutherlandClip(x1, y1, x2, y2);

	delay(50000);
	closegraph();
	return 0;
}
