#include <iostream>       
#include <functional>     
#include <thread>        
#include <future>       
#include <stdexcept>

void print_int(std::future<int>& fut) {
	std::cout << " print Thread started \n";
	//std::cout << "got the value in print thread: " << fut.get() << '\n';
    printf("got the value in print thread: %d \n", fut.get());
}

int main()
{
	std::promise<int> prom;
	std::future<int> fut = prom.get_future();

	std::thread print_thread(print_int, std::ref(fut));

	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	//std::cout << "\n setting promise the value in main thread \n";
    printf("\n setting promise the value in main thread \n");
	prom.set_value(10);

	print_thread.join();
}