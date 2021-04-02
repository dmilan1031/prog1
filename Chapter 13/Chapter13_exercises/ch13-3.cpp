#include "Simple_window.h"
#include "Graph.h"

struct Arrow : Shape
{
	Arrow(Point p1, Point p2, float qq = 0.1f) //a nyíl p1-ből megy p2-be
	{										//a nyíl feje qq szerint aránylik a nyíl hosszához
		add(p1);
		add(p2);

		int v1x = p2.x-p1.x; //p1-ből p2-be mutató vektor
		int v1y = p2.y-p1.y;
	
		int v2x = v1y; //v1 merőlegese
		int v2y = -v1x;

		add(Point
			{
				int(p2.x - float(v1x)*qq + float(v2x)*qq/2), //a nyíl "éleinek" hozzáadása a Shape-hez
				int(p2.y - float(v1y)*qq + float(v2y)*qq/2) 
			});

		add(Point
			{
				int(p2.x - float(v1x)*qq - float(v2x)*qq/2),
				int(p2.y - float(v1y)*qq - float(v2y)*qq/2) 
			});
	}
	void draw_lines() const;
private:
	float q;
};

void Arrow::draw_lines() const
{
	if(color().visibility())
	{
		fl_line(point(0).x,point(0).y,point(1).x,point(1).y);
		fl_line(point(1).x,point(1).y,point(2).x,point(2).y);
		fl_line(point(1).x,point(1).y,point(3).x,point(3).y);
	}
}


int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 3"};

	Arrow a1 {Point{100,100},Point{300,300},0.3f};
	a1.set_style(Line_style{Line_style::dot,6});
	a1.set_color(Color::blue);

	Arrow a2 {Point{100,300},Point{400,100},0.1f};
	a2.set_style(Line_style{Line_style::solid,4});
	a2.set_color(Color::green);

	win.attach(a1);
	win.attach(a2);
	win.wait_for_button();
}