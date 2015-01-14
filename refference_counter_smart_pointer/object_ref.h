/*************************************************************************
	> File Name: object_ref.h
	> Author: kevinfu
	> Mail: kevinfu1985@gmail.com
	> Created Time: Tue 13 Jan 2015 10:29:13 PM CST
 ************************************************************************/
#include <iostream>
#include <assert.h>

class RefObject
{
public:
    RefObject():iRefCount_(0)
    {
    }

    virtual ~RefObject()
    {
    }

    int AddRefCount()
    {
        ++iRefCount_;
        return iRefCount_;
        std::cout<<"In AddRefCount:iRefCount_ is:"<<iRefCount_<<std::endl;
    }

    int SubRefCount()
    {
        --iRefCount_;
        return iRefCount_;
        std::cout<<"In SubRefCount:iRefCount_ is:"<<iRefCount_<<std::endl;
    }

    const int GetRefcount() const
    {
        return iRefCount_;
    }

private:
    int iRefCount_;
};



template <class T>
class shared_ptr
{
public: 
    explicit shared_ptr(T* ref = NULL)
    {
       if(ref != NULL)
       {
            m_pRawObject = ref;
            m_pRawObject->AddRefCount();
       }
    }

    shared_ptr(const shared_ptr& ref)
    {
       m_pRawObject = ref.m_pRawObject;
       if(m_pRawObject != NULL)
       {
           m_pRawObject->AddRefCount();
       }
    }

    ~shared_ptr()
    {
      if (m_pRawObject != NULL && m_pRawObject->SubRefCount() == 0)
      {
          delete m_pRawObject;
          m_pRawObject = NULL;
      }
    }

    T* operator->() const
    {
        return m_pRawObject;
    }


    T& operator*() const
    {
        return *m_pRawObject;
    }

    T& operator=(const shared_ptr& ref)
    {
        if (this!=ref)
        {
            m_pRawObject = ref.m_pRawObject;
            if (m_pRawObject != NULL)
            {
                m_pRawObject->AddRefCount();
            }
            
        }
    }

    T* get() const
    {
        return m_pRawObject;
    }

    int use_count() const
    {
        return m_pRawObject->GetRefcount();
    }

private:
    T* m_pRawObject;
};


