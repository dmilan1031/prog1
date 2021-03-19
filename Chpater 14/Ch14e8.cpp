#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

struct Octagon : Shape
{
	Octagon(Point xy, int ww) : w{ww} //A nyolcszöget körbehatároló négyzet bal felső sarka és a négyzet oldalhossza
	{
		int xo = xy.x+ww/2; //a nyolcszög középpontja
		int yo = xy.y+ww/2;
		double phi = atan(1); //45° szög radiánban
		for(int i = 0; i < 8; i++)
		{
			Point p;
			p.x = (int)(xo + (ww/2)*cos(i*phi));
			p.y = (int)(yo + (ww/2)*sin(i*phi));
			add(p);
		}
	}
	void draw_lines() const;
	int width() const {return w;}
private:
	int w;
};

void Octagon::draw_lines() const //hasonlóan a Closed_polyline::draw_lines() -hoz
{
	if(color().visibility())
	{
		for(int i = 0; i < 7; i++) fl_line(point(i).x,point(i).y,point(i+1).x,point(i+1).y);
		fl_line(point(0).x,point(0).y,point(7).x,point(7).y);
	}
	
}

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 8"};
	Octagon o {Point{100,100},100};
	o.set_style(Line_style{Line_style::dash,3});
	o.move(50,50);
	win.attach(o);
	win.wait_for_button();
}
