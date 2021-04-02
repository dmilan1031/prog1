#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

struct Regular_hexagon : Shape
{
	Regular_hexagon(Point c, int rr) : r{rr} { add(c); }
	Regular_hexagon(Point c, int rr, double p) : r{rr} , phs{p} { add(c); }
	void draw_lines() const;
	void set_radius(int rr) { r = rr; }
	void set_phase(double p) { phs = p; }
	int radius() const { return r; }
	double phase() const { return phs; }
private:
	int r;
	double phs = 0;
};

void Regular_hexagon::draw_lines() const
{
	int xx = point(0).x;
	int yy = point(0).y;
	double a = M_PI/3; //30 fokos szög radiánban
	for(int i = 0; i < 6; i++)
	{
		fl_line(
			xx+radius()*cos(a*i+phase()),
			yy+radius()*sin(a*i+phase()),
			xx+radius()*cos(a*(i+1)+phase()),
			yy+radius()*sin(a*(i+1)+phase())
			);
	}
}

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 6"};
	Regular_hexagon h1 {Point{200,200},100};
	Regular_hexagon h2 {Point{300,300},100, 0.2};
	win.attach(h1);
	win.attach(h2);
	win.wait_for_button();
}