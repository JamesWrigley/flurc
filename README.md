# flurc
A header-only C++ library implementing a circular buffer. Run `make; ./test` to
compile and run the test suite.

Requires: A C++11 compliant compiler (the test suite uses GCC by default).

Functions provided:
* **flurc**(int `size`) - Throws `std::invalid_argument` if `size` is negative
* **flurc**(std::initializer_list<T>)
* clear()
* empty()
* full()
* length()
* pop() - Throws `std::out_of_range` if the buffer is empty
* push(T `t`) - Throws `std::out_of_range` if the buffer is full

Example usage:
```C++
#include <iostream>
#include "flurc.hpp"

int main()
{
  flurc<int> foo(3); // Or, flurc<int> foo{ 2, 4, 8 }
  foo.push(2);
  foo.push(4);
  foo.push(8);

  while (!foo.empty())
    {
      std::cout << foo.pop() << std::endl;
    }
}
```