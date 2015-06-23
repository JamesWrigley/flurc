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
#include <initializer_list>

template<typename Data>
using bufferIterator = typename std::vector<Data>::iterator;

template<typename Data>
class flurc {
  public:
    flurc(int);
    flurc(std::initializer_list<Data>);

    void clear();
    bool empty();
    bool full();
    int length();
    Data pop();
    void push(Data);

  private:
    bufferIterator<Data> increment(bufferIterator<Data>);

    std::vector<Data> buffer;
    bufferIterator<Data> read;
    bufferIterator<Data> write;
};

template<typename Data>
flurc<Data>::flurc(int size) {
    if (size < 0) {
        throw std::invalid_argument("Negative buffer size");
    }

    // We use the one-extra-slot approach to distinguish between full and empty
    // buffers.
    buffer.resize(size + 1);
    write = buffer.begin();
    read = buffer.begin();
}

template<typename Data>
flurc<Data>::flurc(std::initializer_list<Data> initial_values) {
    buffer.assign(initial_values);
    buffer.resize(buffer.size() + 1);
    write = --buffer.end();
    read = buffer.begin();
}

template<typename Data>
void flurc<Data>::clear() {
    read = buffer.begin();
    write = buffer.begin();
}

template<typename Data>
bool flurc<Data>::empty() {
    return std::distance(read, write) == 0;
}

template<typename Data>
bool flurc<Data>::full() {
    int distance = std::distance(read, write);
    return distance == -1 || distance == (signed int)buffer.capacity() - 1;
}

template<typename Data>
bufferIterator<Data> flurc<Data>::increment(bufferIterator<Data> iterator) {
    if (std::distance(iterator, --buffer.end()) == 0) {
        return buffer.begin();
    } else {
        return std::next(iterator);
    }
}

template<typename Data>
int flurc<Data>::length() {
    int distance = std::distance(read, write);

    if (distance < 0) {
        return std::distance(read, buffer.end()) +
            std::distance(buffer.begin(), write);
    } else {
        return distance;
    }
}

template<typename Data>
Data flurc<Data>::pop() {
    if (empty()) {
        throw std::out_of_range("Empty buffer");
    } else {
        Data contents = *read;
        read = increment(read);
        return contents;
    }
}

template<typename Data>
void flurc<Data>::push(Data contents) {
    if (full()) {
        throw std::out_of_range("Full buffer");
    } else {
        *write = contents;
        write = increment(write);
    }
}

#endif
