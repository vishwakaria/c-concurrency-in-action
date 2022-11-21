// Listing 2.3 Using RAII to wait for a thread to complete

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

class thread_guard {
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_):
        t(t_) {}
    ~thread_guard() {
        std::cout << "~thread_guard " << std::endl;
        if (t.joinable()) {
            std::cout << "Joining thread" << std::endl;
            t.join();
        }
    }
    thread_guard(thread_guard const&) = delete;
    thread_guard& operator=(thread_guard const&) = delete;
};

void f() {
    int local_state = 10; 
    func myfunc(local_state); // Creates func obj with i = 10
    std::thread t(myfunc);
    thread_guard g(t);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    throw std::runtime_error("Let's see if the thread joins.");
}

int main() 
{
  f(); 
  return 0;
}
