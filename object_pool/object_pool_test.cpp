#include "object_pool.h"
#include <iostream>
#include <stdio.h>

class Test
{
public:
	Test()
	{
		//std:cout<<"Test::Test()"<<std::endl;
		printf("Test::Test()");
	}
};

int main(int argc, char const *argv[])
{
	ObjectPool<Test> pool;
	pool.GetPoolSize();
	for (int i = 0; i < 100; ++i)
	{
		pool.GetObject();
	}
	

	return 0;
}