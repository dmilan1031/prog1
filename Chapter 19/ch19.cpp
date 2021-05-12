#include <string>
#include <vector>
#include <iostream>


template<typename T>
struct S
{
	S() {}
	S(T vl) : val{vl} {}

	T& get();
	const T& get() const;
	void operator=(const T& v);
	void set(T v);

private:
	T val;
};

template<typename T>
T& S<T>::get()
{
	return val;
}

template<typename T>
const T& S<T>::get() const
{
	return val;
}

template<typename T>
void S<T>::operator=(const T& v)
{
	val = v;
}

template<typename T>
void S<T>::set(T v)
{
	val = v;
}

template<typename T>
void read_val(T& v)
{
	std::cin >> v;
}

int main()
{
	//3.
	//S<int> si = S<int>(5);
	S<int> si(5);
	S<char> sc('a');
	S<double> sd(1.1);
	S<std::string> ss("string");
	S<std::vector<int>> sv({1,2,3,5,8,13});

	//4., 7.-ben változtatava
	std::cout << si.get() << '\n';
	std::cout << sc.get() << '\n';
	std::cout << sd.get() << '\n';
	std::cout << ss.get() << '\n';
	for(auto i : sv.get()) std::cout << i << ' ';
	std::cout << '\n';

	//13.
	read_val(si.get());
	read_val(sc.get());
	read_val(sd.get());
	read_val(ss.get());

}