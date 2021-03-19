#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

struct Binary_tree : Shape
{
	Binary_tree(Point xy, int levels) : lvl{levels}
	{
		v = {(int)pow(2,lvl),""};
		set_fill_color(Color::white);
		add(xy);
		build_tree(xy.x,xy.y,levels);
	}
	void set_label(string path, string l) {v[path_to_index(path)]=l;};
	string label(string path) {return v[path_to_index(path)];}
	void draw_lines() const;
private:
	vector<string> v; 
	int lvl;
	int path_to_index(string path) const;
	void build_tree(int xx, int yy, int lv); //rekurzív módon hozzáadja a Shape-hez a fa pointjait
	virtual void draw_node(int index); //rekurzívan kirajzolja a fát
};

void Binary_tree::draw_lines() const
{
	int k = (number_of_points()+1)/2;
	for(int i = 1; i < k; i++)
	{
		fl_line(point(i-1).x,point(i-1).y,point(i*2-1).x,point(i*2-1).y);
		fl_line(point(i-1).x,point(i-1).y,point(i*2).x,point(i*2).y);
	}

}

void Binary_tree::build_tree(int xx, int yy, int lv) 
{
	if(lv>1)
	{
		int dx = pow(2,lvl)*25;
		add(Point{xx+dx,yy+40});
		add(Point{xx-dx,yy+40});
		build_tree(xx+dx,yy+40,lvl-1);
		build_tree(xx-dx,yy+40,lvl-1);
	}
}

void Binary_tree::draw_node(int index)
{
	int xx = point(index).x;
	int yy = point(index).y;

	fl_color(fill_color().as_int());
	fl_pie(xx-20,yy-20,40,40,0,360);

	fl_color(color().as_int());
	fl_arc(xx-20,yy-20,40,40,0,360);
}

int Binary_tree::path_to_index(string path) const
{
	int index = 1;
	for(int i = 0; i < path.length(); i++)
	{
		if(path[i]=='l')index = index*2;	//bináris keresőfa algoritmus alapján
		if(path[i]=='r')index = index*2+1;
	}
	return index-1;
}

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 11"};
	Binary_tree bt {Point{250,100},3};
	win.wait_for_button();
}
