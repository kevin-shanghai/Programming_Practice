#include <iostream>

template <class Type>
struct ListNode
{
	Type data;
	ListNode* pNext;
};

template <class T>

class List
{
public:
	List():m_pListHead(NULL)
	{
	}

	ListNode<T>* CreateLinkedList()
	{
		ListNode<T>* p1;
		ListNode<T>* p2;
		m_pListHead = new ListNode<T>();
		m_pListHead->pNext = NULL;
		p1 = m_pListHead;
		while (1)
		{
			T tmp;
			std::cout << "Please input the Node data:" << std::endl;
			std::cin >> tmp;
			if (tmp == 0)
			{
				break;
			}
			p2 = new ListNode<T>();
			p2->data = tmp;
			p1->pNext = p2;
			p1 = p1->pNext;
		}
		return m_pListHead;
	}

	void PrintList(ListNode<T>* pHead)
	{
		if (pHead == NULL)
		{
			return;
		}
		ListNode<T>* pTemp = pHead;
		while (pTemp != NULL)
		{
			std::cout << "ListNode data is:" << pTemp->data << std::endl;
			pTemp = pTemp->pNext;
		}
	}

	void Insert( ListNode<T>* pHead, T value, int insert_position)
	{
        if (pHead == NULL || insert_position < 0) return;
        ListNode<T>* p = pHead;
        while (--insert_position)
        {
            p = p->pNext;
        }
        ListNode<T>* pTemp = new ListNode<T>();
        pTemp->data = value;
        pTemp->pNext = p->pNext;
        p->pNext = pTemp;
	}

    void Delete( ListNode<T>* pHead, int delete_position)
    {
        if (pHead == NULL || delete_position < 0) return;
        ListNode<T>* p = pHead;
        while (--delete_position)
        {
            p = p->pNext;
        }
        ListNode<T>* pTemp = p->pNext;
        p->pNext = pTemp->pNext;
        delete pTemp;
        pTemp = NULL;
    }

    ListNode<T>* Reverse(ListNode<T>* pHead)
    {
        ListNode<T>* prev = NULL;
        ListNode<T>* next;
        if (pHead == NULL) return NULL;
        while(pHead != NULL)
        {
            next = pHead->pNext;
            pHead->pNext = prev;
            prev = pHead;
            pHead = next;
        }
        return prev;
    }
private:
	ListNode<T>* m_pListHead;
};

int main(int argc, char const *argv[])
{
	List<int> myList;
	std::cout << "Create linked list..." << std::endl;
	ListNode<int>* pHead = myList.CreateLinkedList();
	std::cout << "Print linked list..." << std::endl;
	myList.PrintList(pHead);
    std::cout << "Insert a node in the linked list..." << std::endl;
    myList.Insert(pHead, 5 , 2);
    myList.PrintList(pHead);
    std::cout << "Delte a node in the linked list..." << std::endl;
    myList.Delete(pHead, 3);
    myList.PrintList(pHead);
    std::cout << "Reverse the linked list..." << std::endl;
    ListNode<int>* pReversedHead = myList.Reverse(pHead);
    myList.PrintList(pReversedHead);
    
    return 0;
}
