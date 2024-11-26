#include "BitArray.h"

// Конструктор по умолчанию
BitArray::BitArray() : bits() {}

// Конструктор с количеством бит и значением
BitArray::BitArray(int num_bits, unsigned long value) {
    resize(num_bits); // Устанавливаем размер массива
    for (int i = 0; i < std::min(num_bits, static_cast<int>(sizeof(value) * 8)); ++i) {
        bits[i] = (value & (1UL << i)) != 0; // Устанавливаем соответствующий бит
    }
}

// Конструктор копирования
BitArray::BitArray(const BitArray& b) : bits(b.bits) {}

// Метод обмена содержимого массивов
void BitArray::swap(BitArray& b) {
    bits.swap(b.bits);
}

// Оператор присваивания
BitArray& BitArray::operator=(const BitArray& b) {
    if (this != &b) { // Проверка на самоприсваивание
        bits = b.bits;
    }
    return *this;
}

// Изменение размера массива
void BitArray::resize(int num_bits, bool value) {
    bits.resize(num_bits, value);
}

// Очистка массива
void BitArray::clear() {
    bits.clear();
}

// Добавление бита в конец
void BitArray::push_back(bool bit) {
    bits.push_back(bit);
}

// Операторы побитовых операций
BitArray& BitArray::operator&=(const BitArray& b) {
    if (size() != b.size()) throw std::invalid_argument("Sizes must match for AND operation.");
    for (size_t i = 0; i < bits.size(); ++i) {
        bits[i] = bits[i] && b.bits[i];
    }
    return *this;
}

BitArray& BitArray::operator|=(const BitArray& b) {
    if (size() != b.size()) throw std::invalid_argument("Sizes must match for OR operation.");
    for (size_t i = 0; i < bits.size(); ++i) {
        bits[i] = bits[i] || b.bits[i];
    }
    return *this;
}

BitArray& BitArray::operator^=(const BitArray& b) {
    if (size() != b.size()) throw std::invalid_argument("Sizes must match for XOR operation.");
    for (size_t i = 0; i < bits.size(); ++i) {
        bits[i] = bits[i] != b.bits[i];
    }
    return *this;
}

BitArray BitArray::operator|(const BitArray& b) const {
    BitArray result(*this);
    result |= b;
    return result;
}

BitArray BitArray::operator^(const BitArray& b) const {
    BitArray result(*this);
    result ^= b;
    return result;
}

BitArray& BitArray::operator<<=(int n) {
    if (n < 0) throw std::invalid_argument("Shift amount must be non-negative.");
    bits.insert(bits.begin(), n, false);
    bits.resize(bits.size() - n);
    return *this;
}

BitArray& BitArray::operator>>=(int n) {
    if (n < 0) throw std::invalid_argument("Shift amount must be non-negative.");
    bits.erase(bits.begin(), bits.begin() + std::min(n, size()));
    bits.insert(bits.end(), n, false);
    return *this;
}

BitArray BitArray::operator<<(int n) const {
    BitArray result(*this);
    return result <<= n;
}

BitArray BitArray::operator>>(int n) const {
    BitArray result(*this);
    return result >>= n;
}

BitArray& BitArray::set(int n, bool val) {
    check_index(n);
    bits[n] = val;
    return *this;
}

BitArray& BitArray::set() {
    std::fill(bits.begin(), bits.end(), true);
    return *this;
}

BitArray& BitArray::reset(int n) {
    return set(n, false);
}

BitArray& BitArray::reset() {
    std::fill(bits.begin(), bits.end(), false);
    return *this;
}

bool BitArray::any() const {
    return std::any_of(bits.begin(), bits.end(), [](bool b) { return b; });
}

bool BitArray::none() const {
    return !any();
}

BitArray BitArray::operator&(const BitArray& b) const {
    if (size() != b.size()) throw std::invalid_argument("Sizes must match for AND operation.");
    BitArray result(*this); // Создаем изменяемую копию
    result &= b;            // Применяем операцию AND
    return result;          // Возвращаем результат
}

int BitArray::count() const {
    return std::count(bits.begin(), bits.end(), true);
}

bool BitArray::operator[](int i) const {
    check_index(i);
    return bits[i];
}

int BitArray::size() const {
    return static_cast<int>(bits.size());
}

bool BitArray::empty() const {
    return bits.empty();
}

std::string BitArray::to_string() const {
    std::ostringstream oss;
    for (bool bit : bits) {
        oss << (bit ? '1' : '0');
    }
    return oss.str();
}

// Метод проверки индекса
void BitArray::check_index(int index) const {
    if (index < 0 || index >= size()) {
        throw std::out_of_range("Index out of range");
    }
}

// Глобальные операторы сравнения
bool operator==(const BitArray& a, const BitArray& b) {
    return a.size() == b.size() && a.get_bits() == b.get_bits();
}

bool operator!=(const BitArray& a, const BitArray& b) {
    return !(a == b);
}