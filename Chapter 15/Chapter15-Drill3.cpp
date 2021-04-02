#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <vector>

using namespace Graph_lib;

struct Person
{
	Person() { };
	Person(string fn, string sn, int aa) : first_n{fn}, second_n{sn}, a{aa}
	{
		if(a < 0 || a > 149) error("Rossz életkor");
		vector<char> v {';',':','"','\'','[',']','*','&','^','%','$','#','@','!'};
		for(int i = 0; i < v.size(); i++)
		{
			if(first_n.find(v[i]) != string::npos || second_n.find(v[i]) != string::npos) error("Rossz név");
		}
	}
	Person(string n, int aa) { error("Két nevet kell megadni"); }
	int age() const { return a; }
	string first_name() const { return first_n; }
	string second_name() const { return second_n; }
private:
	string first_n;
	string second_n;
	int a;
};

//formátum: (Firstname,Secondname,age)

ostream& operator << (ostream& os, Person& p)
{
	os << "(" << p.first_name() << "," << p.second_name() << "," << p.age() << ")";
	return os;
}

istream& operator >> (istream& is, Person& p)
{
	string fn, sn;
	int age;

	char ch;
	if(is >> ch && ch != '(')
	{
		is.unget();
		std::cin.clear(ios_base::failbit);
		return is;
	}

	//az elválasztók közötti karaktereket hozzáfűzzük az fn és sn-hez

	while(is >> ch && ch!=',') //first_name
	{
		fn.push_back(ch);
		if(!is)
		return is;
	}

	while(is >> ch && ch!=',') //second_name
	{
		sn.push_back(ch);
		if(!is)
		return is;
	}

	is >> age >> ch; //age és zárójel
	if(!is)
	{
		return is;
	}

	p = Person{fn,sn,age};
	return is;
}

int main()
{
	//Person goofy { "Goofy", 63 };
	//std::cout << goofy.name() << ", " << goofy.age() << std::endl;

	vector<Person> v;
	Person p;

	while(std::cin>>p)
	{
		v.push_back(p);
	}

	std::cout << std::endl;

	for(int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
}