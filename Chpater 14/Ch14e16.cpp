#include "Graph.h"
#include "Simple_window.h"

struct Controller
{
	virtual void on() {b = true;}
	virtual void off() {b = false;}
	virtual void show() { }
	virtual void level(int i) { lvl = i; }

	bool state() const { return b; }
	int get_level() const { return lvl; }
private:
	bool b;
	int lvl {0};
};

struct ControllerTest : Controller
{
	void show() 
	{
		std::cout << (state()?"on ":"off ") << get_level() << std::endl;
	}
};

struct Control_color : Controller
{	
	void level(int i)
	{
		Controller::level(i);
		if(s!=0)
		{
			s->set_color(Color{get_level()});
		}
	}
	void set_shape(Shape &shp) { s = &shp; }
private:
	Shape* s;
};

struct Control_thickness : Controller
{	
	void level(int i)
	{
		Controller::level(i);
		if(s!=0)
		{
			s->set_style(Line_style{Line_style::solid,i});
		}
	}
	void set_shape(Shape &shp) { s = &shp; }
private:
	Shape* s;
};

int main()
{
	ControllerTest ct;
	ct.on();
	ct.show();

	Simple_window win {Point{100,100},500,500,"Exercise 16"};
	Circle c {Point{200,200},100};

	Control_color col;
	col.set_shape(c);
	col.level(5);

	Control_thickness thk;
	thk.set_shape(c);
	thk.level(5);

	win.attach(c);
	win.wait_for_button();
}