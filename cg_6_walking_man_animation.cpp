#include <graphics.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Base class for drawable objects
class Drawable
{
  public:
	virtual void draw(int xOffset) = 0; // Pure virtual function for drawing
	virtual ~Drawable() {}
};

// Class for the man
class Man : public Drawable
{
  public:
	void draw(int xOffset) override {
		// Draw the ground
		line(0, 400, 639, 400);

		// Head
		circle(30 + xOffset, 280, 20);

		// Body
		line(30 + xOffset, 300, 30 + xOffset, 350);

		// Arms
		line(30 + xOffset, 330, 70 + xOffset, 330);

		// Legs (alternate for animation)
		if (xOffset % 2 == 0) {
			line(30 + xOffset, 350, 25 + xOffset, 400); // Left leg
			line(30 + xOffset, 350, 10 + xOffset, 400); // Right leg
		} else {
			line(30 + xOffset, 350, 35 + xOffset, 400); // Left leg
			line(30 + xOffset, 350, 50 + xOffset, 400); // Right leg
		}

		/*
		if ((xOffset / 5) % 2 == 0) {
			line(30 + xOffset, 350, 25 + xOffset, 400); // Left leg
			line(30 + xOffset, 350, 45 + xOffset, 400); // Right leg
		} else {
			line(30 + xOffset, 350, 15 + xOffset, 400); // Left leg
			line(30 + xOffset, 350, 35 + xOffset, 400); // Right leg
		}
		*/

		// Umbrella handle
		line(70 + xOffset, 250, 70 + xOffset, 330);

		// Umbrella top
		pieslice(70 + xOffset, 250, 0, 180, 40);
	}
};

// Class for the rain
class Rain : public Drawable 
{
  public:
	void draw(int xOffset) override {
		for (int i = 0; i < 100; i++) {
			int x = rand() % 640;
			int y = rand() % 400;
			line(x, y, x + 2, y + 10); // Draw raindrop
		}
	}
};

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	srand(time(0)); // Seed for random rain

	Man man;
	Rain rain;

	for (int xOffset = 0; xOffset < 200; xOffset += 5) {
		rain.draw(0); // Draw rain
		man.draw(xOffset); // Draw man with offset
		delay(100);
		cleardevice(); // Clear screen for the next frame
	}

	getch();
	closegraph();

	return 0;
}
