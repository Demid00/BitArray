#include "BitArray.h"
#include <iostream>

int main() {
    BitArray arr(10, 5); // ������� ������� ������ � 10 ������, ������ 3 ���� - 101
    std::cout << "BitArray to_string: " << arr.to_string() << std::endl;
    return 0;
}
