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
    // Нормально отображение кириллицы
    //setlocale(LC_NUMERIC, "С"); // Чтоб не округляло числа из файла

    SetConsoleTitle(L"FreeDOM"); //Задает название консоли
    
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLongPtr(consoleWindow, GWL_STYLE, GetWindowLongPtr(consoleWindow, GWL_STYLE) & ~WS_THICKFRAME);
    SetWindowLongPtr(consoleWindow, GWL_STYLE, GetWindowLongPtr(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX);
    SetWindowPos(consoleWindow, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);

    
    firstWin(); // Запускает первое окно программы
    return 0;
}

