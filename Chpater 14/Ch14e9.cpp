#include "Simple_window.h"
#include "Graph.h"

struct Group
{
	Group() {}
	void move(int dx, int dy);
	int size() {return v.size();}
	void add(Shape* s) {v.push_back(s);}
	Shape& shape(int i) {return v[i];}
	Shape& last_shape() {return v[v.size()-1];}
private:
	Vector_ref<Shape> v;
};

void Group::move(int dx, int dy)
{
	for(int i = 0; i < v.size(); i++) v[i].move(dx,dy);
}

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 9"};

	Group checker_board; //tábla
	for(int x = 0; x < 8; x++)
		for(int y = 0; y < 8; y++)
		{
			checker_board.add(new Rectangle{Point{x*50,y*50},50,50});
			checker_board.last_shape().set_fill_color((x%2==y%2)?Color::white:Color::black); 	//egy négyzet szomszédjainak a koordinátái vagy x-ben vagy y-ban térnek el eggyel,
			win.attach(checker_board.last_shape());												//így a szomszédos cellák (x%2==y%2) értéke biztosan eltérő
		}

	Group my_pieces; //bábuk
	for(int x = 0; x < 8; x++)
		for(int y = 6; y < 8; y++)
		{
			if(x%2==y%2)
			{
			checker_board.add(new Circle{Point{x*50+25,y*50+25},20});
			checker_board.last_shape().set_fill_color(Color::red);
			win.attach(checker_board.last_shape());
			}
		}

	my_pieces.move(50,50);
	checker_board.move(50,50);

	win.wait_for_button();
}
