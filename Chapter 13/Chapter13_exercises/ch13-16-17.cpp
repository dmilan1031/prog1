#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
#include <vector>

struct Regular_hexagon : Shape
{
	Regular_hexagon(Point c, int rr) : r{rr}
	{
		if(r < 0) error("Negatív sugár");
		add(c);
	}
	Regular_hexagon(Point c, int rr, double p) : r{rr} , phs{p} 
	{
		if(r < 0) error("Negatív sugár");
		add(c);
	}
	void draw_lines() const;
	void set_radius(int rr) { r = rr; }
	void set_phase(double p) { phs = p; }
	int radius() const { return r; }
	double phase() const { return phs; }
private:
	int r;
	double phs = 0;
};

void Regular_hexagon::draw_lines() const
{
	int xx = point(0).x;
	int yy = point(0).y;
	double a = M_PI/3; //30 fokos szög radiánban

	if(fill_color().visibility())
	{
		fl_color(fill_color().as_int());
		fl_begin_complex_polygon();
		for(int i = 0; i < 6; i++)
		{
			fl_vertex(
				xx+radius()*cos(a*i+phase()),
				yy+radius()*sin(a*i+phase())
				);
		}
		fl_end_complex_polygon();
	}

	if(color().visibility())
	{
		fl_color(color().as_int());
		for(int i = 0; i < 6; i++)
		{
			fl_line(
				xx+radius()*cos(a*i+phase()),
				yy+radius()*sin(a*i+phase()),
				xx+radius()*cos(a*(i+1)+phase()),
				yy+radius()*sin(a*(i+1)+phase())
				);
		}
	}

}

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 9"};
	Vector_ref<Regular_hexagon> hex;

	int r = 30;

	int dx = (int)(1.5*r);
	int dy = (int)(sqrt(3)*r);

	vector<Color::Color_type> ct { Color::green, Color::dark_green, Color::cyan, Color::dark_cyan, Color::blue, Color::white, Color::magenta };
	int i = 0;
	int k = 5;

	for(int x = 0; x < win.x_max()/dx+1; x++)
		for(int y = 0; y < win.y_max()/dy+1; y++)
		{
			hex.push_back(new Regular_hexagon {Point{x*dx,y*dy+((x%2==1)?dy/2:0)},r});
			hex[hex.size()-1].set_style(Line_style{Line_style::solid,3});
			hex[hex.size()-1].set_fill_color(ct[(k*i++)%ct.size()]);
			hex[hex.size()-1].set_color(Color::dark_magenta);
			win.attach(hex[hex.size()-1]);
		}
		
	win.wait_for_button();
}