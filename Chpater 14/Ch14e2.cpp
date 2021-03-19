#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	Circle s1 {Point{100,100},100};
	Shape s2 = s1;

	//A Shape deklarációjában a "Shape(const Shape&) = delete" megakadályozza a másolást
}