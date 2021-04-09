#include "GUI.h"

using namespace Graph_lib;

struct  Lines_window : Window
{
	Lines_window(Point xy, int w, int h, const string& title);
	
private:
	Open_polyline lines;

	Menu color_menu;
	Menu style_menu;

	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;
	Out_box xy_out;

	Button color_menu_button;
	Button style_menu_button;

	void change_color(Color c) { lines.set_color(c); }
	void change_style(Line_style l) { lines.set_style(l); }

	void hide_color_menu() { color_menu.hide(); color_menu_button.show(); }
	void hide_style_menu() { style_menu.hide(); style_menu_button.show(); }

	void show_color_menu() { color_menu.show(); color_menu_button.hide(); }
	void show_style_menu() { style_menu.show(); style_menu_button.hide(); }

	void red_pressed() { change_color(Color::red); redraw(); hide_color_menu(); }
	void blue_pressed() { change_color(Color::blue); redraw(); hide_color_menu(); }
	void black_pressed() { change_color(Color::black); redraw(); hide_color_menu(); }

	void solid_pressed() { change_style({Line_style::solid,1}); redraw(); hide_style_menu(); }
	void dash_pressed() { change_style({Line_style::dash,1}); redraw(); hide_style_menu(); }
	void dot_pressed() { change_style({Line_style::dot,1}); redraw(); hide_style_menu(); }

	void next();
	void quit(){ hide(); }
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window{xy,w,h,title},
	next_button{ Point{x_max()-150,0},70,20,"Next point",
		[](Address,Address pw) { reference_to<Lines_window>(pw).next();} }, //widgetek inicializálása
	quit_button{ Point{x_max()-70,0},70,20,"Quit",
		[](Address,Address pw) { reference_to<Lines_window>(pw).quit();} },
	next_x{Point{x_max()-310,0},50,20,"next x:"},
	next_y{Point{x_max()-210,0},50,20,"next y:"},
	xy_out{Point{100,0},100,20,"current (x,y):"},
	color_menu{Point{x_max()-70,40},70,20,Menu::vertical,"color"},
	style_menu{Point{x_max()-70,110},70,20,Menu::vertical,"style"},
	color_menu_button{ Point{x_max()-70,40},70,20,"color",
		[](Address,Address pw) { reference_to<Lines_window>(pw).show_color_menu(); } },
	style_menu_button{ Point{x_max()-70,110},70,20,"style",
		[](Address,Address pw) { reference_to<Lines_window>(pw).show_style_menu();} }
{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	attach(lines);

	//menügombok létrehozása, callback függvények lambda kifejezéssel
	color_menu.attach(new Button{ Point{0,0},0,0,"red",
		[](Address,Address pw){ reference_to<Lines_window>(pw).red_pressed(); }});
	color_menu.attach(new Button{ Point{0,0},0,0,"blue",
		[](Address,Address pw){ reference_to<Lines_window>(pw).blue_pressed(); }});
	color_menu.attach(new Button{ Point{0,0},0,0,"black",
		[](Address,Address pw){ reference_to<Lines_window>(pw).black_pressed(); }});

	style_menu.attach(new Button{ Point{0,0},0,0,"solid",
		[](Address,Address pw){ reference_to<Lines_window>(pw).solid_pressed(); }});
	style_menu.attach(new Button{ Point{0,0},0,0,"dashed",
		[](Address,Address pw){ reference_to<Lines_window>(pw).dash_pressed(); }});
	style_menu.attach(new Button{ Point{0,0},0,0,"dotted",
		[](Address,Address pw){ reference_to<Lines_window>(pw).dot_pressed(); }});

	attach(color_menu);
	attach(style_menu);
	attach(color_menu_button);
	attach(style_menu_button);

	color_menu.hide();
	style_menu.hide();
}

void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();
	lines.add(Point{x,y});

	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();
}

int main()
try
{
	Lines_window win {Point{100,100},600,400,"lines"};
	return gui_main();
}
catch(exception& e)
{
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch(...)
{
	cerr << "some exception" << '\n';
	return 2;
}
