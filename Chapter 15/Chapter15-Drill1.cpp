#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Simple_window win{Point{100,100},600,600,"Chapter 15 Drill"};


	Axis ax{Axis::x,Point{100,300},400,20,"1 == 20 pixels"};
	Axis ay{Axis::y,Point{300,500},400,20,"1 == 20 pixels"};

	ax.set_color(Color::red);
	ay.set_color(Color::red);

	ax.label.set_color(Color::black);
	ay.label.set_color(Color::black);

	win.attach(ax);
	win.attach(ay);

	win.wait_for_button();
}