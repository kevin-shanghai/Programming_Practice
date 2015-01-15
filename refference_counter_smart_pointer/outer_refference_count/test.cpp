#include "outer_refference_count.h"
#include <iostream>

class Test
{
public:
	Test()
	{
		std::cout<<"Test::Test()"<<std::endl;
	}

	~Test()
	{
		std::cout<<"Test::~Test()"<<std::endl;
	}

	void print()
	{
		std::cout<<"Test::print()"<<std::endl;
	}
	
};

int main(int argc, char const *argv[])
{
	shared_ptr<Test> sp(new Test);
	sp->print();
	Test* p = sp.get();
	p->print();
	(*sp).print();
	return 0;
}