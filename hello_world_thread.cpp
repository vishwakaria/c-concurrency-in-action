#include <iostream>
#include <thread>

void display_message() {
	std::cout << "Hello World!\n";
}

int main() {
	std::thread t(display_message);
	t.join();
	return 0;
}
