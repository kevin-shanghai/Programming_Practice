#include <iostream>
#include <stack>
template <class T>
class Queue {
public:
    // Push element x to the back of queue.
    void push(T x) {
        m_stack1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
       if (m_stack2.empty())
       {
           while(!m_stack1.empty())
           {
                int temp = m_stack1.top();
                m_stack1.pop();
                m_stack2.push(temp);
           }
       }
       m_stack2.pop();
    }

    // Get the front element.
    T peek(void) {
        if (m_stack2.empty())
        {
            while(!m_stack1.empty())
            {
                int temp = m_stack1.top();
                m_stack1.pop();
                m_stack2.push(temp);
            }
        }
        return m_stack2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
       return m_stack2.empty() && m_stack1.empty(); 
    }

    
private:
    std::stack<T> m_stack1, m_stack2;
};

int main()
{

	Queue<int> qe;
	qe.push(3);
	qe.push(5);
	qe.push(6);
	std::cout << "qe.peek" << qe.peek() << std::endl;
}
