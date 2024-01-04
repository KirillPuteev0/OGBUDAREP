#ifndef BOOK_SUBSCRIPTION_H
// проверяет, не был ли определен идентификатор BOOK_SUBSCRIPTION_H ранее в текущей области видимости. 
// Если он не был определен, то следующий код будет включен; если он был определен, этот код будет исключен.
#define BOOK_SUBSCRIPTION_H
// если файл будет включен снова, проверка #ifndef не выполнится, и код будет исключен.
#include "constant.h"//подключение содержимого constant.h

struct rates
    //объявляет тип структуры с именем rates
{
    char bank[MAX_STRING_SIZE];//название банка
    float buy_price;//цена продажи
    float sell_price;//цена покупки
    char adress[MAX_STRING_SIZE];//адрес отделений банка
};

#endif