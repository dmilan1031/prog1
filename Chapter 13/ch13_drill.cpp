#include "Simple_window.h"
#include "Graph.h"

int main()
{
	//1.
	Simple_window win {{100,100},800,1000,"Chapter 13"};

	//2.
	Lines grid;
	int grid_size = 100;

	for (int i = 0; i <= win.x_max()/grid_size ; ++i)	//ablak méretéhez alkalmazkodik a négyzetrács
	{													//i = win.x_max()/grid_size megengedett, hogy a rács alját is megrajzolja
		grid.add({i*grid_size,0},{i*grid_size,800});	//vízszintes vonalak
		grid.add({0,i*grid_size},{800,i*grid_size});	//függőleges vonalak
	}

	win.attach(grid);

	//3.
	Vector_ref<Rectangle> diagonal;

	for (int i = 0; i <= win.x_max()/grid_size ; ++i)
	{
		diagonal.push_back(new Rectangle{{i*grid_size,i*grid_size},100,100});
		diagonal[diagonal.size()-1].set_fill_color(Color::red);
		win.attach(diagonal[diagonal.size()-1]);
	}

	//4.
	Image tree_1 {Point{0,400},"tree200.jpg"};
	Image tree_2 {Point{0,600},"tree200.jpg"};
	Image tree_3 {Point{200,600},"tree200.jpg"};

	win.attach(tree_1);
	win.attach(tree_2);
	win.attach(tree_3);

	//5.
	Image tri {{100,0},"triangle100.jpg"};
	win.attach(tri);
	int pos_x = 1;	//számon tartja a kép helyzetét
	int pos_y = 0;

	while(true)
	{
		win.wait_for_button();
		tri.move(100,0);
		pos_x++;

		if(pos_x>=8) {pos_x = 0; tri.move(-800,100); pos_y++;} //a kép soronként bejárja a négyzethálót
		if(pos_y>=8) {pos_y = 0; tri.move(0,-800);}
	}
}