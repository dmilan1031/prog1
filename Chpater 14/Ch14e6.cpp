#include "Simple_window.h"
#include "Graph.h"

struct Striped_Circle : Circle
{
	Striped_Circle(Point xy, int r, int space) : Circle(xy,r), spc{space} { }
	int space() const {return spc;}
	void set_space(int s) {spc = s;};
	void draw_lines() const;
private:
	int spc; //vonalköz
};

void Striped_Circle::draw_lines() const
{
	int k = point(0).x+radius(); //a középpont x koordinátája
	Circle::draw_lines();
	for(int i = -radius(); i<radius() ;i+=spc)
	{
		double fe = sqrt(radius()*radius()-abs(i)*abs(i)); //félérintő, pitagorasz tétellel kiszámolva
		fl_line(k-fe,point(0).y+radius()+i,k+fe,point(0).y+radius()+i);
	}
}

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 7"};
	Striped_Circle sc {Point{250,250},100,3};
	win.attach(sc);
	sc.set_space(5);
	sc.set_fill_color(Color::white);
	sc.set_style(Line_style{Line_style::dash,2});
	win.wait_for_button();
}
