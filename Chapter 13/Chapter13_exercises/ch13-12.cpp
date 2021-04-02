#include "Simple_window.h"
#include "Graph.h"

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 12"};

	Circle c {Point{250,250},200};
	win.attach(c);

	Mark m {Point{450,250},'M'};
	win.attach(m);

	double a = 0;
	double da = 0.1;

	win.wait_for_button();

	while(true)
	{
		a += da;
		int xx = 250 + 200*cos(a);
		int yy = 250 + 200*sin(a);
		m.move(xx-m.point(0).x,yy-m.point(0).y);
		win.wait_for_button();
	}
}