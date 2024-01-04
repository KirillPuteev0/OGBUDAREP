#pragma once
#include "rates_structures.h"
void only_Belarusbank(rates* subscriptions[], int size);//фильтрует подписки по банку Belarusbank
void low_volume(rates* subscriptions[], int size);//фильтрует подписки с низким объемом продаж
void BubbleSort(rates* subscriptions[], int size, int sort_id);//сортирует подписки с использованием алгоритма пузырьковой сортировки
bool SortCase(int sort_id, rates* subscriptions[], int size, int id, int id2);//осуществляет сравнение для сортировки в зависимости от sort_id
void mergeSort(rates* subscriptions[], int left, int right, int sort_id);//выполняет сортировку подписок с использованием алгоритма сортировки слиянием
void print_data(rates* subscriptions[], int id);//выводит данные о подписке