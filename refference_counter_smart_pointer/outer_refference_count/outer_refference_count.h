#include <iostream>
template <class T>
class shared_ptr
{
public:
	shared_ptr(T* ref)
	{
		if (ref != NULL)
		{
			m_pRawObjectPtr = ref;
			m_oHolder.AddRefCount();
		}
	}

	shared_ptr(const T& ref)
	{
		if (this->m_pRawObjectPtr != ref.get())
		{
			m_oHolder.AddRefCount();
		}
	}

	~shared_ptr()
	{
		if (this->m_pRawObjectPtr != NULL && m_oHolder.SubRefCount() == 0)
		{
			delete m_pRawObjectPtr;
			m_pRawObjectPtr = NULL;
		}
	}

	T* operator->() const 
	{
		return m_pRawObjectPtr;
	}

	T& operator*() const
	{
		return *m_pRawObjectPtr;
	}

	T* get() const
	{
		if (this->m_pRawObjectPtr != NULL)
		{
			return this->m_pRawObjectPtr;
		}
	}

	const int use_count() const
	{
		return m_oHolder.GetRefCount();
	}

	class Holder
	{
	public:
		Holder():m_iRefCount(0)
		{

		}

		int AddRefCount()
		{
			++m_iRefCount;
			return m_iRefCount;
		}

		int SubRefCount()
		{
			--m_iRefCount;
			return m_iRefCount;
		}

		const int GetRefCount() const
		{
			return m_iRefCount;
		}

	private:
		int m_iRefCount;
	};

private:
	Holder m_oHolder;
	T* m_pRawObjectPtr;
};