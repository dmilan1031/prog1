#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <numeric>

int main()
{
	//1
	std::ifstream fstr("float.txt");
	std::vector<double> vd;
	double d;
	while(fstr >> d) vd.push_back(d);

	//2
	for(int i = 0; i < vd.size(); i++) std::cout << vd[i] << " ";

	//3
	std::vector<int> vi(vd.size());
	std::copy(vd.begin(),vd.end(),vi.begin());

	//4
	std::cout << "\n\n";
	for(int i = 0; i < vd.size(); i++) std::cout << vd[i] << "\t" << vi[i] << '\n';

	//5
	std::cout << "\n\n" << "vd sum:" << '\n';
	std::cout << accumulate(vd.begin(),vd.end(),0.0);

	//6
	std::cout << "\n\n" << "difference:" << '\n';
	std::cout << accumulate(vd.begin(),vd.end(),0.0) - accumulate(vi.begin(),vi.end(),0);

	//7
	std::cout << "\n\n" << "reverse:" << '\n';
	for(int i = 0; i < vd.size(); i++) std::cout << vd[i] << " ";

	//8
	std::cout << "\n\n" << "vd mean:" << '\n';
	double mean = accumulate(vd.begin(),vd.end(),0.0)/vd.size();
	std::cout << mean;

	//9
	std::vector<double> vd2(vd.size());
	std::copy_if(vd.begin(),vd.end(),vd2.begin(),
		[mean](double d){return d < mean;}
		);

	//10
	std::cout << "\n\n" << "vd sorted:" << '\n';
	std::sort(vd.begin(),vd.end());
	for(int i = 0; i < vd.size(); i++) std::cout << vd[i] << " ";
	std::cout << '\n';

}