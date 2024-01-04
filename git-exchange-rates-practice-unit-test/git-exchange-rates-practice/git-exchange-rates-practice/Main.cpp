#include <iostream>

using namespace std;

#include "rates_structures.h"
#include "file_reader.h"
#include "constant.h"
#include "manipulation.h"
#include "processing.h"
int main()
{
    setlocale(LC_ALL, "Russian");//вывод данных
    cout << "Лабораторная работа №4. GIT\n";
    cout << "Вариант №4. Курсы валют\n";
    cout << "Автор: Ильющенко Яна\n\n";
    rates* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        {
            //// Вывод данных
            cout << subscriptions[i]->bank << ' ';
            cout << subscriptions[i]->buy_price << ' ';
            cout << subscriptions[i]->sell_price << ' ';
            cout << subscriptions[i]->adress << ' ';
            cout << '\n';
        }

    }
    catch (const char* error)
    {// // Вывод сообщения об ошибке, если произошла беда-беда
        cout << error << '\n';
    }

    bool rpts = true;//флаг для продолжения работы программы
    int rpts_value = 0;
    while (rpts == true)
    {
        cout << "What do you want to do next? " << endl << "1. Ввывод всех валют Беларусбанка " << endl << "2. Продажа < 2.5 ";
        cout << endl << "3. Сортировка пузырьком " << endl << "4. Сортировка слиянием " << endl << "5. Exit " << endl << "6. Monthly prepositions" << endl;
        //варианты действий и выбор действия
        cin >> rpts_value;
        //получение выбора пользователя
        switch (rpts_value)
        {
        case 1: only_Belarusbank(subscriptions, size); // Отобразить все валюты Беларусбанка
            break;
        case 2:low_volume(subscriptions, size);// Показать валюты с продажей меньше 2.5
            break;
        case 3:// Сортировка пузырьком
        {
            cout << "Критерии сортировки" << endl << "1. убывание разницы между продажей и покупкой    2. сортировка по названию";
            int sort_id;
            cin >> sort_id;
            BubbleSort(subscriptions, size, sort_id);
            break;
        }

        case 4:
        {// Сортировка слиянием по выбранному критерию
            cout << "Критерии сортировки" << endl << "1. убывание разницы между продажей и покупкой    2. сортировка по названию";
            int sort_id;
            cin >> sort_id;
            mergeSort(subscriptions, 0, size - 1, sort_id);
            for (int i = 0; i < size; i++)
            {
                print_data(subscriptions, i);
            }
            break;
        }
        case 5:// Выход из программы
        {
            rpts = false;
            break;
        }
        case 6:
        {    
            Difference(subscriptions, size);
            break;
        }
        }

    }
    for (int i = 0; i < size; i++)
    {
        delete subscriptions[i];// Освобождение выделенной памяти

       
    }
    return 0;

}