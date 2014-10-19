#include <iostream>

using namespace std;

class Test
{
public:
	Test()
	{
		cout<<"Test()"<<endl;
	}

	~Test()
	{
		cout<<"~Test()"<<endl;
	}

	void print()
	{
		cout<<"Test::print()."<<endl;
	}

};

class Test1
{
public:
	Test1()
	{
		cout<<"Test1::Test1()."<<endl;
	}

	~Test1()
	{
		cout<<"Test1::~Test1()."<<endl;
	}

	void SayHello()
	{
		cout<<"Test1::SayHello()."<<endl;
	}
};


template<class T>

class TestPtr
{
public:
	explicit TestPtr(T* pTest):m_pTest(pTest)
	{

	}

	~TestPtr()
	{
		delete m_pTest;
	}

	T* operator -> () const
	{
		return Get();
	}

	T& operator * () const
	{
		return *Get();
	}

	T* Get() const
	{
		return m_pTest;
	}

private:
	T* m_pTest;
};

int main(int argc, char const *argv[])
{
	TestPtr<Test> testptr(new Test);
	Test1* test1 = new Test1();
	TestPtr<Test1> testptr1(test1);
	testptr->print();
	(*testptr1).SayHello();
	return 0;
}
