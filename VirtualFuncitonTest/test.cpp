#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout<<"In Base()"<<endl;
		TestVirtual(33);
	}
	virtual void TestVirtual(int a)
	{
		cout<<"In Base::TestVirtual(int a)"<<endl;
	}

private:
	int m_i;
};

class Derived:public Base
{
public:
	virtual void TestVirtual(int dfd)
	{
		cout<<"In Derived::TestVirtual(string str)"<<endl;
		
	}
};

int main(int argc, char const *argv[])
{
	Base *base = new Derived();
	//base->TestVirtual(3);
	//base->TestVirtual("Hello");
	return 0;
}