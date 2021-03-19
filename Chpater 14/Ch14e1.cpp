#include "Graph.h"
#include "Simple_window.h"

struct Smiley : public Circle
{
	using Circle::Circle;
	void draw_lines() const;
};

struct Frowny : public Circle
{
	using Circle::Circle;
	void draw_lines() const;
};

struct Smiley_with_hat : public Smiley
{
	using Smiley::Smiley;
	void draw_lines() const;
};

struct Frowny_with_hat : public Frowny
{
	using Frowny::Frowny;
	void draw_lines() const;
};

void Smiley::draw_lines() const
{
	Circle::draw_lines();
	fl_arc(point(0).x+radius()/2,point(0).y+radius()/2,radius(),radius(),180,360);
	fl_arc(point(0).x+radius()/2,point(0).y+radius()/2,radius()/2,radius()/2,0,360);
	fl_arc(point(0).x+radius(),point(0).y+radius()/2,radius()/2,radius()/2,0,360);
}

void Frowny::draw_lines() const
{
	Circle::draw_lines();
	fl_arc(point(0).x+radius()/2,point(0).y+radius(),radius(),radius(),0,180);
	fl_arc(point(0).x+radius()/2,point(0).y+radius()/2,radius()/2,radius()/2,0,360);
	fl_arc(point(0).x+radius(),point(0).y+radius()/2,radius()/2,radius()/2,0,360);
}

void Smiley_with_hat::draw_lines() const
{
	Smiley::draw_lines();
	fl_line(point(0).x+radius()/2,point(0).y,point(0).x+radius()*3/2,point(0).y);
	fl_line(point(0).x+radius()*3/2,point(0).y,point(0).x+radius(),point(0).y-radius());
	fl_line(point(0).x+radius(),point(0).y-radius(),point(0).x+radius()/2,point(0).y);
}

void Frowny_with_hat::draw_lines() const
{
	Frowny::draw_lines();
	fl_line(point(0).x+radius()/2,point(0).y,point(0).x+radius()*3/2,point(0).y);
	fl_arc(point(0).x+radius()/2,point(0).y-radius()/2,radius(),radius(),0,180);
}

int main()
{
	Simple_window win {Point{100,100},500,500,"Excercise 1"};
	Smiley s{Point{150,150},100};
	Frowny f{Point{100,300},50};
	Smiley_with_hat sh {Point{400,400},80};
	Frowny_with_hat fh {Point{200,400},60};
	win.attach(s);
	win.attach(f);
	win.attach(sh);
	win.attach(fh);
	win.wait_for_button();
}