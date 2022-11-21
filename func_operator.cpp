#include <iostream>       // std::cout

class Point {
    private:
        int x, y;
    public:
        int operator()() {
            return x*y;
        }
        Point(int x1, int y1) {
            x = x1;
            y = y1;
        }
};

int main()
{
  Point p(1,2);
  std::cout << "p() = " << p() << std::endl;
  return 0;
}
