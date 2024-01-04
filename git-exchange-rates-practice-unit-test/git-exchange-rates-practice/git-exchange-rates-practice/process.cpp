#include <iostream>
#include "rates_structures.h"
#include "processing.h"
// Подключение заголовочных файлов

float Difference(rates* subscribtions[], int size) {//разница между ценой покупки и продажи для каждой подписки,
	int index = 0;
	float value = 0;
	for (int i = 0; i < size; i++) {
		float temp1 = subscribtions[i]->buy_price; // Получение значения цены покупки
		float temp2 = subscribtions[i]->sell_price;// Получение значения цены продажи
		if ((abs(temp1 - temp2)) > value)// Если разница между ценами больше сохранённого значения
		{
			value = (abs(temp1 - temp2));// Обновление значения наибольшей разницы цен
			index = i; // Сохранение индекса текущей подписки

		}
        
	}
    
	// Вывод данных о подписке с наибольшей разницей цен
	cout << subscribtions[index]->bank << ' ';// Название банка
	cout << subscribtions[index]->buy_price << ' ';//Цена покупки
	cout << subscribtions[index]->sell_price << ' ';//Цена продажи
	cout << subscribtions[index]->adress << ' ';//адрес
	cout << '\n';
    return value;
}

/*int DifferenceV(rates* subscribtions[], int size) {//разница между ценой покупки и продажи для каждой подписки,
    int index = 0;
    float value = 0;
    for (int i = 0; i < size; i++) {
        float temp1 = abs(subscribtions[i]->buy_price); // Получение значения цены покупки
        float temp2 = abs(subscribtions[i]->sell_price);// Получение значения цены продажи
        if ((abs(temp1 - temp2)) > value)// Если разница между ценами больше сохранённого значения
        {
            value = (abs(temp1 - temp2));// Обновление значения наибольшей разницы цен
            index = i; // Сохранение индекса текущей подписки

        }
        return value + index;

    }
    // Вывод данных о подписке с наибольшей разницей цен
    cout << subscribtions[index]->bank << ' ';// Название банка
    cout << subscribtions[index]->buy_price << ' ';//Цена покупки
    cout << subscribtions[index]->sell_price << ' ';//Цена продажи
    cout << subscribtions[index]->adress << ' ';//адрес
    cout << '\n';
    return value;

}

int DifferenceI(rates* subscribtions[], int size) {//разница между ценой покупки и продажи для каждой подписки,
    int index = 0;
    float value = 0;
    for (int i = 0; i < size; i++) {
        float temp1 = abs(subscribtions[i]->buy_price); // Получение значения цены покупки
        float temp2 = abs(subscribtions[i]->sell_price);// Получение значения цены продажи
        if ((abs(temp1 - temp2)) > value)// Если разница между ценами больше сохранённого значения
        {
            value = (abs(temp1 - temp2));// Обновление значения наибольшей разницы цен
            index = i; // Сохранение индекса текущей подписки

        }
        return value + index;

    }
    // Вывод данных о подписке с наибольшей разницей цен
    cout << subscribtions[index]->bank << ' ';// Название банка
    cout << subscribtions[index]->buy_price << ' ';//Цена покупки
    cout << subscribtions[index]->sell_price << ' ';//Цена продажи
    cout << subscribtions[index]->adress << ' ';//адрес
    cout << '\n';
    return index;

}
*/
