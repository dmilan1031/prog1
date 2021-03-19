#include "Simple_window.h"
#include "Graph.h"

class A
{
protected:
	A();
};

int main()
{
	A a;
	//csak A leszármazottai férnek hozzá a konstruktorához
	//absztrakt osztályt még lehetne pure virtual function-nel deklarálni
}