// Listing 2.2 Waiting for a thread to finish

#include <iostream>       // std::cout
#include <thread>         // std::thread

struct func {
    int &i;
    func(int& i_) : i(i_) {
        std::cout << "i = " << i << std::endl;
    }
    void operator()() {
        for (int j = 0; j < 10000; j++) {
            std::cout << i << "\t";
        }
    }
};

void f() {
    int local_state = 10; 
    func myfunc(local_state); // Creates func obj with i = 10
    std::thread t(myfunc);
    try {
        throw std::runtime_error("Let's see if the thread joins.");
    } catch (...) {
        t.join();
        throw;
    }
    t.join();
}

int main() 
{
  f(); 
  return 0;
}
