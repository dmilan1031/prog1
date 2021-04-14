#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
try
{
	Simple_window win {Point{100,100},600,400,"Canvas"};

	Axis xa{Axis::x,Point{20,300},280,10,"x axis"};
	win.attach(xa);
	xa.set_color(Color::red);
	win.set_label("Canvas 2");
	win.wait_for_button();

	Axis ya{Axis::y,Point{20,300},280,10,"y axis"};
	win.attach(ya);
	ya.set_color(Color::blue);
	ya.label.set_color(Color::dark_red);
	win.set_label("Canvas 3");
	win.wait_for_button();

	Function sine{sin,0,100,Point{20,150},1000,50,50};
	win.attach(sine);
	sine.set_style({Line_style::dash,3});
	sine.set_color(Color::dark_blue);
	win.set_label("Canvas 4");
	win.wait_for_button();

	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	win.attach(poly);
	poly.set_color(Color::red);
	poly.set_fill_color(Color::white);
	win.set_label("Canvas 5");
	win.wait_for_button();

	Rectangle r{Point{200,200},100,50};
	win.attach(r);
	r.set_fill_color(Color::dark_blue);
	win.set_label("Canvas 6");
	win.wait_for_button();

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});
	poly_rect.set_fill_color(Color::yellow);
	win.attach(poly_rect);
	win.set_label("Canvas 7");
	win.wait_for_button();

	Text t {Point{150,150}, "Hello, graphical world!"};
	win.attach(t);
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.set_label("Canvas 8");
	win.wait_for_button();

	Image ii {Point{100,50},"tree200.jpg"};
	win.attach(ii);
	ii.move(200,200);
	win.set_label("Canvas 9");
	win.wait_for_button();

	Circle c{Point{100,200},50};
	Ellipse e{Point{100,200},75,25};
	e.set_color(Color::dark_red);
	Mark m {Point{100,200},'x'};
	win.attach(c);
	win.attach(e);
	win.attach(m);
	win.set_label("Canvas 10");
	win.wait_for_button();
}
catch(exception& e)
{
	std::cout << "error: " << e.what();
	return 1;
}
catch(...)
{
	return 2;
}