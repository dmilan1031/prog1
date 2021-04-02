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
	Simple_window win {Point{100,100},500,500,"Exercise 15"};

	int size = 30; //felosztás mérete
	Vector_ref<Right_triangle> v;

	for(int x = 0; x < win.x_max()/size+1; x++)
		for(int y = 0; y < win.y_max()/size+1; y++)
		{
			v.push_back(new Right_triangle{Point{x*size,(y+1)*size},Point{x*size,y*size},1});
			v[v.size()-1].set_color(Color::invisible);
			v[v.size()-1].set_fill_color(Color::cyan);
			win.attach(v[v.size()-1]);

			v.push_back(new Right_triangle{Point{(x+1)*size,y*size},Point{(x+1)*size,(y+1)*size},1});
			v[v.size()-1].set_color(Color::invisible);
			v[v.size()-1].set_fill_color(Color::blue);
			win.attach(v[v.size()-1]);
		}

	win.wait_for_button();
}