#include "BoundedBlockingQueue.h"
#include "ThreadPool.h"
#include <thread>
#include <chrono>

int main(int argc, char const *argv[])
{
	std::shared_ptr<int> sp(new int(3));
	std::make_shared<int>(3);
	BoundedBlockingQueue<int> taskQueue(10);
	std::deque<int> myQueue;
	ThreadPool pool;
	for (int i=0; i<10; i++)
	{
		std::cout << "pool.AddTask, num of put task is:" << i << std::endl;
		pool.AddTask([]{
			while(1)
			{
				std::cout << "thread id:" << std::this_thread::get_id() << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			}
		});
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	std::this_thread::sleep_for(std::chrono::seconds(1000));

	return 0;
}