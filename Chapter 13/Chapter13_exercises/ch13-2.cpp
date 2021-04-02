#include "Simple_window.h"
#include "Graph.h"

struct Box : Shape
{
	Box(Point p, int ww, int hh, int rr) : w{ww} , h{hh} , r{rr} 
	{ 
		add(p); 
	}
	void draw_lines() const;
private:
	int w;
	int h;
	int r;
};

void Box::draw_lines() const
{
	int xx = point(0).x;
	int yy = point(0).y;

	fl_line(xx+r,yy,xx+w-r,yy);
	fl_line(xx+r,yy+h,xx+w-r,yy+h);

	fl_line(xx,yy+r,xx,yy+h-r);
	fl_line(xx+w,yy+r,xx+w,yy+h-r);

	fl_arc(xx,yy,r*2,r*2,90,180);
	fl_arc(xx+w-r*2,yy,r*2,r*2,0,90);
	fl_arc(xx,yy+h-r*2,r*2,r*2,180,270);
	fl_arc(xx+w-r*2,yy+h-r*2,r*2,r*2,270,360);
}

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 2"};
	Box b{Point{100,100},100,100,10};
	win.attach(b);
	win.wait_for_button();
	error("bruh");
}