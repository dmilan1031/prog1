#include "Graph.h"
#include "Simple_window.h"
#include <cmath>

using namespace Graph_lib; 

struct complex
{
	complex() : re{0}, im{0} { }
	complex(double r, double i) : re{r}, im{i} { }

	double real() const { return re; }
	double imag() const { return im; }
	double abs() const { return sqrt(re*re+im*im); }
private:
	double re;
	double im;
};

complex operator + (complex a, complex b)
{
	return complex{a.real()+b.real(),a.imag()+b.imag()};
}

complex operator * (complex a, complex b)
{
	return complex{a.real()*b.real()-a.imag()*b.imag(),a.real()*b.imag()+a.imag()*b.real()};
}

int mandelbrot(complex c, int k)
{
	complex z;
	int i = 0;

	while(z.abs()<2 && i<k)
	{
		z = z * z + c;
		i++;
	}

	return i;
}

constexpr double scale = 300;
constexpr int orig_x = 600;
constexpr int orig_y = 400;

struct Mandelbrot_set : Shape
{
	Mandelbrot_set(Point xy, int ww, int hh) : w{ww}, h{hh} {add(xy);}
	void draw_lines() const;
private:
	int w;
	int h;
};

constexpr double dColor = 0.3;
constexpr double P = M_PI*2/3;
void color_circle(int& r, int& g, int& b, int a)
{
	r = int(sin(a*dColor)*127)+127;
	g = int(sin(a*dColor+P)*127)+127;
	b = int(sin(a*dColor+2*P)*127)+127;
}

void Mandelbrot_set::draw_lines() const
{
	for(int x = 0; x < w; x++)
		for(int y = 0; y < h; y++)
		{
			double xx = (x-orig_x)/scale;
			double yy = (y-orig_y)/scale;

			complex c {xx,yy};
			int k = mandelbrot(c,100);
			int r,g,b;
			if(k == 100) { r=255; g=200; b=200; }
			else color_circle(r,g,b,k);
			fl_color(r,g,b);
			fl_point(x,y);
		}
}

int main()
{
	Simple_window win {Point{100,100},800,800,"Mandelbrot"};
	Mandelbrot_set ms{ Point{0,0},800,800};
	win.attach(ms);
	win.wait_for_button();
}