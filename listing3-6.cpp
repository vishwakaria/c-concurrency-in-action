// Listing 3.6 Using std::lock and std::lock_guard in a swap operation
#include <iostream>
#include <list>
#include <mutex>
#include <algorithm>
#include <thread>


class X {
    private:
        int detail;
        std::mutex m;
    public:
        X(int const& d): detail(d) {}
        friend void swap(X& lhs, X& rhs) {
            if (&lhs == &rhs) return;
            std::lock(lhs.m, rhs.m);
            std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock);
            std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock);
            std::swap(lhs.detail, rhs.detail);
        }    
};

int main()
{
    
    return 0;
}

