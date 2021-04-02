#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x)+slope(x); }

int main()
{
	constexpr double r1 = -10; //a Function paraméterei
	constexpr double r2 = 11;
	const Point origin {300,300};
	constexpr double scale = 20;
	constexpr int num = 400;

	const int xspace = origin.x+int(r1*scale); //a grafikon körüli margó
	constexpr int yspace = 100;

	constexpr int xlength = int((r2-r1)*scale); //a tengelyek hossza
	constexpr int ylength = 400;

	const int xmax = xlength + 2 * xspace; //az ablak méretei
	constexpr int ymax = ylength + 2 * yspace;

	Simple_window win{Point{100,100},xmax,ymax,"Chapter 15 Drill"};

	Axis ax{Axis::x, Point {origin.x+int(r1*scale), origin.y}, 	xlength, xlength/int(scale), "x"};
	Axis ay{Axis::y, Point {origin.y, ymax-yspace}, 			ylength, ylength/int(scale), "y"};

	//////////

	Function f1 {one, r1,r2, origin, num, scale,scale};

	Function f2 {slope, r1,r2, origin, num, scale,scale};
	Text tx {Point{xspace,380},"x/2"};

	Function f3 {square, r1,r2, origin, num, scale,scale};

	Function f4 {cos, r1,r2, origin, num, scale,scale};
	f4.set_color(Color::blue);

	Function f5 {sloping_cos, r1,r2, origin, num, scale,scale};

	win.attach(ax);
	win.attach(ay);

	win.attach(f1);
	win.attach(f2);
	win.attach(f3);
	win.attach(f4);
	win.attach(f5);

	win.attach(tx);

	win.wait_for_button();
}