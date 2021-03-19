#include "Simple_window.h"
#include "Graph.h"

struct Immobile_Circle : public Circle
{
	using Circle::Circle;
	void move(int, int) {};
};

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 4"};
	Immobile_Circle ic {Point{100,100},100};
	win.attach(ic);
	ic.move(50,50);
	win.wait_for_button();
}