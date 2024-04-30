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
    system("color 3");
    SetConsoleTitle(L"FreeDOM");
    //setlocale(LC_ALL, "ru");
    //setlocale(LC_NUMERIC, "POSIX");

    ////записывает из файла в вектор данные о пользователе
    //vector<User> users = User::writingUsers();

    chooseWin();
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

