#include "Simple_window.h"
#include "Graph.h"

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 13"};
	Vector_ref<Rectangle> v;

	int size = 25;

	for(int x = 0; x < 16; x++)
		for(int y = 0; y < 16; y++)
		{
			v.push_back(new Rectangle{Point{x*size,y*size},size,size});
			v[v.size()-1].set_fill_color(Color{x*16+y});
			v[v.size()-1].set_color(Color::invisible);
			win.attach(v[v.size()-1]);
		}

	win.wait_for_button();
}