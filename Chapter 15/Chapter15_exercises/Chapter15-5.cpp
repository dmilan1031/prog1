#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

int main()
{
	Simple_window win{Point{100,100},500,500,"Exercise 5"};

	constexpr int xspace = 100; //segéd konstansok a grafikonhoz
	const int xlength = win.x_max()-2*xspace;
	const int yhalf = win.y_max()/2;

	Line l1 {Point{ xspace, yhalf }, Point{ xspace+xlength, yhalf }}; // (0,1) szakasz
	Line l2 {Point{ xspace, yhalf-100}, Point{ xspace, yhalf+100 }};
	Line l3 {Point{ xspace+xlength, yhalf-100}, Point{ xspace+xlength, yhalf+100 }};
	Line l4 {Point{ xspace+int(75*M_PI), yhalf-100}, Point{ xspace+int(75*M_PI), yhalf+100 }};

	Text t1 {Point{ xspace, yhalf-100}, "0"}; //feliratok
	Text t2 {Point{ xspace+xlength, yhalf-100}, "1"};
	Text t3 {Point{ xspace+int(75*M_PI), yhalf-100}, "Pi/4"};
	Text t4 {Point{ xspace, yhalf-120}, "S(n)"};
	t4.set_color(Color::blue);

	Lines ls;
	ls.set_color(Color::blue);


	win.attach(l1);
	win.attach(l2);
	win.attach(l3);
	win.attach(l4);
	win.attach(ls);

	win.attach(t1);
	win.attach(t2);
	win.attach(t3);
	win.attach(t4);

	win.wait_for_button();

	double S = 0; //összeg
	int i = 0; //nevező
	int k = 1; //előjel

	while(true)
	{
		S += k*1/double(i*2+1); 
		ls.add(Point{xspace+int(xlength*S),yhalf-50}, Point{xspace+int(xlength*S),yhalf+50});
		t4.move( int(300*k*1/double(i*2+1)), 0 );

		i++;
		k*=-1;

		win.wait_for_button();
	}
}