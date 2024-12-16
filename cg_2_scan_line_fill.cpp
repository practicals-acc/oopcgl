#include <graphics.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent a point
struct Point
{
	int x, y;
};

// Function to fill a concave polygon using the scan-fill algorithm
void scanFill(const vector<Point>& points, int fillColor)
{
	// Find the minimum and maximum y-values of the polygon
	int ymin = points[0].y, ymax = points[0].y;
	for (size_t i = 0; i < points.size(); i++) {
		if (points[i].y < ymin) ymin = points[i].y;
		if (points[i].y > ymax) ymax = points[i].y;
	}

	// Scan line by line
	for (int y = ymin; y <= ymax; y++) {
		vector<int> intersections;

		// Find intersections with polygon edges
		for (size_t i = 0; i < points.size(); i++) {
			Point p1 = points[i];
			Point p2 = points[(i + 1) % points.size()]; // Next point (wrapping around)

			if (p1.y == p2.y) continue; // Skip horizontal edges

			if ((y >= p1.y && y < p2.y) || (y >= p2.y && y < p1.y)) {
				int x = p1.x + (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);
				intersections.push_back(x);
			}
		}

		// Sort intersections by x-coordinate
		sort(intersections.begin(), intersections.end());

		// Fill between pairs of intersections
		setcolor(fillColor); // Set fill color
		for (size_t i = 0; i < intersections.size(); i += 2) {
			if (i + 1 < intersections.size()) {
				line(intersections[i], y, intersections[i + 1], y);
			}
			delay(100);
		}
	}

}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	// Define the points of the concave polygon
	vector<Point> polygon;
	/* Predefined
	polygon.push_back({200, 150});
	polygon.push_back({300, 100});
	polygon.push_back({400, 150});
	polygon.push_back({350, 250});
	polygon.push_back({250, 250});
	*/

	int n;
	cout << "Enter the number of vertices: ";
	cin >> n;

	cout << "Enter the coordinates of the vertices:\n";
	for (int i = 0; i < n; i++) {
		cout << "Vertex " << i + 1 << ": ";
		Point p;
		cin >> p.x >> p.y;
		polygon.push_back(p);
	}

	// Draw the outline of the polygon
	for (size_t i = 0; i < polygon.size(); i++) {
		line(polygon[i].x, polygon[i].y, polygon[(i + 1) % polygon.size()].x, polygon[(i + 1) % polygon.size()].y);
	}

	// Fill the polygon with the desired color
	scanFill(polygon, GREEN);

	getch();
	closegraph();

	return 0;
}
