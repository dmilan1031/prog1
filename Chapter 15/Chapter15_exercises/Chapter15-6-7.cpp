#include "Simple_window.h"
#include "Graph.h"
#include <vector>

using namespace Graph_lib;

struct Bar_graph : Shape
{
	Bar_graph(Point xy, int ww, int hh, double qq = 0.5) : w{ww}, h{hh}, q{qq} 
	{ 
		add(xy);
	}
	void draw_lines() const;

	void set_width(int ww) { w = ww; }
	void set_height(int hh) { h = hh; }
	void set_q(double qq) { q = qq; }
	void add_value(double d, string label = "") 
	{ 
		labels.push_back(label);
		v.push_back(d);
		if(d > max) max = d;
	}
	void set_bar_color(Color c) { b_col = c; }
	void set_label(string ll) { l = ll; }

	int width() const { return w; }
	int height() const { return h; }
	int number_of_values() const { return v.size(); }
	Color bar_color() const { return b_col; }

private:
	int w;
	int h;
	double q; //mekkora részét teszik k az oszlopok a grafikonnak
	double max; //legnagyobb érték

	Color b_col = Color::invisible; //oszlopok színe
	vector<string> labels;
	vector<double> v;

	string l; //a diagram felirata
};

void Bar_graph::draw_lines() const
{
	//a diagram háttere és felirata

	if(fill_color().visibility())
	{
		fl_color(fill_color().as_int());
		fl_rectf(point(0).x,point(0).y,w,h);
	}

	if(color().visibility())
	{
		fl_color(color().as_int());
		fl_rect(point(0).x,point(0).y,w,h);
		fl_draw(l.c_str(),point(0).x+3,point(0).y+13);
	}

	//oszlopok

	if(bar_color().visibility() && number_of_values() > 0 )
	{
		int space = int(w/double(number_of_values())); //egy oszlopra jutó intervallum
		int bwidth = int(space*q); //az oszlop szélessége
		int bspace = int(space*double(1-q)/2); //az oszlop melletti rés

		double scale = h/double(max);

		

		for(int i = 0; i < v.size(); i++)
		{
			int xx = space*i + bspace; //az aktuális oszlop bal felső sarka
			int yy = h - int(v[i]*scale);

			fl_color(color().as_int()); //oszlopfeliratok
			fl_draw(labels[i].c_str(),point(0).x+xx,point(0).y+h+15);

			fl_color(bar_color().as_int());
			fl_rectf(point(0).x+xx, point(0).y+yy, bwidth, int(v[i]*scale));
		}
	}

}

int main()
{
	Simple_window win {Point{100,100},800,500,"Exercise 6-7"};
	Bar_graph bg {Point{100,100},600,300,0.2f};

	bg.add_value(1,"egy");
	bg.add_value(2,"ketto");
	bg.add_value(3,"harom");

	bg.set_bar_color(Color::blue);
	bg.set_fill_color(Color::white);

	bg.set_label("grafikon");

	win.attach(bg);
	win.wait_for_button();
}