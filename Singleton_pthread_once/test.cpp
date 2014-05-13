#include <iostream>
#include <pthread.h>
using namespace std;
template<class T>
class Singleton
{
public:
	static T& instance()
	{
        pthread_once(&m_Once, &Singleton::init);
        return *m_tValue;
    }

private:
	Singleton();
	~Singleton();
	static void init()
	{
		m_tValue = new T();
	}

private:
	static pthread_once_t m_Once;
	static T* m_tValue;
};

template<class T>
pthread_once_t Singleton<T>::m_Once = PTHREAD_ONCE_INIT;

template<class T>
T* Singleton<T>::m_tValue = NULL;


class Test
{
public:
	Test()
	{
		cout<<"In Test::Test()."<<endl;
	}
};

void* thread_func(void*)
{
    Test& t = Singleton<Test>::instance();
}

int main(int argc, char const *argv[])
{
//	Test& t = Singleton<Test>::instance();
    pthread_t thread_id[10];
    for(int i=0;i<10;i++)
    {
        pthread_create(&thread_id[i], NULL, thread_func, NULL);
    }
	return 0;
}
