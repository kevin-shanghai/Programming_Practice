/**********************************************
 ******* g++ *.cpp -std=c++11 -lpthread //(g++ versiton > 4.8)
 * *******************************************/
#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <functional>
template<class T>
class Singleton
{
public:
    Singleton()
    {

    }
    
    template <typename... Args>
    static T* GetInstance(Args&&... args)
    {
       if(m_pInstance == NULL)
        {
            static std::mutex m_Mutex;
            std::lock_guard<std::mutex> lock(m_Mutex);
            if(m_pInstance == NULL)
            {
               m_pInstance = new T(std::forward<Args>(args)...);
            }
        }
        return m_pInstance;
    }
private:
    static T* m_pInstance;
};

template<class T>
T* Singleton<T>::m_pInstance = NULL;

class Test
{
public:
    Test(const std::string& name):m_sName(name)
    {
        std::cout<<"Test::Test(), name is:" << m_sName << std::endl;
    }
private:
    std::string m_sName;
};

void CreateTestInstance()
{
    for (int i=0; i<10; i++)
        Test* t1 =  Singleton<Test>::GetInstance(std::string("Kevin"));
}

int main()
{
    std::thread t1(std::bind(CreateTestInstance));
    std::thread t2(std::bind(CreateTestInstance));
    t1.join();
    t2.join();
    return 0;
}
