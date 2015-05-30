/*************************** Copyrights and License ******************************
 *                                                                                *
 * This file is part of flurc. http://github.com/JamesWrigley/flurc/              *
 *                                                                                *
 * flurc is free software: you can redistribute it and/or modify it under         *
 * the terms of the GNU Lesser General Public License as published by the Free    *
 * Software Foundation, either version 3 of the License, or (at your option) any  *
 * later version.                                                                 *
 *                                                                                *
 * flurc is distributed in the hope that it will be useful, but WITHOUT ANY       *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS      *
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more   *
 * details.                                                                       *
 *                                                                                *
 * You should have received a copy of the GNU Lesser General Public License along *
 * with flurc. If not, see <http://www.gnu.org/licenses/>.                        *
 *                                                                                *
 *********************************************************************************/

#ifndef FLURC_H
#define FLURC_H

#include <vector>

template<typename Data>
class flurc
{
  public:
    flurc(int);

    void push(Data);
    Data pop();
    bool empty();
    bool full();
    int length();

  private:
    void increment(typename std::vector<Data>::iterator);

    std::vector<Data> buffer;
    typename std::vector<Data>::iterator head;
    typename std::vector<Data>::iterator tail;
};

template<typename Data>
flurc<Data>::flurc(int size)
{
  // We use the one-extra-slot approach to distinguish between full and empty
  // buffers.
  buffer.reserve(size + 1);
  head = buffer.begin();
  tail = buffer.begin();
}

template<typename Data>
bool flurc<Data>::empty()
{
  return head == tail;
}

template<typename Data>
bool flurc<Data>::full()
{
  return std::distance(tail, head) == -1;
}

template<typename Data>
void flurc<Data>::increment(typename std::vector<Data>::iterator iterator)
{
  if (iterator == --buffer.end())
    {
      iterator = buffer.begin();
    }
  else
    {
      ++iterator;
    }
}

template<typename Data>
int flurc<Data>::length()
{
  return std::distance(tail, head);
}

template<typename Data>
Data flurc<Data>::pop()
{
  Data contents = *tail;
  increment(tail);
  return contents;
}

template<typename Data>
void flurc<Data>::push(Data contents)
{
  *head = contents;
  increment(head);
}

#endif
