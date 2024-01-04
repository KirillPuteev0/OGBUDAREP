#include "pch.h"
#include "CppUnitTest.h"

#include "../git-exchange-rates-practice/rates_structures.h"
#include "../git-exchange-rates-practice/processing.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


TEST_CLASS(PRPTests)
{
public:
    TEST_METHOD(TestMonthlyPrepositions)
    {
        int testSize = 2;
        rates** Subscriptions = new rates* [testSize];

        // Подготовка тестовых данных
        Subscriptions[0] = new rates{ "bank1", 10.2 , 15.2,"lalaa" };
        Subscriptions[1] = new rates{ "bank2", 10.2, 4.2, "fff" };
        cout << Subscriptions[1]->buy_price;

        float result = 6;

       Assert::AreEqual(result, Difference(Subscriptions, testSize));
    }
    TEST_METHOD(TestMonthlyPrepositions1)
    {
        int testSize = 2;
        rates** Subscriptions = new rates * [testSize];

        // Подготовка тестовых данных
        Subscriptions[0] = new rates{ "bank3", 20.0 , 15.0,"sssss" };
        Subscriptions[1] = new rates{ "bank4", 33.0, 4.0, "sdsd" };
        cout << Subscriptions[1]->buy_price;

        float result = 29.0;

        Assert::AreEqual(result, Difference(Subscriptions, testSize));
    }
    TEST_METHOD(TestMonthlyPrepositions2)
    {
        int testSize = 2;
        rates** Subscriptions = new rates * [testSize];

        // Подготовка тестовых данных5
        Subscriptions[0] = new rates{ "bank5", 38.7, 15.8,"sssss" };
        Subscriptions[1] = new rates{ "bank6", 40.2, 3.2, "sdsd" };
        cout << Subscriptions[1]->buy_price;

        float result = 37.0;

        Assert::AreEqual(result, Difference(Subscriptions, testSize));
    }
};