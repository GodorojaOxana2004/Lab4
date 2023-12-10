#include "dynamicArray.h"
#include <iostream>
#include <cassert>
#include <span>

DynamicArray createDynamicArrayWithCapacity(size_t capacity) {
    DynamicArray arr;
    arr.data = new int[capacity];
    arr.length = 0;
    arr.capacity = capacity;
    return arr;
}

DynamicArray createDynamicArray() {
    // Создание массива с дефолтной вместимостью (4 элемента)
    return createDynamicArrayWithCapacity(4);
}

void addElementToArray(DynamicArray* arr, int element) {
    if (arr->length == arr->capacity) {
        // Если массив полный, увеличиваем вместимость
        // Проверка на нулевое capacity - устанавливаем новую вместимость в 1
        size_t newCapacity = (arr->capacity == 0) ? 1 : arr->capacity * 2;
        int* newData = new int[newCapacity];
        std::copy(arr->data, arr->data + arr->length, newData);
        delete[] arr->data;
        arr->data = newData;
        arr->capacity = newCapacity;
    }

    // Добавляем элемент в конец массива
    arr->data[arr->length++] = element;
}

int getElementAtIndex(const DynamicArray* arr, size_t index) {
    assert(index < arr->length);
    // Получаем элемент по индексу
    return arr->data[index];
}

std::span<int> getCurrentSpan(const DynamicArray* arr) {
    return std::span<int>{arr->data, arr->length};
}

void freeDynamicArray(DynamicArray* arr) {
    // Освобождение динамической памяти
    delete[] arr->data;
    arr->data = nullptr;
    arr->length = 0;
    arr->capacity = 0;
}
