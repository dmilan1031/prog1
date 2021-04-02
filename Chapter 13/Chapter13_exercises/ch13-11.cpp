#include "Simple_window.h"
#include "Graph.h"

int main()
{
	Simple_window win {Point{100,100},500,400,"Exercise 11"};

	Ellipse e {Point{250,200},150,100}; //Ellipszis
	win.attach(e);

	Axis ax {Axis::x,Point{50,200},400,40,"x"}; //Tengelyek
	win.attach(ax);

	Axis ay {Axis::y,Point{250,350},300,30,"y"};
	win.attach(ay);

	int c = (int)(sqrt(e.major()*e.major()-e.minor()*e.minor())); //Fókuszpontok

	Point f1 { e.center().x+c, e.center().y };
	Point f2 { e.center().x-c, e.center().y };

	Mark m1 { f1, 'F' };
	Mark m2 { f2, 'F' };

	win.attach(m1);
	win.attach(m2);

	int dx = (int)(e.minor()*cos(1)); //Egy pont a minor() sugarú köríven
	int dy = (int)(e.minor()*sin(1));
	dx *= ((float)e.major()/e.minor());	//a kör transzformálása ellipszissé -> a pont az ellipszis felszínén lesz

	Point p { e.center().x+dx , e.center().y+dy };
	Mark mp { p, 'P' };

	win.attach(mp);

	Lines l {f1,p,f2,p}; //Vonalak

	win.attach(l);

	win.wait_for_button();
}