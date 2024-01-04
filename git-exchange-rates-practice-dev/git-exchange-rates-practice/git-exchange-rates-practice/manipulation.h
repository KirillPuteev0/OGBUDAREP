#pragma once
#include "rates_structures.h"
void only_Belarusbank(rates* subscriptions[], int size);
void low_volume(rates* subscriptions[], int size);
void BubbleSort(rates* subscriptions[], int size, int sort_id);
bool SortCase(int sort_id, rates* subscriptions[], int size, int id, int id2);
void mergeSort(rates* subscriptions[], int left, int right, int sort_id);
void print_data(rates* subscriptions[], int id);