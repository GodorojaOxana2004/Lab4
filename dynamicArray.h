#pragma once // использование кода множество раз 

#include <span> // предназначенный для представления непрерывных участков памяти.

struct DynamicArray {
    int* data;     // Указатель на массив данных
    size_t length;  // Текущая длина массива
    size_t capacity;  // Максимальная вместимость массива
};

DynamicArray createDynamicArrayWithCapacity(size_t capacity); // динамический массив с заданной начальной вместимостью.
DynamicArray createDynamicArray();  // создает динамический массив с начальной вместимостью
void addElementToArray(DynamicArray* arr, int element); //добавляет элемент в конец динамического массива
int getElementAtIndex(const DynamicArray* arr, size_t index); // возвращает элемент в массиве по указанному индексу.
std::span<int> getCurrentSpan(const DynamicArray* arr); // возвращает std::span<int>, предоставляющий представление текущей части массива.
void freeDynamicArray(DynamicArray* arr); //свобождает память, выделенную для динамического массива.
