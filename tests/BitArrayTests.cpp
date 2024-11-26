#include "gtest/gtest.h"
#include "BitArray.h"

// Тест конструктора
TEST(BitArrayConstructor, DefaultSize) {
    BitArray arr(10, 5); // 10 бит, первые 5 = 101
    EXPECT_EQ(arr.size(), 10);
    EXPECT_EQ(arr[0], true);  // Первый бит = 1
    EXPECT_EQ(arr[1], false); // Второй бит = 0
}

// Тест методов
TEST(BitArrayMethods, SetAndReset) {
    BitArray arr(10);
    arr.set(0);
    EXPECT_EQ(arr[0], true); // Первый бит = 1
    arr.reset(0);
    EXPECT_EQ(arr[0], false); // Первый бит = 0
}

// Тест операций
TEST(BitArrayOperations, BitwiseAnd) {
    BitArray arr1(8, 0b1100); // Биты: 1100
    BitArray arr2(8, 0b1010); // Биты: 1010
    arr1 &= arr2;            // Биты: 1000
    EXPECT_EQ(arr1.to_string(), "00001000");
}
