#include <vector>
#include <list>
#include <iostream>

struct Iterator
{
	virtual double* next() =0;
};

struct Vector_iterator : Iterator
{
	Vector_iterator(std::vector<double> vv) : v{vv} { };
	double* next()
	{
		if(i>=v.size()) return 0;
		return &v[i++];
	}
private:
	std::vector<double> v;
	int i = 0;
};

struct List_iterator : Iterator
{
	List_iterator(std::list<double> ll) : l{ll} { };
	double* next()
	{
		if(i>=l.size()) return 0; //megoldás az internetről: std::list kezelése
		auto lbegin = l.begin();
		std::advance(lbegin,i++);
		return &(*lbegin); //??
	}
private:
	std::list<double> l;
	int i = 0;
};

void print(Iterator& it)
{
	double* d = it.next();
	while(d!=0)
	{
		std::cout << *d << " ";
		d = it.next();
	}
}

int main()
{
	std::vector<double> v {1,2,3,4,5};
	std::list<double> l {10,11,12,13,14,15};
	Vector_iterator vi {v};
	List_iterator li {l};
	print(vi);
	std::cout << std::endl;
	print(li);
}
