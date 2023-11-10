#include <iostream>
#include <thread>

#include "thread_safe_queue.h"

thread_safe_queue<int> queue;

void pop_thread()
{
	int value;
	queue.wait_pop(value);
	std::cout << value << std::endl;

}

void push_thread()
{
	int x = 10;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	queue.push(x);
}

int main()
{
	std::thread thread_1(pop_thread);
	std::thread thread_2(push_thread);

	thread_1.join();
	thread_2.join();
}