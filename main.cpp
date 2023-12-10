#include "dynamicArray.h"
#include <iostream>
#include <cassert>
#include <span>

void test1() {
    DynamicArray arr = createDynamicArrayWithCapacity(10);
    assert(arr.capacity == 10);
} // Создание массива с начальной вместимостью 10 и проверяем через capacity

void test2() //Создание массива с дефолтной вместимостью (4) и добавление элемента
{
    DynamicArray arr = createDynamicArray();
    assert(arr.length == 0); // Проверяем, что длина массива равна 0 после создания
    addElementToArray(&arr, 5);
    assert(arr.length == 1); // Убеждаемся, что длина стала равной 1
} 

void test3() // Создание массива с начальной вместимостью 1 и динамическое увеличение
{
    DynamicArray arr = createDynamicArrayWithCapacity(1);
    addElementToArray(&arr, 5);
    assert(arr.capacity == 1); // Проверяем, что вместимость осталась неизменной после добавления первого элемента
    addElementToArray(&arr, 10);
    assert(arr.capacity == 2);  // Проверяем, что вместимость увеличилась до 2 после добавления второго элемента
    addElementToArray(&arr, 20);
    assert(arr.capacity == 4); // Проверяем, что вместимость увеличилась до 4 после добавления третьего элемента
}

void test4() //Создание массива с дефолтной вместимостью и доступ к элементу по индексу
{
    DynamicArray arr = createDynamicArray();
    addElementToArray(&arr, 5);
    int el = getElementAtIndex(&arr, 0);
    assert(el == 5); // Убеждаемся, что доступ к элементу по индексу возвращает правильное значение
}

void test5() //Создание массива, добавление элементов и получение std::span
{
    DynamicArray arr{};
    addElementToArray(&arr, 5);
    addElementToArray(&arr, 6);
    addElementToArray(&arr, 7);

    std::span<int> span = getCurrentSpan(&arr);

    assert(span.size() == 3); // Убеждаемся, что размер std::span соответствует числу добавленных элементов
    assert(span[0] == 5);  // Проверяем, что элементы в std::span соответствуют ожидаемым значениям
    assert(span[1] == 6);
    assert(span[2] == 7);
}

//  Проверяет, что созданный массив с дефолтным capacity имеет нулевую длину и соответствующую capacity
void test6() {
    DynamicArray arr = createDynamicArray();
    assert(arr.length == 0);
    assert(arr.capacity == 4);
}

//  Проверяет, что случай с 0 capacity обрабатывается правильно
void test7() {
    DynamicArray arr = createDynamicArrayWithCapacity(0);
    addElementToArray(&arr, 5);
    assert(arr.capacity == 1);
    assert(arr.length == 1);
    assert(arr.data[0] == 5);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    return 0;
}
