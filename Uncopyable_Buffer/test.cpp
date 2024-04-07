/**
 * @file test.cpp
 * @author your name (Marcus.Asberg.98@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-12-01
 *
 * @copyright Copyright (c) 2024
 * g++ test.cpp -o main && ./main
 */

#include <iostream>
#include <cassert>
#include "buffer.h"

int main(void)
{
    buffer_t<int, 8> buff;

    buff.write(1);
    buff.write(2);
    buff.write(3);
    buff.write(4);

    assert(4 == buff.elements());
    buff.clear();
    assert(0 == buff.elements());

    std::cout << "Testing buffer.write function...... test passed." << std::endl;

    buff.write(1);
    buff.write(2);
    buff.write(3);
    buff.write(4);

    buff.read();
    buff.read();

    assert(2 == buff.elements());

    buff.clear();
    assert(0 == buff.elements());

    std::cout << "Testing buffer read function...... test passed." << std::endl;
    std::cout << "Testing buffer elements function...... test passed." << std::endl;
    std::cout << "Testing buffer clear function...... test passed." << std::endl;

    assert(0 == buff.full());

    buff.write(1);
    buff.write(2);
    buff.write(3);
    buff.write(4);
    buff.write(1);
    buff.write(2);
    buff.write(3);
    buff.write(4);

    assert(1 == buff.full());
    buff.clear();

    std::cout << "Testing buffer full function...... test passed." << std::endl;

    buff.write(1);
    buff.write(2);
    buff.write(3);
    buff.write(4);

    assert(2.5 == buff.average());

    std::cout << "Testing buffer avarage function...... test passed." << std::endl;

    std::cout << buff << std::endl;

    std::cout << "Testing overwrite functions .... test passed." << std::endl;

    buff.clear();

    std::cout << "All test passed." << std::endl;

    return 0;
}