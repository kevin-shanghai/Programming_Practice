/*************************************************************************
	> File Name: Thread.cpp
	> Author: KevinFu
	> Mail: kevinfu1985@gmail.com 
	> Created Time: 2014年05月26日 星期一 20时41分07秒
 ************************************************************************/

#include<iostream>
#include <pthread.h>
#include <boost/function.hpp>
#include <boost/bind.hpp>

using namespace std;

class Thread
{
    typedef boost::function<void(void)> ThreadFunctionCallBack;
public:
    Thread(ThreadFunctionCallBack cb, string name = "Unknow")
        :m_cb(cb)
    {

    }
    ~Thread()
    {

    }

    void Start(void)
    {
        pthread_create(&m_ThreadID, NULL, ThreadFunction, this);
    }
	

    static void* ThreadFunction(void* obj)
    {
        Thread* thread = static_cast<Thread*>(obj);
        thread->m_cb();
    }

private:
    ThreadFunctionCallBack m_cb;
    pthread_t m_ThreadID;
};

class Test
{
public:
    void run(void)
    {
        cout<<"In test::run()"<<endl;
    }
};

int main()
{
    Test t;
    Thread thread1(boost::bind(&Test::run, &t));
    thread1.Start();
    usleep(1000);
}
