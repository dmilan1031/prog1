#include <iostream>

int R_fac(int a) //rekurzív faktoriális
{
	return a==1 ? 1 : a*R_fac(a-1);
}

int I_fac(int a) //iteratív faktoriális
{
	int b = 1;
	for(int i = 2; i <= a; i++) b*=i;
	return b;
}

int main()
{
	std::cout << R_fac(5) << " " << I_fac(5);
}