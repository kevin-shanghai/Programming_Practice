#ifndef BOUNDED_BLOCKING_QUEUE_H__
#define BOUNDED_BLOCKING_QUEUE_H__

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <deque>
#include <thread>


template <class T>
class BoundedBlockingQueue
{
public:
	BoundedBlockingQueue(int iQueueSize = 10)
						: m_iQueueMaxSize(iQueueSize)
	{

	}

	~BoundedBlockingQueue()
	{

	}

	void Put(T& value)
	{
		std::unique_lock<std::mutex> lock(m_oMutex);
		m_notFull.wait(lock, [this]{return !IsFull();});
		m_Queue.push_back(std::forward<T>(value));
		m_notEmpty.notify_all();
	}

	T Take()
	{
		std::unique_lock<std::mutex> lock(m_oMutex);
		m_notEmpty.wait(lock, [this] {return !IsEmpty();});
		T value = m_Queue.front();
		m_Queue.pop_front();
		m_notFull.notify_all();
		return value;
	}

	void Take(std::deque<T>& valueQueue)
	{
		std::unique_lock<std::mutex> lock(m_oMutex);
		m_notEmpty.wait(lock, [this] {!IsEmpty();});
		valueQueue =  std::move(m_Queue);
	}

	int Size() const
	{
		return m_Queue.size();
	}

	bool IsFull() const
	{
		if (m_iQueueMaxSize == this->Size())
		{
			std::cout << "BlockingQueue is full...." << std::endl;
		}
		return m_iQueueMaxSize == this->Size();
	}

	bool IsEmpty() const
	{
		if (m_Queue.empty())
		{
			std::cout << "buffer is empty, thread id is:" << std::this_thread::get_id() << std::endl;
		}
		return m_Queue.empty();
	}

private:
	std::mutex m_oMutex;
	std::deque<T> m_Queue;
	std::condition_variable m_notEmpty;
	std::condition_variable m_notFull;
	int m_iQueueMaxSize;
};

#endif