#include <iostream>
#include "rates_structures.h"
#include "processing.h"

void Difference(rates* subscribtions[], int size) {
	int index = 0;
	float value = 0;
	for (int i = 0; i < size; i++) {
		float temp1 = abs(subscribtions[i]->buy_price);
		float temp2 = abs(subscribtions[i]->sell_price);
		if ((abs(temp1 - temp2)) > value)
		{
			value = (abs(temp1 - temp2));
			index = i;

		}

	}
	cout << subscribtions[index]->bank << ' ';
	cout << subscribtions[index]->buy_price << ' ';
	cout << subscribtions[index]->sell_price << ' ';
	cout << subscribtions[index]->adress << ' ';
	cout << '\n';


}