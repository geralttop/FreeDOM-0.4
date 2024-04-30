#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include "User.h"
#include "Lib.h"
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;


int main()
{
    // Чтоб нормально введеную кириллицу считывало
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(0, "ru"); // Нормально отображение кириллицы
    setlocale(LC_NUMERIC, "POSIX"); // Чтоб не округляло числа из файла

    SetConsoleTitle(L"FreeDOM"); //Задает название консоли
    
    firstWin(); // Запускает первое окно программы
    return 0;
}

