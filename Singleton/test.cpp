#include <iostream>
#include <pthread.h>
using namespace std;
template <class T>
class Singleton
{
public:
    Singleton()
    {

    }

    static T* GetInstance()
    {
       if(m_pInstance == NULL)
        {
            pthread_mutex_lock(&m_Mutex);
            if(m_pInstance == NULL)
            {
                T* temp = new T;
                m_pInstance = temp;
            }
            pthread_mutex_unlock(&m_Mutex);
        }
        return m_pInstance;
    }
private:
    static T* m_pInstance;
    static pthread_mutex_t m_Mutex;
};

template<class T>
T* Singleton<T>::m_pInstance = NULL;

template<class T>
pthread_mutex_t Singleton<T>::m_Mutex;

class Test:public Singleton<Test>
{
    
};

int main()
{
    Test *test1 = Test::GetInstance();
    Test *test2 = Test::GetInstance();
    cout<<"test1:"<<test1<<endl<<"test2:"<<test2<<endl;
    return 0;
}
