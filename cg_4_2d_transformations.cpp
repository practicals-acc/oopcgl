#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

class Point
{
  public:
	float x, y, w;

	Point(float x = 0, float y = 0) : x(x), y(y), w(1) {}

	// Overload the multiplication operator for matrix transformations
	Point operator*(float mat[3][3]) {
		float result[3] = {0};
		float coords[3] = {x, y, w};

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				result[i] += coords[j] * mat[i][j];
			}
		}

		return Point(result[0], result[1]);
	}

	void draw(Point p)
	{
		line(x, y, p.x, p.y);
	}
};

void drawPolygon(Point points[], int n)
{
	for (int i = 0; i < n; i++) {
		points[i].draw(points[(i + 1) % n]);
	}
}

void transform(Point points[], int n, float mat[3][3])
{
	for (int i = 0; i < n; i++) {
		points[i] = points[i] * mat;
	}
}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	int n;
	cout << "Enter the number of vertices: ";
	cin >> n;
	Point points[n];

	cout << "Enter the coordinates of the vertices:\n";
	for (int i = 0; i < n; i++) {
		cout << "Vertex " << i + 1 << ": ";
		cin >> points[i].x >> points[i].y;
	}

	while (true) {
		cleardevice();
		drawPolygon(points, n);

		cout << "\nTransformations:\n1. Translate\n2. Scale\n3. Rotate\n4. Exit\nEnter your choice: ";
		int choice;
		cin >> choice;

		if (choice == 4) break;

		float mat[3][3] = {{0}};
		mat[0][0] = mat[1][1] = mat[2][2] = 1; // Make identity matrix
		switch (choice) {
			case 1: {
				float tx, ty;
				cout << "Enter translation factors (tx, ty): ";
				cin >> tx >> ty;
				mat[0][2] = tx;
				mat[1][2] = ty;
				break;
			}
			case 2: {
				float sx, sy;
				cout << "Enter scaling factors (sx, sy): ";
				cin >> sx >> sy;

				mat[0][0] = sx;
				mat[1][1] = sy;
				break;
			}
			case 3: {
				float angle;
				cout << "Enter rotation angle (in degrees): ";
				cin >> angle;

				float cosTheta = cos(angle * M_PI / 180.0); // Radians conversion
				float sinTheta = sin(angle * M_PI / 180.0);

				mat[0][0] = cosTheta;
				mat[0][1] = sinTheta;
				mat[1][0] = -sinTheta; // Anti-clockwise (row-major)
				mat[1][1] = cosTheta;
				break;
			}
			default:
				cout << "Invalid choice!\n";
				continue;
		}
		transform(points, n, mat);
	}

	closegraph();
	return 0;
}
