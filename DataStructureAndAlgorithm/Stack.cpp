#include <iostream>

template <class T>
class Statck
{
public:
	Statck(int iCapacity): m_iTop(0)
			, m_iCapacity(iCapacity)
			, m_tElements(new T[m_iCapacity])
	{	

	}

	~Statck()
	{
		delete[] m_tElements;
		m_tElements = NULL;
	}

	bool IsFull()
	{
		return m_iTop >= m_iCapacity;
	}

	bool IsEmpty()
	{
		return m_iTop == 0;
	}

	void Push(T value)
	{
		if (!IsFull())
		{
			m_tElements[m_iTop] = value;
			std::cout << "push value..." << std::endl;
			m_iTop++;
		}
	}

	T Pop()
	{
		if (!IsEmpty())
		{
			m_iTop--;
			T tempValue = m_tElements[m_iTop];
			std::cout << "pop value..." <<std::endl;
			return tempValue;
		}
		else
		{
			return 0;
		}
	}

	int GetSize()
	{
		return m_iTop;
	}

	int GetCapacity()
	{
		return m_iCapacity;
	}
	
private:
	T* m_tElements;
	int m_iTop;
	int m_iCapacity;
};


int main(int argc, char const *argv[])
{
	Statck<int> st(5);
	st.Push(10);
	st.Push(11);
	std::cout << "st.size():" << st.GetSize() << std::endl;
	std::cout << "st.Pop():" << st.Pop() << std::endl;
	std::cout << "st.size():" << st.GetSize() << std::endl;
	std::cout << "st.Pop():" << st.Pop() << std::endl;
	std::cout << "st.size():" << st.GetSize() << std::endl;
	st.Push(111);
	std::cout << "st.size():" << st.GetSize() << std::endl;
	return 0;
}