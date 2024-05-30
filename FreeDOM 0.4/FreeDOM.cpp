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
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLongPtr(consoleWindow, GWL_STYLE, GetWindowLongPtr(consoleWindow, GWL_STYLE) & ~WS_THICKFRAME);
    SetWindowLongPtr(consoleWindow, GWL_STYLE, GetWindowLongPtr(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX);
    SetWindowPos(consoleWindow, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
    system("mode con cols=70 lines=22");
    AboutApp();
    firstWin(); // Запускает первое окно программы
    return 0;
}

