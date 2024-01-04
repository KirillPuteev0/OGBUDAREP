#include <iostream>

using namespace std;

#include "rates_structures.h"
#include "file_reader.h"
#include "constant.h"
#include "manipulations.h"

void print_data(rates* subscriptions[], int id)
//функция для вывода на экран 
{
    cout << subscriptions[id]->bank << ' ';//вывод названий банка
    cout << subscriptions[id]->buy_price << ' ';//вывод цены покупки
    cout << subscriptions[id]->sell_price << ' ';//вывод цены продажи
    cout << subscriptions[id]->adress << ' ';//вывод  адреса
    cout << '\n';
}

void only_Belarusbank(rates* subscriptions[], int size)
// Функция фильтрует подписки по банку Belarusbank и выводит данные
{


    for (int i = 0; i < size; i++)
    {
        if (strstr(subscriptions[i]->bank, "Belarusbank") != NULL)// Если банк содержит подстроку "Belarusbank"
        {
            print_data(subscriptions, i);// Вывести данные о подписке
        }
    }
}

void low_volume(rates* subscriptions[], int size)
// Функция находит цену продаж <2.5 и выводит данные
{
    for (int i = 0; i < size; i++)
    {
        if (subscriptions[i]->sell_price < 2.5)// Если цена продажи меньше 2.5
        {
            print_data(subscriptions, i);//вывести отделение банка

        }
    }
}
// Функцияосуществляет сравнение для сортировки
bool SortCase(int sort_id, rates* subscriptions[], int size, int id, int id2)
{
    switch (sort_id)
    {
    case 1:
        // Сортировка по разнице между ценой продажи и покупки
    {
        if (abs(subscriptions[id]->sell_price - subscriptions[id]->buy_price) < abs(subscriptions[id2]->sell_price - subscriptions[id2]->buy_price))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    case 2:
        // Сортировка по банку и адресу
    {if (strcmp(subscriptions[id]->bank, subscriptions[id2]->bank) < 0)
    {
        return true;
    }
    if (strcmp(subscriptions[id]->bank, subscriptions[id2]->bank) == 0)
    {
        if (strcmp(subscriptions[id]->adress, subscriptions[id2]->adress) < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (strcmp(subscriptions[id]->bank, subscriptions[id2]->bank) > 0)
    {
        return false;
    }
    }
    }
}
void BubbleSort(rates* subscriptions[], int size, int sort_id) {
    //сортируем пузырьком
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (SortCase(sort_id, subscriptions, size, j + 1, j))// Вызов функции для сравнения
                swap(subscriptions[j + 1], subscriptions[j]);// Обмен элементов
        }
    }
    for (int d = 0; d < size; d++)
    {
        print_data(subscriptions, d); // Вывод данных после сортировки
    }
}
// Объединяем отсортированные массивы
void merge(rates* subscriptions[], int left, int mid, int right, int sort_id) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Создаём временные массивы
    rates** LeftSubArray = new rates * [n1];
    rates** RightSubArray = new rates * [n2];

   // Копируем данные во временные массивы
    for (int i = 0; i < n1; i++) {
        LeftSubArray[i] = subscriptions[left + i];
    }
    for (int j = 0; j < n2; j++) {
        RightSubArray[j] = subscriptions[mid + 1 + j];
    }

    // возвращаем временные массивы обратно в основной
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (SortCase(sort_id, subscriptions, n1, i, j)) {
            subscriptions[k] = LeftSubArray[i];
            i++;
        }
        else {
            subscriptions[k] = RightSubArray[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы, если они есть
    while (i < n1) {
        subscriptions[k] = LeftSubArray[i];
        i++;
        k++;
    }

    // И снова копируем оставшиеся элементы
    while (j < n2) {
        subscriptions[k] = RightSubArray[j];
        j++;
        k++;
    }

    // Очистка временной памяти
    delete[] LeftSubArray;
    delete[] RightSubArray;
}
//сортируем обе половинки и объединяем отсортированние части
void mergeSort(rates* subscriptions[], int left, int right, int sort_id) {
    if (left < right) {
        int mid = left + (right - left) / 2;// Находим середину массива

        
        mergeSort(subscriptions, left, mid, sort_id);
        mergeSort(subscriptions, mid + 1, right, sort_id);

        //объединяем половинки
        merge(subscriptions, left, mid, right, sort_id);
    }
}