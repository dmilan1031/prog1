#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while(f1!=e1)
	{
		*f2 = *f1;
		f2++;
		f1++;
	}
	return f2;
}

int main()
{
	//1-3
	int a[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> v { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::list<int> l { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	//4
	int a2[10]; //nem lehet másolatként inicializálni
	std::copy(a,a+10,a2); //maga az 'a' használható iterátorként
	std::vector<int> v2 = v;
	std::list<int> l2 = l;

	//5
	for(auto i : a) i+=2;
	for(auto i : v) i+=3;
	for(auto i : l) i+=5;

	//7
	my_copy(a,a+10,v.begin());
	my_copy(l.begin(),l.end(),a);

	//8
	auto f = std::find(v.begin(),v.end(),3); //auto helyett std::vector<int>::iterator lehetne
	if(f == v.end()) std::cout << "Nincs ilyen elem\n";
	else std::cout << std::distance(v.begin(),f)+1 << '\n';

	auto f2 = std::find(l.begin(),l.end(),27);
	if(f2 == l.end()) std::cout << "Nincs ilyen elem\n";
	else std::cout << std::distance(l.begin(),f2)+1 << '\n';
}