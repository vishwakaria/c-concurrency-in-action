// Listing 2.1 A function that returns while the thread still has access to local variables

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

int main() 
{
  int local_state = 10; 
  func myfunc(local_state); // Creates func obj with i = 10
  std::thread mythread(myfunc);
  std::this_thread::sleep_for (std::chrono::milliseconds(100));
  mythread.detach(); 
  return 0;
}
