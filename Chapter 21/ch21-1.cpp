#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>

struct Item
{
	Item(){}
	Item(int id, std::string n, double v) : iid{id}, name{n}, value{v} {}

	std::string name;
	int iid;
	double value;
};

int main()
{
	//1.
	std::vector<Item> v;
	std::ifstream fstr("item.txt"); //iid name value

	Item tmp;
	while(fstr >> tmp.iid >> tmp.name >> tmp.value) v.push_back(tmp);

	fstr.close();

	//2-4
	std::sort(v.begin(),v.end(), [](Item a, Item b){return a.name < b.name;});

	std::sort(v.begin(),v.end(), [](Item a, Item b){return a.iid < b.iid;});

	std::sort(v.begin(),v.end(), [](Item a, Item b){return a.value > b.value;});

	for(auto I : v) std::cout << I.name << " " << I.value << '\n';

	//5-7
	v.insert(v.end(), {99,"horse shoe",12.34});
	v.insert(v.end(), {99,"CanonS400",499.95});
	v.erase(std::find_if
		(
			v.begin(),v.end(),[](Item a){return a.name == "Fóka";}
		));
	v.erase(std::find_if
		(
			v.begin(),v.end(),[](Item a){return a.iid == 1;}
		));


	//Megismételve listával
	std::cout << '\n';

	//1.
	std::list<Item> l;
	std::ifstream fstr2("item.txt"); //iid name value

	Item tmp2;
	while(fstr2 >> tmp2.iid >> tmp2.name >> tmp2.value) l.insert(l.end(),tmp2);

	fstr2.close();

	//2-4
	l.sort([](Item a, Item b){return a.name < b.name;});

	l.sort([](Item a, Item b){return a.iid < b.iid;});

	l.sort([](Item a, Item b){return a.value > b.value;});

	for(auto I : l) std::cout << I.name << " " << I.value << '\n';

	//5-7
	l.insert(l.end(), {99,"horse shoe",12.34});
	l.insert(l.end(), {99,"CanonS400",499.95});
	l.erase(std::find_if
		(
			l.begin(),l.end(),[](Item a){return a.name == "Fóka";}
		));
	l.erase(std::find_if
		(
			l.begin(),l.end(),[](Item a){return a.iid == 1;}
		));
}