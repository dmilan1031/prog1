#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

struct FuntionR : Shape
{
	FuntionR(Fct& ff, double rr1, double rr2, Point xy, int cnt, double xs, double ys);
private:
	Fct& f;
	double r1;
	double r2;
	Point orig;
	int count;
	double xscale;
	double yscale;
};

//Function::Function a Graph.cpp-ből

FuntionR::FuntionR(Fct& ff, double rr1, double rr2, Point xy, int cnt, double xs, double ys) : 
	r1{rr1}, r2{rr2}, orig{xy}, count{cnt}, xscale{xs}, yscale{ys}
{
	f&.assign(ff);
	if (r2-r1<=0) error ("Rossz range!");
	if (count<=0) error ("Rossz count!");
	double dist = (r2-r1)/count;
	double r = r1;
	for (int i = 0; i < count; ++i){
		add(Point(xy.x+int(r*xscale), xy.y-int(f(r)*yscale)));
		r += dist;
	}
}

int main()
{

}