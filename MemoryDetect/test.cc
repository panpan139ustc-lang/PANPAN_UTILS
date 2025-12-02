#include <iostream>
#include <memory>
#include <mutex>

//open the mutton of memory detecting
#define ENABLE_DEBUG_NEW
#include "MemoryDetect.h"

#ifdef ENABLE_DEBUG_NEW
#  define new DEBUG_NEW
#endif

struct A {
	int a;
};

int main() {
	printf("memory detect\n");

	new_autocheck_flag = true;
	//new_verbose_flag = true;
	int* ptr1 = new int;
	delete ptr1;

	int* ptr2 = new int[4];
	delete[] ptr2;

	A* a1 = new A;
	//delete a1
	A* a2 = new A;
	delete a2;

	{ std::shared_ptr<A> a = std::make_shared<A>(); }

	checkLeaks();

	return 0;



}