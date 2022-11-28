// Listing 3.1 Protecting a list with a mutex

#include <iostream>
#include <list>
#include <mutex>
#include <algorithm>
#include <thread>

std::list<int> nums = {1,2,3};
std::mutex nums_mutex;

void add_to_list(int val) {
    std::cout << "Adding "<< val << " to list \n";
    std::lock_guard<std::mutex> guard(nums_mutex);
    nums.push_back(val);
}

bool list_contains(int val) {
    std::lock_guard<std::mutex> guard(nums_mutex);
    return std::find(nums.begin(), nums.end(), val) != nums.end();
}

void print_list() {
    std::cout << "Printing list \n";
    std::lock_guard<std::mutex> guard(nums_mutex);
    for (auto const &i: nums) {
        std::cout << i << "\t";
    }
    std::cout << std::endl;
}

void perform_list_ops() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    add_to_list(3);
    add_to_list(7);
    print_list();
    std::cout << "Found 5 in list = " << list_contains(5) << std::endl;
    add_to_list(5);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

int main()
{
    std::cout << "Creating threads \n";
    std::thread t1(perform_list_ops);
    std::thread t2(perform_list_ops);
    t1.join();
    t2.join();
    return 0;
}

