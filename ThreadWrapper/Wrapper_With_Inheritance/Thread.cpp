/*************************************************************************
	> File Name: Thread.cpp
	> Author: KevinFu
	> Mail: kevinfu1985@gmail.com 
	> Created Time: 2014年05月26日 星期一 21时27分51秒
 ************************************************************************/

#include<iostream>
#include <pthread.h>


using namespace std;

class Thread
{
public:
    Thread(string name = "Unknown")
    {
    }
    virtual ~Thread()
    {

    }

    void Start()
    {
       pthread_create(&m_ThreadID, NULL, ThreadFunc, this); 
    }

    static void* ThreadFunc(void* pth)
    {
        Thread* p = static_cast<Thread*>(pth);
        p->Run();
    }

    virtual void Run() = 0;

private:
    pthread_t m_ThreadID;
};


class Test:public Thread
{
public:
    virtual void Run()
    {
        while(1)
        {
            cout<<"In Test::Run()"<<endl;
        }
    }
};
int main()
{
    Thread* thread1 = new Test();
    thread1->Start();
    sleep(1);
}
