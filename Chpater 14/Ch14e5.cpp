#include "Simple_window.h"
#include "Graph.h"

struct Striped_Rectangle : Rectangle
{
	Striped_Rectangle(Point xy, int w, int h, int space) : Rectangle(xy,h,w), spc{space} { }
	int space() const {return spc;}
	void set_space(int s) {spc = s;};
	void draw_lines() const;
private:
	int spc; //vonalköz
};

void Striped_Rectangle::draw_lines() const
{
	Rectangle::draw_lines();
	for(int i;i<height();i+=spc)
	{
		fl_line(point(0).x,point(0).y+i,point(0).x+width()-1,point(0).y+i);
	}
}

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 5"};
	Striped_Rectangle sr {Point{100,100},200,100,5};
	win.attach(sr);
	win.wait_for_button();
}
