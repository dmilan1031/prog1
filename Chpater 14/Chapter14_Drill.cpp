
#include <iostream>

class B1
{
public:
	virtual void pvf() =0;
	virtual void vf() { std::cout << "B1::vf ";};
	void f() { std::cout << "B1::f ";};
};

class D1 : public B1
{
public:
	void vf() { std::cout << "D1::v f ";};
	void f() { std::cout << "D1::f " ;};
};

class D2 : public D1
{
public:
	void pvf() { std::cout << "D2::pvf ";};
};

class B2
{
public:
	virtual void pvf() =0;
};

class D21 : public B2
{
public:
	void pvf() { std::cout << s;};
private:
	std::string s = "D ";
};

class D22 : public B2
{
public:
	void pvf() { std::cout << i;};
private:
	int i = 2;
};

void f(B2& b2r)
{
	b2r.pvf();
}

int main()
{
	/*//1.
	B1 b1;
	b1.vf();
	b1.f();
	
	//2.
	std::cout << std::endl;

	D1 d1;
	d1.vf();
	d1.f();

	//3.
	std::cout << std::endl;

	B1& b1r = d1;
	b1r.vf();
	b1r.f();*/

	//4.
	// A void f() nem virtuális függvény, ha D1-ben definiálva van, nem örökli B1::vf() definícióját
	// A B1 referencia, nem tudja, hogy D1-ben definiálva van az f(), B1 függvényét hívja meg

	//5.
	// Ha pvf() nincs override-olva, az osztály absztrakt marad, nem lehet pédánya

	//6.

	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();

	//7.
	std::cout << std::endl;

	D21 d21;
	D22 d22;
	f(d21);
	f(d22);
}