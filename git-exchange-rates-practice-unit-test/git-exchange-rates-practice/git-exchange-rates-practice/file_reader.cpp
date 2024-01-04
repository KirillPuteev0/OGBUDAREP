#include "file_reader.h"
#include "constant.h"
//подключение заголовочных файлов
#include <fstream>
#include <cstring>
// подключение стандартных библиотек 

void read(const char* file_name, rates* array[], int& size)
{
    std::ifstream file(file_name); // Открываем файл для чтения
    if (file.is_open()) // Проверяем, успешно ли открыт файл
    {
        size = 0; // Инициализируем переменную size значением 0
        char tmp_buffer[MAX_STRING_SIZE]; // Создаем временный буфер для чтения строки
        while (!file.eof()) // Читаем файл до конца
        {
            rates* item = new rates; // Создаем новый объект структуры rates
            file >> item->bank; // Читаем значение поля bank из файла и сохраняем в объекте item
            file >> item->buy_price; // Читаем значение поля buy_price из файла и сохраняем в объекте item
            file >> item->sell_price; // Читаем значение поля sell_price из файла и сохраняем в объекте item
            file >> tmp_buffer; // Читаем значение временного буфера из файла
            file.read(tmp_buffer, 1); // Читаем лишний символ пробела из файла
            file.getline(item->adress, MAX_STRING_SIZE); // Читаем значение строки адреса из файла и сохраняем в объекте item
            array[size++] = item; // Добавляем объект item в массив array и увеличиваем значение size на 1
        }
        file.close(); // Закрываем файл
    }
    else
    {
        throw "Ошибка открытия файла"; // В случае ошибки открытия файла выбрасываем исключение
    }
}
