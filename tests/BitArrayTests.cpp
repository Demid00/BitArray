#include "gtest/gtest.h"
#include "BitArray.h"

// ���� ������������
TEST(BitArrayConstructor, DefaultSize) {
    BitArray arr(10, 5); // 10 ���, ������ 5 = 101
    EXPECT_EQ(arr.size(), 10);
    EXPECT_EQ(arr[0], true);  // ������ ��� = 1
    EXPECT_EQ(arr[1], false); // ������ ��� = 0
}

// ���� �������
TEST(BitArrayMethods, SetAndReset) {
    BitArray arr(10);
    arr.set(0);
    EXPECT_EQ(arr[0], true); // ������ ��� = 1
    arr.reset(0);
    EXPECT_EQ(arr[0], false); // ������ ��� = 0
}

// ���� ��������
TEST(BitArrayOperations, BitwiseAnd) {
    BitArray arr1(8, 0b1100); // ����: 1100
    BitArray arr2(8, 0b1010); // ����: 1010
    arr1 &= arr2;            // ����: 1000
    EXPECT_EQ(arr1.to_string(), "00001000");
}
