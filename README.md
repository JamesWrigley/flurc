# flurc
A header-only library implementing a circular buffer, written in C++.

Functions provided:
* flurc(int `size`) - Throws `std::invalid_argument` if `size` is negative
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
  flurc<int> foo(3);
  foo.push(2);
  foo.push(4);
  foo.push(8);

  while (!foo.empty())
    {
      std::cout << foo.pop() << std::endl;
    }
}
```