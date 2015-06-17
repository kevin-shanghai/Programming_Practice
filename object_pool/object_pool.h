#include <iostream>
#include <list>

template<class T, int PoolSize = 500>

class ObjectPool
{
public:
	explicit ObjectPool()
	{
		for (int i = 0; i < PoolSize; ++i)
		{
			T object;
			m_vecObjectPool.push_back(object);
		}
	}

	~ObjectPool()
	{
		m_vecObjectPool.clear();
	}

	T GetObject() 
	{
		GetPoolSize();
		T t = m_vecObjectPool.front();
		m_vecObjectPool.pop_front();
		return t;
	}

	void ReturnObject(T object) 
	{
		GetPoolSize();
		m_vecObjectPool.push_back(object);
	}

	int GetPoolSize() 
	{
		std::cout<<"m_vecObjectPool.size():"<<m_vecObjectPool.size()<<std::endl;
		return m_vecObjectPool.size();
	}


private:
	std::list<T> m_vecObjectPool;
};
