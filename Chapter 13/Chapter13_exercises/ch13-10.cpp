#include "Simple_window.h"
#include "Graph.h"

struct Regular_polygon :Shape
{
	Regular_polygon(Point c, int nn, int rr) : n{nn} , r{rr} { add(c); }
	void set_radius(int rr) { r = rr; }
	int radius() const { return r; }
	void draw_lines() const;
	int count() const {return n; }
	void set_count(int nn) { n = nn; }
private:
	int r;
	int n;
};

const double P = M_PI*2; //360 fok radiánban

void Regular_polygon::draw_lines() const
{
	int xx = point(0).x;
	int yy = point(0).y;
	int r = radius();

	if(fill_color().visibility())
	{
		fl_color(fill_color().as_int());
		fl_begin_complex_polygon();
		for(int i = 0; i < count(); i++)
		{
			fl_vertex
			(
				xx+r*cos(i*P/count()),
				yy+r*sin(i*P/count())
			);
		}
		fl_end_complex_polygon();
	}

	if(color().visibility())
	{
		fl_color(color().as_int());
		for(int i = 0; i < count(); i++)
		{
			fl_line
			(
				xx+r*cos(i*P/count()),
				yy+r*sin(i*P/count()),
				xx+r*cos((i+1)*P/count()),
				yy+r*sin((i+1)*P/count())
			);
		}
	}
}

int main()
{
	Simple_window win{ Point{100,100},500,500,"Exercise 10"};

	Regular_polygon p1 {Point{200,200},7,100};
	p1.set_fill_color(Color::green);
	p1.set_color(Color::invisible);
	win.attach(p1);
	
	win.wait_for_button();
}