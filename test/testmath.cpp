#include "../src/math/includes.h"

#include <iostream>

int main()
{
    math::Vector<int, 10> v1;
    v1[9] = 9;

    const int vectorData[3] = { 15, 30, 45 };
    math::Vector3<int> v2(vectorData);
    math::Vector3D v3;

    // v1.getX();
    v2.setX(35);
    v2.refX() = -99;
    std::cout << v2.getX() << std::endl;

    return 0;
}
