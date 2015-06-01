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
using bufferIterator = typename std::vector<Data>::iterator;

template<typename Data>
class flurc {
  public:
    flurc(int);

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

#include "flurc.cpp"

#endif
