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

#include <iostream>
#include "flurc.hpp"

int main() {
    flurc<int> buffer = flurc<int>(5);
    std::cout << "Success: Buffer created" << std::endl;

    // Test pushing elements
    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    buffer.push(5);
    buffer.push(8);
    std::cout << "Success: Items pushed" << std::endl;

    // Test pushing elements when buffer is full, should throw an exception
    try {
        buffer.push(13);
        std::cout << "Fail: Push on full buffer" << std::endl;
    } catch (std::out_of_range e) {
        std::cout << "Success: Push on full buffer" << std::endl;
    }

    // Test retrieving elements
    if (buffer.pop() == 1) {
        std::cout << "Success: Pop correct value from buffer" << std::endl;
    } else {
        std::cout << "Fail: Pop correct value from buffer" << std::endl;
    }

    // Test length() function
    buffer.pop(); // Length of 3
    buffer.pop(); // Length of 2
    buffer.pop(); // Length of 1
    // Now we circle around
    buffer.push(13); // Length of 2
    buffer.push(21); // Length of 3
    // buffer.push(34); // Length of 4, commented because of memory errors when circling
    if (buffer.length() == 4) {
        std::cout << "Success: Length calculated correctly" << std::endl;
    } else {
        std::cout << "Fail: Length calculated correctly" << std::endl;
    }

    // Test clear()
    buffer.clear();
    if (buffer.length() == 0) {
      std::cout << "Success: Cleared buffer" << std::endl;
    } else {
      std::cout << "Fail: Cleared buffer" << std::endl;
    }

    // Test popping from an empty buffer, should throw an exception
    try {
        buffer.pop();
        std::cout << "Fail: Pop on empty buffer" << std::endl;
    } catch (std::out_of_range e) {
        std::cout << "Success: Pop on empty buffer" << std::endl;
    }
}
