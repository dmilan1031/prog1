//zn+1 = zn^2 +c
//z0 = 0
//abs(zn) < 2?

#include "Graph.h"
#include "Simple_window.h"

struct complex
{
	double im;
	double re;
	double abs();
};

complex operator + (complex c1, complex c2)
{
	return complex{c1.re+c2.re,c1.im+c2.im};
}

complex operator * (complex c1, complex c2)
{
	return complex{c1.re*c2.re-c1.im*c2.im,c1.re*c2.im+c2.re*c1.im};
}

double complex::abs()
{
	return sqrt(re*re+im*im);
}

int main()
{
	complex z0{0,0};			//a kérdéses komplex számsorozatok első tagja
	complex c;					//a vizsgált pont
	const int n = 100;			//n számolás után a sorozatot konvergensnek tekintjük
	const int pixel = 20;		//a halmazból vett minták mérete

	const double c_x = -2;		//a rajz bal felső sarkának koordinátái
	const double c_y = -2;
	const double scale = 0.008;	//egy "pixel" mérete a koordinátarendszerben

	Vector_ref<Rectangle> rajz;
	Simple_window win {Point{100,100},500,500,"Mandelbrot"};

	for(int x = 0; x < win.x_max(); x+=pixel)
		for(int y = 0; y < win.y_max(); y+=pixel)			//az ablak bejárása
		{
			c = {(double)x*scale+c_x,(double)y*scale+c_y};	//az ablak pontja áthelyezve a koordinátarendszerbe

			complex z = z0;				//a számsorozat aktuális tagja;
			int iter = 0;				//az iteráció száma

			while(z.abs() < 2 && ++iter < n)
			{
				z = z*z+c;
			}

			rajz.push_back(new Rectangle{Point{x,y},pixel,pixel});
			rajz[rajz.size()-1].set_fill_color(iter==n? Color::black : Color::white);
			win.attach(rajz[rajz.size()-1]);
		}

	win.wait_for_button();
}