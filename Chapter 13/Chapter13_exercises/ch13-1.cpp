#include "Simple_window.h"
#include "Graph.h"

struct Arc : Shape
{
	Arc(Point p, int ww, int hh, int ss, int ee) : w{ww} , h{hh} , start{ss}, end{ee} { add(p); }
	void draw_lines() const;
	void set_width(int ww) { w = ww; }
	void set_height(int hh) { h = hh; }
	int width() { return w; }
	int height() { return h; }
	void set_interval( int ss, int ee ) { start = ss; end = ee; }
private:
	int w;
	int h;
	int start;
	int end;
};

void Arc::draw_lines() const
{
	if(fill_color().visibility())
	{
		fl_color(fill_color().as_int());
		fl_pie(point(0).x,point(0).y,w,h,start,end);
	}

	if(color().visibility())
	{
		fl_color(color().as_int());
		fl_arc(point(0).x,point(0).y,w,h,start,end);
	}
}

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 1"};
	Arc a {Point{100,100},100,100,0,300};
	Arc b {Point{300,200},30,100,0,300};

	a.set_fill_color(Color::green);
	a.set_style(Line_style{Line_style::dash,5});

	b.set_fill_color(Color::white);
	b.set_style(Line_style{Line_style::dot,2});

	win.attach(a);
	win.attach(b);

	win.wait_for_button();
}