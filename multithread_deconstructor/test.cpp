#include <iostream>
#include <pthread.h>
#include <boost/shared_ptr.hpp>
using namespace std;

class Foo
{
public:
	Foo()
	{
		cout<<"Foo()."<<endl;
    };
	~Foo()
	{
		cout<<"~Foo()."<<endl;
	}
	void update()
	{
		cout<<"update()."<<endl;
	}

	void GetValueI()
	{
		cout<<"member value i is:"<<i<<endl;
	}

private:
	int i;

};

Foo* foo = new Foo; //global pointer

void* thread1_function(void*)
{
	cout<<"In thread1_function(), we will delete the object foo."<<endl;
	delete foo;
	foo = NULL;
}

void *thread2_function(void*)
{
	cout<<"In thread2_function, we will excute the member functon void GetValueI()."<<endl;
	foo->GetValueI();
}

int main(int argc, char const *argv[])
{
	cout<<"Entering main, This program is for the deconstructor when in the multithread condition."<<endl;
	 pthread_t thread1, thread2;
	 pthread_create(&thread1, NULL, &thread1_function, NULL);
	 pthread_create(&thread2, NULL, &thread2_function, NULL);
	 sleep(1);
	return 0;
}
