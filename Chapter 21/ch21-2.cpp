#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <numeric>

void read(std::map<std::string,int>& msi)
{
	std::string s;
	int i;
	std::cin >> s >> i;
	msi.insert(std::pair<std::string,int>(s,i));
}

int main()
{
	//1-2
	std::map<std::string,int> msi;
	auto it = msi.begin(); //std::map<string,int>::iterator
	std::vector<std::string> str = {"a","b","c","d","e","f","g","h","i","j"};
	for(int i = 1; i <= 10; i++)
	{
		msi.insert(std::pair<std::string,int>(str[i-1],i));
	}

	//3
	for(auto p : msi) std::cout << p.first << " " << p.second << '\n';

	//4
	msi.erase(msi.begin(),msi.end());

	//6
	for(int i = 0; i < 3; i++) read(msi);

	//7
	std::cout << '\n';
	for(auto p : msi) std::cout << p.first << " " << p.second << '\n';

	//8-9
	std::map<int,std::string> mis;
	for(auto p : msi) mis.insert(std::pair<int,std::string>(p.second,p.first));

	//10
	std::cout << '\n';
	for(auto p : mis) std::cout << p.first << " " << p.second << '\n';
}