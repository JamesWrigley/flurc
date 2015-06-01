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

    buffer.push(1);
    buffer.push(1);
    buffer.push(2);
    buffer.push(3);
    buffer.push(5);
    std::cout << "Success: Items pushed" << std::endl;

    try {
        buffer.push(8);
        std::cout << "Fail: Push on full buffer" << std::endl;
    } catch (std::out_of_range e) {
        std::cout << "Success: Push on full buffer" << std::endl;
    }

    int i = buffer.pop();
    if (i == 1) {
        std::cout << "Success: Pop correct value from buffer" << std::endl;
    } else {
        std::cout << "Fail: Pop correct value from buffer" << std::endl;
    }

    buffer.pop();
    buffer.pop();
    buffer.pop();
    buffer.pop();
    
    try {
        buffer.pop();
        std::cout << "Fail: Pop on empty buffer" << std::endl;
    } catch (std::out_of_range e) {
        std::cout << "Success: Pop on empty buffer" << std::endl;
    }
}
