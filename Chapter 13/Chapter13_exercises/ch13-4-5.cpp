#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

Point point_on_ellipse(int x, int y, int w, int h, double phi) //segédfüggvény körök és ellipszisek esetén, phi függvényében ad egy pontot az ellipszis kerületén
{
	int xx = (int)(cos(phi)*w/2);
	int yy = (int)(sin(phi)*h/2);
	return Point{x+w/2+xx,y+h/2+yy};
}

const double d = atan(1); //45°-os szög

//Circle - körök és ellipszisek esetén a segédfüggvénnyel számolunk pontokat, 45 fokos beosztással az alakzatok felszínén

Point n(Circle& c) { return point_on_ellipse(c.point(0).x,c.point(0).y,c.radius()*2,c.radius()*2,d*2); }
Point w(Circle& c) { return point_on_ellipse(c.point(0).x,c.point(0).y,c.radius()*2,c.radius()*2,d*4); }
Point s(Circle& c) { return point_on_ellipse(c.point(0).x,c.point(0).y,c.radius()*2,c.radius()*2,d*6); }
Point e(Circle& c) { return point_on_ellipse(c.point(0).x,c.point(0).y,c.radius()*2,c.radius()*2,d*0); }

Point nw(Circle& c) { return point_on_ellipse(c.point(0).x,c.point(0).y,c.radius()*2,c.radius()*2,d*3); }
Point ne(Circle& c) { return point_on_ellipse(c.point(0).x,c.point(0).y,c.radius()*2,c.radius()*2,d*1); }
Point sw(Circle& c) { return point_on_ellipse(c.point(0).x,c.point(0).y,c.radius()*2,c.radius()*2,d*5); }
Point se(Circle& c) { return point_on_ellipse(c.point(0).x,c.point(0).y,c.radius()*2,c.radius()*2,d*7); }

Point center(Circle& c) {return c.center(); }


//Ellipse

Point n(Ellipse& e) { return point_on_ellipse(e.point(0).x,e.point(0).y,e.major()*2,e.minor()*2,d*2); }
Point w(Ellipse& e) { return point_on_ellipse(e.point(0).x,e.point(0).y,e.major()*2,e.minor()*2,d*4); }
Point s(Ellipse& e) { return point_on_ellipse(e.point(0).x,e.point(0).y,e.major()*2,e.minor()*2,d*6); }
Point e(Ellipse& e) { return point_on_ellipse(e.point(0).x,e.point(0).y,e.major()*2,e.minor()*2,d*0); }

Point nw(Ellipse& e) { return point_on_ellipse(e.point(0).x,e.point(0).y,e.major()*2,e.minor()*2,d*3); }
Point ne(Ellipse& e) { return point_on_ellipse(e.point(0).x,e.point(0).y,e.major()*2,e.minor()*2,d*1); }
Point sw(Ellipse& e) { return point_on_ellipse(e.point(0).x,e.point(0).y,e.major()*2,e.minor()*2,d*5); }
Point se(Ellipse& e) { return point_on_ellipse(e.point(0).x,e.point(0).y,e.major()*2,e.minor()*2,d*7); }

Point center(Ellipse& e) { return e.center(); }


//Rectangle

Point n(Rectangle& r) { return Point{r.point(0).x+r.width()/2,r.point(0).y}; }
Point w(Rectangle& r) { return Point{r.point(0).x,r.point(0).y+r.height()/2}; }
Point s(Rectangle& r) { return Point{r.point(0).x+r.width()/2,r.point(0).y+r.height()}; }
Point e(Rectangle& r) { return Point{r.point(0).x+r.width(),r.point(0).y+r.height()/2}; }

Point nw(Rectangle& r) { return Point{r.point(0).x,r.point(0).y}; }
Point ne(Rectangle& r) { return Point{r.point(0).x+r.width(),r.point(0).y}; }
Point sw(Rectangle& r) { return Point{r.point(0).x,r.point(0).y+r.height()}; }
Point se(Rectangle& r) { return Point{r.point(0).x+r.width(),r.point(0).y+r.height()}; }

Point center(Rectangle& r) { return Point{r.point(0).x+r.width()/2,r.point(0).y+r.height()/2}; }


int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 4"};

	Rectangle r {Point{100,100},100,100};
	Ellipse ell {Point{300,300},200,100};
	Circle c {Point{400,100},50};

	Mark m1 {se(r),'X'};
	Mark m2 {nw(ell),'O'};
	Mark m3 {e(c),'+'};

	win.attach(r);
	win.attach(c);
	win.attach(ell);

	win.attach(m1);
	win.attach(m2);
	win.attach(m3);

	win.wait_for_button();
}