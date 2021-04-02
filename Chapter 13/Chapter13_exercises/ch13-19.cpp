#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

struct Star : Shape
{
	Star(Point c, int rr, int nn) : n{nn} , r{rr} 
	{ 
		if(nn < 3) error("Túl kevés pont a Star megadásában");
		add(c);
	};
	void draw_lines()const;
	int count() const { return n; }
	int radius() const { return r; }
private:
	int r;
	int n;
};

void Star::draw_lines() const
{
	int cx = point(0).x;
	int cy = point(0).y;

	double a = (M_PI)/count();
	int r = radius();

	if(fill_color().visibility())
	{
		fl_color(fill_color().as_int());
		fl_begin_complex_polygon();
		for(int i = 0; i < count()*2; i++)
		{
			int xx = (int)(r * cos(i*a) * ((i%2==1) ? 0.5 : 1)) ;
			int yy = (int)(r * sin(i*a) * ((i%2==1) ? 0.5 : 1)) ;

			fl_vertex(cx+xx,cy+yy);
		}
		fl_end_complex_polygon();
	}

	if(color().visibility())
	{
		fl_color(color().as_int());
		for(int i = 0; i < count()*2; i++)
		{
			int x1 = (int)(r * cos(i*a) * ((i%2==1) ? 0.5 : 1)) ;
			int y1 = (int)(r * sin(i*a) * ((i%2==1) ? 0.5 : 1)) ;

			int x2 = (int)(r * cos((i+1)*a) * ((i%2==0) ? 0.5 : 1)) ;
			int y2 = (int)(r * sin((i+1)*a) * ((i%2==0) ? 0.5 : 1)) ;

			fl_line(cx+x1,cy+y1,cx+x2,cy+y2);
		}
	}
}

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 19"};
	Star s{Point{300,300},100,11};
	Star s2{Point{150,150},100,7};
	s.set_fill_color(Color::red);
	s2.set_color(Color::red);
	s2.set_fill_color(Color::black);
	s2.set_style(Line_style{Line_style::dash,4});
	win.attach(s);
	win.attach(s2);
	win.wait_for_button();
}