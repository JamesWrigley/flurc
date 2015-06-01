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

template<typename Data>
flurc<Data>::flurc(int size) {
    // We use the one-extra-slot approach to distinguish between full and empty
    // buffers.
    buffer.reserve(size + 1);
    write = buffer.begin();
    read = buffer.begin();
}

template<typename Data>
bool flurc<Data>::empty() {
    return std::distance(write, read) == 0;
}

template<typename Data>
bool flurc<Data>::full() {
    int distance = std::distance(write, read);
    return distance == 1 || distance == -(buffer.capacity() - 1);
}

template<typename Data>
bufferIterator<Data> flurc<Data>::increment(bufferIterator<Data> iterator) {
    if (iterator == --buffer.end()) {
        return buffer.begin();
    } else {
        return ++iterator;
    }
}

template<typename Data>
int flurc<Data>::length() {
    return std::distance(read, write);
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
