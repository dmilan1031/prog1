#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

struct Striped_closed_polyline : Closed_polyline
{
	using Closed_polyline::Closed_polyline;
	Striped_closed_polyline(initializer_list<Point> lst, int space) : Closed_polyline(lst) , spc{space} { }
	int space() const {return spc;}
	void set_space(int s) {spc = s;};
	void draw_lines() const;
private:
	int spc {3}; //vonalköz
	int intersect (const Point p1, const Point p2, int h) const; //segédfüggvény a stripe-hoz, egy szakasz és vízszintes egyenes metszéspontját keresi
	void stripe(int h) const; //egy "stripe" kirajzolása h magasságban
};

void Striped_closed_polyline::draw_lines() const
{
	Closed_polyline::draw_lines();
	if(number_of_points()>2) //csak akkor vonalazzuk be, ha legalább 3 éle van
	{
		int min = point(0).y; //a vízszintes vonalakat csak a legalsó és legfelső pontok között kell megrajzolni
		int max = point(0).y;
		for(int i = 0; i < number_of_points(); i++) //min/max keresés
		{
			if(point(i).y < min) min = point(i).y;
			if(point(i).y > max) max = point(i).y;
		}
		for(int i = min; i < max; i+=spc) stripe(i); //vonalak kirajzoltatása
	}
}

void Striped_closed_polyline::stripe(int h) const
{
	{
		vector<int> v; //a h magasságú egyenes és a closed polyline metszéspontjat fogja tartalmazni
		for (int i = 0; i < number_of_points()-1; i++) //a polyline összes élével megvizsgáljuk a metszést
		{
			if((point(i).y-h)*(point(i+1).y-h)<0)	//ha a szakasz két pontja az egyenes alatt és felett helyezkedik el, az egyenes metszi a szakaszt
			{										//ekkor a szorzat két oldala eltérő előjelű
				v.push_back(intersect(point(i),point(i+1),h));
			}
		}

		if((point(0).y-h)*(point(number_of_points()-1).y-h)<0) //az első és utolsó pontot összekötő szakasz kezelése
		{
			v.push_back(intersect(point(0),point(number_of_points()-1),h));
		}

		sort(v); 							//v a metszéspontok x koordinátáit tartalmazza növekvő sorrendben
		for(int i = 0; i < v.size(); i+=2)	//belátható, hogy ha irányítottnak képzeljük az egyenest, felváltva fog ki- és belépni a closed polyline területére
		{									//ezért a rendezett vektorból páronként ki lehet olvasni a metszetként keletkező szakaszok kezdő- és végpontjának x koordinátái
			fl_line(v[i],h,v[i+1],h);		//a pontok y koordinátáit tudjuk: h
		}
	}
}

int Striped_closed_polyline::intersect(const Point p1, const Point p2, int h) const
{
	Point kis;
	Point nagy;
	if(p1.y<p2.y)	{kis = p1; nagy = p2;}
	else			{kis = p2; nagy = p1;}
	int xx = kis.x + (int)(((float)(h-kis.y)/(nagy.y-kis.y))*(nagy.x-kis.x)); //hasonlóságon alapuló képlet
	return xx;
}

int main()
{
	Simple_window win {Point{100,100},500,500,"Exercise 7"};
	Striped_closed_polyline scp = 
	{
		{{100,100},{200,200},{100,300},{200,100}, {250,150}},
		3
	};
	win.attach(scp);
	win.wait_for_button();
}
