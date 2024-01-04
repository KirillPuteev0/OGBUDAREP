#ifndef BOOK_SUBSCRIPTION_H
#define BOOK_SUBSCRIPTION_H

#include "constant.h"

struct rates
{
    char bank[MAX_STRING_SIZE];
    float buy_price;
    float sell_price;
    char adress[MAX_STRING_SIZE];
};

#endif