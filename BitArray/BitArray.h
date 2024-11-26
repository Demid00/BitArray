#ifndef BITARRAY_H
#define BITARRAY_H

#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>
#include <algorithm>

// Класс BitArray представляет битовый массив переменного размера
class BitArray {
public:
    // Конструкторы и деструктор
    BitArray(); // Конструктор по умолчанию, создает пустой битовый массив
    explicit BitArray(int num_bits, unsigned long value = 0); // Создает массив из num_bits, инициализирует первые sizeof(long) бит
    BitArray(const BitArray& b); // Конструктор копирования
    ~BitArray() = default; // Деструктор по умолчанию

    // Обменивает содержимое текущего массива с другим
    void swap(BitArray& b);

    // Оператор присваивания
    BitArray& operator=(const BitArray& b);

    // Изменяет размер массива, добавляя/удаляя биты
    void resize(int num_bits, bool value = false);

    // Удаляет все элементы массива
    void clear();

    // Добавляет новый бит в конец массива
    void push_back(bool bit);

    // Побитовые операции
    BitArray& operator&=(const BitArray& b); // Побитовая операция И с другим массивом
    BitArray& operator|=(const BitArray& b); // Побитовая операция ИЛИ
    BitArray& operator^=(const BitArray& b); // Побитовая операция исключающего ИЛИ

    // Версия побитовых операций, возвращающая новый массив
    BitArray operator&(const BitArray& b) const; // Возвращает результат И
    BitArray operator|(const BitArray& b) const; // Возвращает результат ИЛИ
    BitArray operator^(const BitArray& b) const; // Возвращает результат исключающего ИЛИ

    // Операторы сдвига
    BitArray& operator<<=(int n); // Сдвигает текущий массив влево
    BitArray& operator>>=(int n); // Сдвигает текущий массив вправо
    BitArray operator<<(int n) const; // Возвращает результат сдвига влево
    BitArray operator>>(int n) const; // Возвращает результат сдвига вправо

    // Методы установки и сброса битов
    BitArray& set(int n, bool val = true); // Устанавливает бит с индексом n в значение val
    BitArray& set(); // Устанавливает все биты в 1
    BitArray& reset(int n); // Устанавливает бит с индексом n в 0
    BitArray& reset(); // Сбрасывает все биты (устанавливает в 0)

    // Проверка состояния битов
    bool any() const; // Проверяет, есть ли хотя бы один бит, равный 1
    bool none() const; // Проверяет, все ли биты равны 0

    // Инверсия битов
    BitArray operator~() const; // Возвращает массив с инвертированными битами

    // Подсчет количества единичных бит
    int count() const;

    // Доступ к биту по индексу (только чтение)
    bool operator[](int i) const;

    // Получение информации о массиве
    int size() const; // Возвращает количество бит в массиве
    bool empty() const; // Проверяет, пуст ли массив

    // Возвращает строковое представление массива
    std::string to_string() const;

    friend bool operator==(const BitArray& a, const BitArray& b); // Проверяет равенство массивов
    friend bool operator!=(const BitArray& a, const BitArray& b); // Проверяет неравенство массивов

private:
    std::vector<bool> bits; // Внутреннее хранилище битов, реализовано через std::vector<bool>

    // Геттер для доступа к внутреннему вектору битов (помогает устранить ошибки доступа)
    const std::vector<bool>& get_bits() const { return bits; }

    void check_index(int index) const; // Проверка корректности индекса
};


#endif // BITARRAY_H
