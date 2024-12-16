#include <graphics.h>
#include <cmath>

class GraphicsDrawer
{
  private:
	int gd, gm, color;
	void plot_circle_symmetry(int xc, int yc, int x, int y)
	{
		putpixel(xc + x, yc + y, color); // Octant 1
		putpixel(xc - x, yc + y, color); // Octant 2
		putpixel(xc + x, yc - y, color); // Octant 8
		putpixel(xc - x, yc - y, color); // Octant 7
		putpixel(xc + y, yc + x, color); // Octant 3
		putpixel(xc - y, yc + x, color); // Octant 4
		putpixel(xc + y, yc - x, color); // Octant 6
		putpixel(xc - y, yc - x, color); // Octant 5		
	}

  public:
	GraphicsDrawer()
	{
		gd = DETECT;
		initgraph(&gd, &gm, NULL);
		color = WHITE;
	}

	void setcolor(int c)
	{
		color = c;
	}

	void pause(int ms)
	{
		delay(ms);
	}

	void dda_lda(int x1, int y1, int x2, int y2)
	{
		int dx = x2 - x1;
		int dy = y2 - y1;

		int step = (std::abs(dx) >= std::abs(dy) ? std::abs(dx) : std::abs(dy));

		float xinc = dx / (float) step;
		float yinc = dy / (float) step;

		float xi = x1, yi = y1;
		for (int i = 0; i < step; i++) {
			putpixel(std::round(xi), std::round(yi), color);
			xi += xinc;
			yi += yinc;
		}
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
		}
	}

	~GraphicsDrawer()
	{
		closegraph();
	}
};

int main()
{
	GraphicsDrawer gd;
	gd.setcolor(CYAN);
	gd.dda_lda(10, 10, 410, 10);
	gd.dda_lda(10, 210, 410, 210);
	gd.dda_lda(10, 10, 10, 210);
	gd.dda_lda(410, 10, 410, 210);

	gd.dda_lda(210, 10, 10, 110);
	gd.dda_lda(210, 10, 410, 110);
	gd.dda_lda(10, 110, 210, 210);
	gd.dda_lda(410, 110, 210, 210);

	gd.bresenham_cda(210, 110, 80);
	
	gd.pause(10000);
	return 0;
}
