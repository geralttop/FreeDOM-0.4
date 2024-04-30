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
    setlocale(0, "ru");
    system("color 3");
    SetConsoleTitle(L"FreeDOM");
    system("mode con cols=49 lines=13");
    
    //setlocale(LC_ALL, "ru");
    //setlocale(LC_NUMERIC, "POSIX");

    ////записывает из файла в вектор данные о пользователе
    //vector<User> users = User::writingUsers();

    firstWin();
    /*int choose;
    bool isUser;

    cout << "Выберите,как войти\n1. User\n2. Developer\n";
    cin >> choose;

    system("cls");
    switch (choose)
    {
    case (1):
        UsSignInUp(users);
        break;
    case (2):
        isUser = false;
        system("cls");
        break;
    default:
        break;
    }*/
    return 0;
}

