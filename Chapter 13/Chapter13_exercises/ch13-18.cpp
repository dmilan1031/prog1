#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

struct  Poly : Shape
{
	Poly(initializer_list<Point> l)
	{
		if(l.size()<3) error("Túl kevés pont a Poly megadásában");
		for(Point p : l)
		{
			for(int j = 0; j < number_of_points()-1; j++)
			{
				if(test_intersect(p,point(number_of_points()-1),point(j),point(j+1))) error("A Poly oldalai metszik egymást");
			}
			add(p);
		}

		for(int i = 0; i < number_of_points()-1; i++)
		{
			if(test_intersect(point(0),point(number_of_points()-1),point(i),point(i+1))) error("A Poly oldalai metszik egymást");
		}
	}
	void draw_lines() const;
private:
	bool test_intersect(Point A1, Point A2, Point B1, Point B2) const
	{
		if( (((A2.x-A1.x)*(B1.y-A1.y) - (A2.y-A1.y)*(B1.x-A1.x)) * ((A2.x-A1.x)*(B2.y-A1.y) - (A2.y-A1.y)*(B2.x-A1.x))) >= 0 ) return false;
		if( (((B2.x-B1.x)*(A1.y-B1.y) - (B2.y-B1.y)*(A1.x-B1.x)) * ((B2.x-B1.x)*(A2.y-B1.y) - (B2.y-B1.y)*(A2.x-B1.x))) >= 0 ) return false;
		return true;
	}
};

void Poly::draw_lines() const
{
	if(fill_color().visibility())
	{
		fl_color(fill_color().as_int());
		fl_begin_complex_polygon();
		for(int i = 0; i < number_of_points(); i++) fl_vertex(point(i).x,point(i).y);
		fl_end_complex_polygon();
	}

	if(color().visibility())
	{
		fl_color(color().as_int());
		for(int i = 0; i < number_of_points()-1; i++)
		{
			fl_line(point(i).x,point(i).y,point(i+1).x,point(i+1).y);
		}
		fl_line(point(0).x,point(0).y,point(number_of_points()-1).x,point(number_of_points()-1).y);
	}
}

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 18"};
	Poly p {{100,100},{100,200},{200,200},{200,100}};
	p.set_fill_color(Color::red);
	win.attach(p);

	win.wait_for_button();
}