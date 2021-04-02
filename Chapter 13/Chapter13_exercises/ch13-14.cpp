#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

struct Right_triangle : Shape
{
	Right_triangle(Point p1, Point p2, double qq) : q{qq} //A derékszögű háromszöget az egyik befogójával adjuk meg
	{
		add(p1);
		add(p2);
		add(Point{p2.x+(int)(q*(p1.y-p2.y)),p2.y+(int)(q*(p2.x-p1.x))}); //merőlegest állítunk p2-re
	}
	void draw_lines() const;
private:
	double q; //a második befogó aránya a megadott befogóhoz
};

void Right_triangle::draw_lines() const
{
	if(fill_color().visibility())
	{
		fl_color(fill_color().as_int());
		fl_begin_complex_polygon();
		fl_vertex(point(0).x,point(0).y);
		fl_vertex(point(1).x,point(1).y);
		fl_vertex(point(2).x,point(2).y);
		fl_end_complex_polygon();
	}

	if(color().visibility())
	{
		fl_color(color().as_int());
		fl_line(point(0).x,point(0).y,point(1).x,point(1).y);
		fl_line(point(1).x,point(1).y,point(2).x,point(2).y);
		fl_line(point(2).x,point(2).y,point(0).x,point(0).y);
	}
}

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 14"};

	int a = 300/(2*sqrt(2));
	int sqa = a*sqrt(2);

	Vector_ref<Right_triangle> v;


	v.push_back(new Right_triangle{Point{100,100+sqa/2+sqa},Point{100,100+sqa/2},2});
	v[v.size()-1].set_fill_color(Color::green);

	v.push_back(new Right_triangle{Point{400,100+sqa/2},Point{400,100+sqa/2+sqa},2});
	v[v.size()-1].set_fill_color(Color::dark_green);



	v.push_back(new Right_triangle{Point{100,100+sqa/2},Point{100+sqa/2,100},1});
	v[v.size()-1].set_fill_color(Color::cyan);

	v.push_back(new Right_triangle{Point{100+sqa,100+sqa/2},Point{100+sqa+sqa/2,100},1});
	v[v.size()-1].set_fill_color(Color::cyan);

	v.push_back(new Right_triangle{Point{100+sqa/2,100+2*sqa},Point{100+sqa,100+sqa+sqa/2},1});
	v[v.size()-1].set_fill_color(Color::cyan);



	v.push_back(new Right_triangle{Point{100+sqa+sqa/2,100},Point{100+sqa,100+sqa/2},1});
	v[v.size()-1].set_fill_color(Color::blue);

	v.push_back(new Right_triangle{Point{100+sqa,100+sqa+sqa/2},Point{100+sqa/2,100+2*sqa},1});
	v[v.size()-1].set_fill_color(Color::blue);

	v.push_back(new Right_triangle{Point{100+2*sqa,100+sqa+sqa/2},Point{100+sqa+sqa/2,100+2*sqa},1});
	v[v.size()-1].set_fill_color(Color::blue);



	for(int i = 0; i < v.size(); i++)
	{
		v[i].set_color(Color::invisible);
		win.attach(v[i]);
	}

	win.wait_for_button();
}