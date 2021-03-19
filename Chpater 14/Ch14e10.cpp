#include "Simple_window.h"
#include "Graph.h"

struct Pseudo_window : Shape
{
	Pseudo_window(Point xy, int ww, int hh) : w{ww}, h{hh}
	{
		if(w < 50)w = 50; //a fejléc és lekerekítések kirajzolása miatt minimum méretet vesz fel
		if(h < 30)h = 30;
		set_fill_color(Color::white);
		add(xy);
	}
	void draw_lines() const;
private:
	int w;
	int h;
};

void Pseudo_window::draw_lines() const
{
	int xx = point(0).x;
	int yy = point(0).y;

	//a sarkak lekerekítése 10 pixel sugarú

	fl_color(fill_color().as_int());

	fl_pie(xx,yy+h-20,20,20,180,270);	//az ablak kitöltése
	fl_pie(xx+w-20,yy+h-20,20,20,270,360);
	fl_rectf(xx,yy+20,w,h-30);
	fl_rectf(xx+10,yy+h-10,w-20,10);

	fl_color(color().as_int());

	fl_line(xx+10,yy,xx+w-10,yy);		//oldalak megrajzolása, helyet hagyva a lekerekített sarkoknak
	fl_line(xx+10,yy+h,xx+w-10,yy+h);

	fl_line(xx,yy+10,xx,yy+h-10);
	fl_line(xx+w,yy+10,xx+w,yy+h-10);

	fl_arc(xx,yy,20,20,90,180);			//lekerekített sarkak
	fl_arc(xx,yy+h-20,20,20,180,270);
	fl_arc(xx+w-20,yy,20,20,0,90);
	fl_arc(xx+w-20,yy+h-20,20,20,270,360);

	fl_line(xx,yy+20,xx+w,yy+20); //fejléc
	fl_arc(xx+5,yy+5,10,10,0,360);
	fl_arc(xx+20,yy+5,10,10,0,360);
	fl_arc(xx+35,yy+5,10,10,0,360);
}

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 10"};
	Pseudo_window pw {Point{100,100},100,100};
	Pseudo_window pw2 {Point{100,300},200,50};
	win.attach(pw);
	win.attach(pw2);
	win.wait_for_button();
}
