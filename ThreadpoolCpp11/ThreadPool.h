#ifndef THREAD_POOL_H__
#define THREAD_POOL_H__

#include "BoundedBlockingQueue.h"
#include <thread>
#include <memory>
#include <atomic>
#include <functional>


class ThreadPool
{
	typedef std::shared_ptr<std::thread> threadPtr;
	using threadFuncCallback = std::function<void()>;

public:
	ThreadPool(int threadNum = 10) 
			  : m_iThreadNum(threadNum)
			  , m_threadFuncQueue(10)
	{
		startAllThread(m_iThreadNum);
	}

	~ThreadPool()
	{

	}

	void AddTask(threadFuncCallback&& task)
	{
		m_threadFuncQueue.Put(task);
	}

	void Stop()
	{
		m_brunning = false;
		for (auto thd: m_threadQueue)
		{
			thd->join();
		}
	}

private:
	void startAllThread(int numThreads)
	{
		m_brunning = true;
		for (int i=0; i<numThreads; i++)
		{
			std::cout << "startAllThread, push_back a new thread...." << std::endl;
			m_threadQueue.push_back(std::make_shared<std::thread>(&ThreadPool::RunInThread, this));
		}
		
	}

	void RunInThread(void)
	{
		while (m_brunning)
		{
			auto task = m_threadFuncQueue.Take();
			task();
		}
	}


private:
	int m_iThreadNum;
	std::deque<threadPtr> m_threadQueue;
	std::atomic_bool m_brunning;
	BoundedBlockingQueue<threadFuncCallback> m_threadFuncQueue;

};

#endif