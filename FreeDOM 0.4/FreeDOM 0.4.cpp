#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include "User.h"
#include "Lib.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    setlocale(LC_NUMERIC, "POSIX");

    //записывает из файла в вектор данные о пользователе
    vector<User> users = writingUsers();
    

    int choose;

    cout << "Выберите,как войти\n1. User\n2. Developer\n";
    cin >> choose;

    system("cls");
    switch (choose)
    {
    case (1):
        cout << "1. Войти\n2. Зарегестрироваться\n";
        break;
        system("cls");
    default:
        break;
    }

    checkingLoginData(users);
    
    




    

    
}

