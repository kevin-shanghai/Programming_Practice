#include <iostream>
#include "Exception.h"
#include <stdio.h>
using namespace std;

class Test
{
public:
	void test()
	{
		throw Exception("test");
	}
};

void fun()
{
	Test t;
	t.test();
}

int main(int argc, char const *argv[])
{
	try
	{
		fun();
	}

	catch(Exception& ex)
	{
		printf("reason: %s\n", ex.what());
    	printf("stack trace: %s\n", ex.StackTrace());
	}
	return 0;
}