#ifndef BITARRAY_H
#define BITARRAY_H

#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>
#include <algorithm>

// ����� BitArray ������������ ������� ������ ����������� �������
class BitArray {
public:
    // ������������ � ����������
    BitArray(); // ����������� �� ���������, ������� ������ ������� ������
    explicit BitArray(int num_bits, unsigned long value = 0); // ������� ������ �� num_bits, �������������� ������ sizeof(long) ���
    BitArray(const BitArray& b); // ����������� �����������
    ~BitArray() = default; // ���������� �� ���������

    // ���������� ���������� �������� ������� � ������
    void swap(BitArray& b);

    // �������� ������������
    BitArray& operator=(const BitArray& b);

    // �������� ������ �������, ��������/������ ����
    void resize(int num_bits, bool value = false);

    // ������� ��� �������� �������
    void clear();

    // ��������� ����� ��� � ����� �������
    void push_back(bool bit);

    // ��������� ��������
    BitArray& operator&=(const BitArray& b); // ��������� �������� � � ������ ��������
    BitArray& operator|=(const BitArray& b); // ��������� �������� ���
    BitArray& operator^=(const BitArray& b); // ��������� �������� ������������ ���

    // ������ ��������� ��������, ������������ ����� ������
    BitArray operator&(const BitArray& b) const; // ���������� ��������� �
    BitArray operator|(const BitArray& b) const; // ���������� ��������� ���
    BitArray operator^(const BitArray& b) const; // ���������� ��������� ������������ ���

    // ��������� ������
    BitArray& operator<<=(int n); // �������� ������� ������ �����
    BitArray& operator>>=(int n); // �������� ������� ������ ������
    BitArray operator<<(int n) const; // ���������� ��������� ������ �����
    BitArray operator>>(int n) const; // ���������� ��������� ������ ������

    // ������ ��������� � ������ �����
    BitArray& set(int n, bool val = true); // ������������� ��� � �������� n � �������� val
    BitArray& set(); // ������������� ��� ���� � 1
    BitArray& reset(int n); // ������������� ��� � �������� n � 0
    BitArray& reset(); // ���������� ��� ���� (������������� � 0)

    // �������� ��������� �����
    bool any() const; // ���������, ���� �� ���� �� ���� ���, ������ 1
    bool none() const; // ���������, ��� �� ���� ����� 0

    // �������� �����
    BitArray operator~() const; // ���������� ������ � ���������������� ������

    // ������� ���������� ��������� ���
    int count() const;

    // ������ � ���� �� ������� (������ ������)
    bool operator[](int i) const;

    // ��������� ���������� � �������
    int size() const; // ���������� ���������� ��� � �������
    bool empty() const; // ���������, ���� �� ������

    // ���������� ��������� ������������� �������
    std::string to_string() const;

    friend bool operator==(const BitArray& a, const BitArray& b); // ��������� ��������� ��������
    friend bool operator!=(const BitArray& a, const BitArray& b); // ��������� ����������� ��������

private:
    std::vector<bool> bits; // ���������� ��������� �����, ����������� ����� std::vector<bool>

    // ������ ��� ������� � ����������� ������� ����� (�������� ��������� ������ �������)
    const std::vector<bool>& get_bits() const { return bits; }

    void check_index(int index) const; // �������� ������������ �������
};


#endif // BITARRAY_H
