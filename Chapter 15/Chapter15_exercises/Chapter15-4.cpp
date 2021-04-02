#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

int main()
{
	constexpr int xspace = 100;
	constexpr int yspace = 100;
	constexpr int xlength = 400;
	constexpr int ylength = 400;

	constexpr int xmax = xlength+2*xspace;
	constexpr int ymax = ylength+2*yspace;

	const Point orig {xspace+xlength/2,yspace+ylength/2};

	constexpr double scale = 40;
	constexpr double r1 = -(0.5*xlength/scale);
	constexpr double r2 = (0.5*xlength/scale);

	Simple_window win {Point{100,100},xmax,ymax,"Exercise 4"};

	Axis ax {Axis::x, Point{xspace,orig.y}, xlength, xlength/int(scale), "x"};
	Axis ay {Axis::y, Point{orig.x,ymax-yspace}, ylength, ylength/int(scale), "y"};


	Function f1 { sin, r1, r2, orig, 400, scale, scale };
	f1.set_color(Color::red);
	Text t1 { Point{100,100}, "sin(x)" };
	t1.set_color(Color::red);

	Function f2 { cos, r1, r2, orig, 400, scale, scale };
	f2.set_color(Color::blue);
	Text t2 { Point{100,115}, "cos(x)" };
	t2.set_color(Color::blue);

	Function f3 { [](double x){return sin(x)+cos(x);}, r1, r2, orig, 400, scale, scale };
	f3.set_color(Color::green);
	Text t3 { Point{100,130}, "sin(x)+cos(x)" };
	t3.set_color(Color::green);

	Function f4 { [](double x){return sin(x)*sin(x)+cos(x)*cos(x);}, r1, r2, orig, 400, scale, scale };
	Text t4 { Point{100,145}, "sin^2(x)+cos^2(x)" };


	win.attach(ax);
	win.attach(ay);

	win.attach(f1);
	win.attach(t1);
	win.attach(f2);
	win.attach(t2);
	win.attach(f3);
	win.attach(t3);
	win.attach(f4);
	win.attach(t4);

	win.wait_for_button();
}