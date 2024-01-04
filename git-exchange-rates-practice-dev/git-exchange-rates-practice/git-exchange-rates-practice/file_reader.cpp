#include "file_reader.h"
#include "constant.h"

#include <fstream>
#include <cstring>


void read(const char* file_name, rates* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            rates* item = new rates;
            file >> item->bank;
            file >> item->buy_price;
            file >> item->sell_price;
            file >> tmp_buffer;
            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            file.getline(item->adress, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}