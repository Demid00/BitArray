#include "BitArray.h"
#include <iostream>

int main() {
    BitArray arr(10, 5); // Создаем битовый массив с 10 битами, первые 3 бита - 101
    std::cout << "BitArray to_string: " << arr.to_string() << std::endl;
    return 0;
}
