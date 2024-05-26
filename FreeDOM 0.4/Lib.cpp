// Заголовочные файлы
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include "User.h" // Пользовательский заголовочный файл с определением класса User
#include "Lib.h" // Пользовательский заголовочый файл с определением функций
#include <Windows.h> // Библиотека для работы с Windows API
#include "Game.h"
#include "Dev.h"
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include <regex>
#include <iomanip>

using namespace std;

string cinSum() {
    string data = "";
    char ch;
    while (true) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 27) {
                return "e";
            }
            else if (ch == '\r') {
                if (data.size() > 0 && stof(data) != 0)
                    break;
            }
            else if (ch == '\b') {
                if (!data.empty()) {
                    data.pop_back();
                    cout << "\b \b";
                }
            }
            else if (isdigit(ch) or ch == '.') {
                int i = 0;
                int dotCount = 0;
                for (int j = 0; j < data.size(); j++) {
                    if (data[j] == '.') {
                        dotCount++;
                        i = j;
                    }
                }
                if (dotCount <= 1) {
                    if ((dotCount == 1 or data.size() == 0) and ch == '.' or data.size() > 9) continue;
                    if (i > 0) {
                        if (data.substr(i).size() == 3) {
                            continue;
                        }
                    }
                    if (stof(data + ch) > 100000) continue;
                    if ((data == "0") && ch != '.' || data == "0.0" && ch == '0') continue;
                    data += ch;
                    cout << ch;
                }
            }
        }
    }
    cout << "\n";
    return data;
}

string cinPassword() {
    string data;
    char ch;
    while (true) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 27) {
                return "123456789123456789123456789";
            }
            else if (ch == '\r') {
                if (data.size() > 0)
                    break;
            }
            else if (ch == '\b') {
                if (!data.empty()) {
                    data.pop_back();
                    cout << "\b \b";
                }
            }
            else {
                if (data.size() < 24) {
                    data += ch;
                    cout << "*";
                }
            }
        }
    }
    cout << "\n";
    return data;
}

string cinUsDevName() {
    string data;
    char ch;
    while (true) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 27) {
                return "123456789123456789123456789";
            }
            else if (ch == '\r') {
                if (data.size() > 0)
                    break;
            }
            else if (ch == '\b') {
                if (!data.empty()) {
                    data.pop_back();
                    cout << "\b \b";
                }
            }
            else if (isalpha(ch) || isdigit(ch) || ch == ' ') {
                if (data.size() < 24) {
                    data += ch;
                    cout << ch;
                }
            }
        }
    }
    cout << "\n";
    return data;
}

string cinCardNum() {
    string data;
    char ch;
    while (true) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 27) {
                return "e";
            }
            else if (ch == '\r') {
                if (data.size() > 0)
                    break;
            }
            else if (ch == '\b') {
                if (!data.empty()) {
                    if ((data.size()) % 4 == 0 && data.size() != 16 && data.size() != 1) cout << "\b \b";
                    data.pop_back();
                    cout << "\b \b";
                }
            }
            else {
                if (isdigit(ch) and data.size() < 16) {
                    data += ch;
                    cout << ch;
                    if (data.size() % 4 == 0 and data.size() != 16)
                        cout << "-";
                }
            }
        }
    }
    cout << "\n";
    return data;
}

string cinGameNameOrDesc(bool isName) {
    int size;
    if (isName) {
        size = 40;
    }
    else size = 440;
    string data;
    char ch;
    while (true) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 27) {
                return "<";
            }
            else if (ch == '\r') {
                if (data.size() > 0)
                    break;
            }
            else if (ch == '\b') {
                if (!data.empty()) {
                    data.pop_back();
                    cout << "\b \b";
                }
            }
            else if (ch != '<') {
                if (data.size() < size) {
                    data += ch;
                    cout << ch;
                }
            }
        }
    }
    cout << "\n";
    return data;
}

vector<User> writingUsers() {
    vector<User> users;
    ifstream ifUsLogin;
    ifstream ifUsPass;
    ifstream ifUsBalance;
    ifUsLogin.open("Data/userNames.txt");
    ifUsPass.open("Data/passOfUsers.txt");
    ifUsBalance.open("Data/userBalances.txt");
    int i = 0;
    while (!ifUsLogin.eof()) {
        string login;
        string pass;
        double balance;
        getline(ifUsLogin, login);
        getline(ifUsPass, pass);
        ifUsBalance >> balance;
        cout << fixed << std::setprecision(2);
        users.push_back(User(login, pass, balance, i));
        i++;
    }
    ifUsLogin.close();
    ifUsPass.close();
    ifUsBalance.close();
    return users;
}

vector<Dev> writingDevs() {
    std::vector<Dev> devs;
    std::ifstream ifDevLogin;
    std::ifstream ifDevPass;
    std::ifstream ifDevBalance;
    std::ifstream ifDevCardNum;
    ifDevLogin.open("Data/devNames.txt");
    ifDevPass.open("Data/passOfDevs.txt");
    ifDevBalance.open("Data/devBalances.txt");
    ifDevCardNum.open("Data/devCardNum.txt");
    int i = 0;
    while (!ifDevLogin.eof()) {
        std::string login;
        std::string pass;
        double balance;
        std::string cardNum;
        std::getline(ifDevLogin, login);
        std::getline(ifDevPass, pass);
        ifDevBalance >> balance;
        std::getline(ifDevCardNum, cardNum);
        devs.push_back(Dev(login, pass, balance, cardNum, i));
        i++;
    }
    ifDevLogin.close();
    ifDevPass.close();
    ifDevBalance.close();
    ifDevCardNum.close();
    return devs;
}

vector<Game> writingDevGames(string devName)
{
    vector<Game> devGames;
    string pathAbout = "Data/DevGames/About/" + devName + "About.txt";
    string pathName = "Data/DevGames/" + devName + "Games.txt";
    string pathPrice = "Data/DevGames/Price/" + devName + "Price.txt";
    ifstream ifAbout;
    ifstream ifName;
    ifstream ifPrice;
    ifAbout.open(pathAbout);
    ifName.open(pathName);
    ifPrice.open(pathPrice);
    int i = 0;
    while (!ifName.eof()) {
        string name;
        string about;
        string price;
        getline(ifName, name);
        getline(ifAbout, about);
        getline(ifPrice, price);
        if (name == "") {
            return devGames;
        }
        if (price == "") price = "0";
        float fprice = stof(price);
        devGames.push_back(Game(name, about, fprice, i, devName));
        i++;
    }
    ifAbout.close();
    ifName.close();
    ifPrice.close();
    return devGames;
}

vector<Game> writngAllGames() {
    vector<Game> allGames;
    vector<Dev> devs = writingDevs();
    for (int i = 0; i < devs.size(); i++) {
        vector<Game> devGames = writingDevGames(devs[i].getLogin());
        allGames.insert(allGames.end(), devGames.begin(), devGames.end());
    }
    return allGames;
}

vector<string> writingUseGames(string UsName) {
    vector<string> UserGames;
    ifstream ifUsGames;
    ifUsGames.open("Data/UserGames/" + UsName + "Games.txt");
    while (!ifUsGames.eof()) {
        string name;
        getline(ifUsGames, name);
        UserGames.push_back(name);
    }
    ifUsGames.close();
    return UserGames;
}

vector<Game> writingUseGamesData(User user) {
    vector<string> UsGamesStr = writingUseGames(user.getLogin());
    vector<Game> allGames = writngAllGames();
    vector<Game> DataUsGames;
    for (int i = 0; i < allGames.size(); i++) {
        for (int j = 0; j < UsGamesStr.size(); j++) {
            if (UsGamesStr[j] == allGames[i].getName()) {
                DataUsGames.push_back(allGames[i]);
                continue;
            }
        }
    }
    return DataUsGames;
}

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GoToXY(short x, short y) {
    SetConsoleCursorPosition(hStdOut, { x, y });
}

bool Quit() {
   
    system("cls");
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    while (true) {
        GoToXY(25, 9);
        cout << "Подтвердите действия";
        GoToXY(25, 10);
        cout << "Да(y)         Нет(n)";
        char c = _getch();
        system("cls");
        if (c == 'y' || c == 'Y') {
            return true;
        }
        else if (c == 'n' || c == 'N')
            return false;
    }
}

void ConsoleCursorVisible(bool show, short size) {
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);

    structCursorInfo.bVisible = show;

    structCursorInfo.dwSize = size;

    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

void bankRequest() {
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    ConsoleCursorVisible(false, 100);
    system("cls");
    GoToXY(15, 1);
    cout << "___";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
    system("cls");
    GoToXY(18, 1);
    cout << "___";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    system("cls");
    GoToXY(21, 1);
    cout << "___";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
    system("cls");
    GoToXY(24, 1);
    cout << "___";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    system("cls");
    GoToXY(27, 1);
    cout << "___";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
    GoToXY(30, 1);
    cout << "___";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    system("cls");
    GoToXY(33, 2);
    cout << "|";
    GoToXY(33, 3);
    cout << "|";
    GoToXY(33, 4);
    cout << "|";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
    system("cls");
    GoToXY(33, 5);
    cout << "|";
    GoToXY(33, 6);
    cout << "|";
    GoToXY(33, 7);
    cout << "|";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    system("cls");
    GoToXY(33, 8);
    cout << "|";
    GoToXY(33, 9);
    cout << "|";
    GoToXY(33, 10);
    cout << "|";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
    GoToXY(30, 11);
    cout << "___";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    system("cls");
    GoToXY(27, 11);
    cout << "___";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
    system("cls");
    GoToXY(24, 11);
    cout << "___";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    system("cls");
    GoToXY(21, 11);
    cout << "___";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
    system("cls");
    GoToXY(18, 11);
    cout << "___";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    GoToXY(15, 11);
    cout << "___";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
    system("cls");
    GoToXY(15, 10);
    cout << "|";
    GoToXY(15, 9);
    cout << "|";
    GoToXY(15, 8);
    cout << "|";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    system("cls");
    GoToXY(15, 7);
    cout << "|";
    GoToXY(15, 6);
    cout << "|";
    GoToXY(15, 5);
    cout << "|";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
    system("cls");
    GoToXY(15, 4);
    cout << "|";
    GoToXY(15, 3);
    cout << "|";
    GoToXY(15, 2);
    cout << "|";
    this_thread::sleep_for(std::chrono::milliseconds(200));

    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    system("cls");
    GoToXY(14, 7);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "Банк одобрил операцию";
    this_thread::sleep_for(std::chrono::milliseconds(1200));
    system("cls");
}

void BigText(int x, int y, int x1, string text) {
    int xx = x;
    for (int i = 0; i < text.length(); i++) {
        if (xx == x1) {
            xx = x;
            y++;
        }
        GoToXY(xx, y);
        xx++;
        cout << text[i];
    }
}

void SignInUs(bool isUser) {
    ConsoleCursorVisible(true, 100);
    vector<User> users = writingUsers();
    vector<Dev> devs = writingDevs();
    string signInLogin;
    string signInPass;
    int x = 21, y = 9;
    GoToXY(x, y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "Введите логин и пароль";
    GoToXY(x, ++y);
    cout << "Логин: ";
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    signInLogin = cinUsDevName();
    if (signInLogin == "123456789123456789123456789") {
        system("cls");
        SignInUp(isUser);
        return;
    }
    GoToXY(x, ++y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "Пароль: ";
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    signInPass = cinPassword();
    if (signInPass == "123456789123456789123456789") {
        system("cls");
        SignInUp(isUser);
        return;
    }
    cout << endl;
    if (isUser) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getLogin() == signInLogin) {
                if (users[i].getPass() == signInPass) {
                    UsCabinet(users[i]);
                }
                else {
                    GoToXY(x, ++y);
                    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
                    cout << "Введён неправильный пароль или логин";
                    this_thread::sleep_for(std::chrono::milliseconds(1200));
                    system("cls");
                    SignInUs(isUser);
                }
                return;
            }
        }
    }
    else {
        for (int i = 0; i < devs.size(); i++) {
            if (devs[i].getLogin() == signInLogin) {
                if (devs[i].getPass() == signInPass) {
                    DevCabinet(devs[i]);
                }
                else {
                    GoToXY(x, ++y);
                    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
                    cout << "Введён неправильный пароль или логин";
                    this_thread::sleep_for(std::chrono::milliseconds(1200));
                    system("cls");
                    SignInUs(isUser);
                }
                return;
            }
        }
    }
    GoToXY(x, ++y);
    ConsoleCursorVisible(false, 100);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "Введен неправильный пароль или логин\n";
    this_thread::sleep_for(std::chrono::milliseconds(1200));
    system("cls");
    SignInUs(isUser);
    return;
}

void SignInUp(bool isUser) {
    system("cls");
    ConsoleCursorVisible(false, 100);
    vector<string> Menu = { "Войти в свой аккаунт", "Создать новый аккаунт", "Вернуться назад, на первое окно", "Выход из программы" };
    int active_menu = 0;
    bool T = true;
    char ch;
    while (T) {
        int x = 19, y = 9;
        GoToXY(x, y);
        for (int i = 0; i < Menu.size(); i++) {
            if (i == active_menu) {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            }
            else {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
            }
            GoToXY(x, y++);
            cout << Menu[i] << endl;
        }
        ch = _getch();
        if (ch == -32) ch = _getch();
        switch (ch) {
        case 27:
            break;
        case 72:
            if (active_menu == 0) {
                active_menu = Menu.size() - 1;
            }
            else if (active_menu > 0) {
                --active_menu;
            }
            break;
        case 80:
            if (active_menu == Menu.size() - 1) {
                active_menu = 0;
            }
            else if (active_menu < Menu.size() - 1) {
                ++active_menu;
            }
            break;
        case 13:
            switch (active_menu) {
            case 0:
                system("cls");
                SignInUs(isUser);
                return;
            case 1:
                system("cls");
                if (isUser)
                    SignUpUs(true);
                else
                    SignUpDev();
                return;
            case 2:
                system("cls");
                firstWin();
                return;
            case 3:
                exit(0);
                break;
            }
            break;
        case 32:
            break;
        }
    }
}

bool validatePassword(const std::string& password) {
    if (password.length() < 8) {
        GoToXY(13, 11);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Пароль должен содержать не менее 8 символов.";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        return false;
    }
    bool hasLowercase = false;
    bool hasUppercase = false;
    bool hasDigit = false;
    bool hasSpace = false;
    for (char c : password) {
        if (std::isspace(c)) {
            hasSpace = true;
        }
        else if (std::islower(c)) {
            hasLowercase = true;
        }
        else if (std::isupper(c)) {
            hasUppercase = true;
        }
        else if (std::isdigit(c)) {
            hasDigit = true;
        }
        else if (!isascii(c)) {
            GoToXY(13, 11);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            std::cout << "Пароль не должен содержать кириллических символов.";
            ConsoleCursorVisible(false, 100);
            this_thread::sleep_for(std::chrono::milliseconds(1200));
            system("cls");
            return false;
        }
    }
    if (hasSpace) {
        GoToXY(13, 11);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Пароль не должен содержать пробелов.";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");
        return false;
    }
    if (!hasLowercase) {
        GoToXY(13, 11);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Пароль должен содержать хотя бы одну строчную букву.";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");
        return false;
    }
    if (!hasUppercase) {
        GoToXY(13, 11);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Пароль должен содержать хотя бы одну заглавную букву.";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");
        return false;
    }
    if (!hasDigit) {
        GoToXY(13, 11);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Пароль должен содержать хотя бы одну цифру.";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");
        return false;
    }
    return true;
}

bool validateLogin(const std::string& login) {
    if (login.length() < 6) {
        GoToXY(13, 9);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Длина логина должна быть не менее 6 символов.\n";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");
        return false;
    }
    bool hasLetter = false;
    for (char c : login) {
        if (isalpha(static_cast<unsigned char>(c))) {
            hasLetter = true;
        }
        if (!isascii(c)) {
            GoToXY(13, 9);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            std::cout << "Логин не должен содержать кириллические символы.\n";
            ConsoleCursorVisible(false, 100);
            this_thread::sleep_for(std::chrono::milliseconds(1200));
            system("cls");
            return false;
        }
    }
    if (!hasLetter) {
        GoToXY(13, 9);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Логин должен содержать хотя бы одну букву.\n";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");
        return false;
    }
    for (char c : login) {
        if (isspace(static_cast<unsigned char>(c))) {
            GoToXY(13, 9);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            std::cout << "Логин не должен содержать пробелы.\n";
            ConsoleCursorVisible(false, 100);
            this_thread::sleep_for(std::chrono::milliseconds(1200));
            system("cls");
            return false;
        }
    }
    return true;
}

bool validateCardNumber(const std::string& cardNumber) {
    if (cardNumber.length() != 16) {
        return false;
    }
    for (char ch : cardNumber) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

bool validateGameName(const std::string& name) {
    if (name.length() <= 5) {
        return false;
    }
    std::regex letterRegex("[а-яА-Яa-zA-Z]");
    return std::regex_search(name, letterRegex);
}

void SignUpUs(bool isUser) {
    vector<User> users = writingUsers();
    ConsoleCursorVisible(true, 100);
    string signUpLogin;
    string signUpPass;
    string signUpRepitPass;
    int x = 13, y = 5;
    GoToXY(x, y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "Введите данные для регистрации";
    ++y;
    GoToXY(x, ++y);
    cout << "(Длина: 6-24, мин. 1 буква[aA-zZ])";
    GoToXY(x, ++y);
    cout << "Логин: ";
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    signUpLogin = cinUsDevName();
    if (signUpLogin == "123456789123456789123456789") {
        system("cls");
        SignInUp(isUser);
        return;
    }
    if (!validateLogin(signUpLogin)) {
        system("cls");
        SignUpUs(true);
        return;
    }
    User currentUser;
    for (auto& user : users) {
        if (signUpLogin == user.getLogin()) {
            GoToXY(x, ++y);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            std::cout << "Такой логин уже занят";
            ConsoleCursorVisible(false, 100);
            this_thread::sleep_for(std::chrono::milliseconds(1200));
            system("cls");
            SignUpUs(true);
            return;
        }
    }
    GoToXY(x, ++y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "(Длина: 8-24, 1 буква[A-Z], 1 буква[a-z], 1 цифра[0-9]";
    GoToXY(x, ++y);
    cout << "Пароль: ";
    char ch;
    while (true) {
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
        signUpPass.clear();
        signUpPass = cinPassword();
        if (signUpPass == "123456789123456789123456789") {
            system("cls");
            SignInUp(isUser);
            return;
        }
        cout << endl;
        if (validatePassword(signUpPass)) {
            break;
        }
        else {
            reppas:
            system("cls");
            x = 13, y = 5;
            GoToXY(x, y);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            cout << "Введите данные для регистрации";
            ++y;
            GoToXY(x, ++y);
            cout << "(Длина: 6-24, мин. 1 буква[aA-zZ])";
            GoToXY(x, ++y);
            cout << "Логин: ";
            SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
            cout << signUpLogin;
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            GoToXY(x, ++y);
            cout << "(Длина: 8-24, 1 буква[A-Z], 1 буква[a-z], 1 цифра[0-9]";
            GoToXY(x, ++y);
            cout << "Пароль: ";
            SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
        }
    }
    GoToXY(x, ++y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    std::cout << "Повт пароль: ";
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    signUpRepitPass.clear();
    signUpRepitPass = cinPassword();
    if (signUpRepitPass == "123456789123456789123456789") {
        system("cls");
        SignInUp(isUser);
        return;
    }
    cout << endl;
    if (signUpPass != signUpRepitPass) {
        GoToXY(x, ++y);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Пароль неправильно повторен\n";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        goto reppas;
    }
    users.push_back(User(signUpLogin, signUpPass, 0, users.size()));
    std::ofstream ofUsLogin;
    std::ofstream ofUsPass;
    std::ofstream ofUsBalance;
    ofUsLogin.open("Data/userNames.txt", std::ofstream::app);
    ofUsBalance.open("Data/userBalances.txt", std::ofstream::app);
    ofUsPass.open("Data/passOfUsers.txt", std::ofstream::app);
    ofUsLogin << std::endl << signUpLogin;
    ofUsBalance << std::endl << 0;
    ofUsPass << std::endl << signUpPass;
    ofUsLogin.close();
    ofUsBalance.close();
    ofUsPass.close();
    ofstream ofUsGames;
    ofUsGames.open("Data/UserGames/" + signUpLogin + "Games.txt");
    ofUsGames.close();
    UsCabinet(users[users.size() - 1]);
}

void SignUpDev() {
    vector<Dev> devs = writingDevs();
    ConsoleCursorVisible(true, 100);
    string signUpLogin;
    string signUpPass;
    string signUpRepitPass;
    string signDevCardNum;
    int x = 15, y = 5;
    GoToXY(x, y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "Введите данные для регистрации";
    GoToXY(x, ++y);
    cout << "(Длина: 6-24, мин. 1 буква[aA-zZ])";
    GoToXY(x, ++y);
    cout << "Логин: ";
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    signUpLogin = cinUsDevName();
    if (signUpLogin == "123456789123456789123456789") {
        SignInUp(false);
        return;
    }
    if (!validateLogin(signUpLogin)) {
        system("cls");
        SignUpDev();
        return;
    }
    for (auto& dev : devs) {
        if (signUpLogin == dev.getLogin()) {
            GoToXY(x, ++y);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            std::cout << "Такой логин уже занят";
            ConsoleCursorVisible(false, 100);
            this_thread::sleep_for(std::chrono::milliseconds(1200));
            system("cls");
            SignUpDev();
            return;
        }
    }
    GoToXY(x, ++y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "CardNum: ";
    while (true) {
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
        signDevCardNum = cinCardNum();
        if (signDevCardNum == "e") {
            SignInUp(false);
            return;
        }
        if (!validateCardNumber(signDevCardNum)) {
            // Если номер карты не прошел валидацию, выводим сообщение и запрашиваем новый номер
            GoToXY(x, ++y);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            std::cout << "Некорректный номер карты";
            ConsoleCursorVisible(false, 100);
            this_thread::sleep_for(std::chrono::milliseconds(1200));
            system("cls");
            x = 15, y = 5;
            GoToXY(x, y);
            cout << "Введите данные для регистрации";
            GoToXY(x, ++y);

            // Ввод логина пользователя
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            cout << "(Длина: 6-24, мин. 1 буква[aA-zZ])";
            GoToXY(x, ++y);
            cout << "Логин: ";
            SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
            cout << signUpLogin;
            GoToXY(x, ++y);

            // Ввод пароля пользователя
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            cout << "CardNum: ";
        }
        else break;
    }
    GoToXY(x, ++y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "(Длина: 8-24, 1 буква[A-Z], 1 буква[a-z], 1 цифра[0-9]";
    GoToXY(x, ++y);
    cout << "Пароль: ";
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    char ch;
    while (true) {
        signUpPass.clear();
        signUpPass = cinPassword();
        if (signUpPass == "123456789123456789123456789") {
            SignInUp(false);
            return;
        }
        cout << endl;
        if (validatePassword(signUpPass)) {
            break;
        }
        else {
            reppasdev:
            system("cls");
            x = 15, y = 5;
            GoToXY(x, y);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            cout << "Введите данные для регистрации";
            GoToXY(x, ++y);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            cout << "(Длина: 6-24, мин. 1 буква[aA-zZ])";
            GoToXY(x, ++y);
            cout << "Логин: ";
            SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
            cout << signUpLogin;
            GoToXY(x, ++y);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            cout << "CardNum: ";
            SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
            for (int i = 0; i < signDevCardNum.size(); i++) {
                cout << signDevCardNum[i];
                if (i != 0 && (i+1)%4 == 0 && i != 15) cout << "-";
                
            }
            GoToXY(x, ++y);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            cout << "(Длина: 8-24, 1 буква[A-Z], 1 буква[a-z], 1 цифра[0-9]";
            GoToXY(x, ++y);
            cout << "Пароль: ";
            SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
        }
    }
    GoToXY(x, ++y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    std::cout << "Повт. пароль: ";
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    signUpRepitPass.clear();
    signUpRepitPass = cinPassword();
    if (signUpRepitPass == "123456789123456789123456789") {
        SignInUp(false);
        return;
    }
    cout << endl;
    if (signUpPass != signUpRepitPass) {
        GoToXY(x, ++y);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Пароль неправильно повторен\n";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        goto reppasdev;
    }
    std::ofstream ofDevLogin;
    std::ofstream ofDevPass;
    std::ofstream ofDevBalance;
    std::ofstream ofDevCardNum;
    ofDevLogin.open("Data/devNames.txt", std::ofstream::app);
    ofDevBalance.open("Data/devBalances.txt", std::ofstream::app);
    ofDevPass.open("Data/passOfDevs.txt", std::ofstream::app);
    ofDevCardNum.open("Data/devCardNum.txt", std::ofstream::app);
    ofDevLogin << std::endl << signUpLogin;
    ofDevBalance << std::endl << "0";
    ofDevPass << std::endl << signUpPass;
    ofDevCardNum << std::endl << signDevCardNum;
    ofDevLogin.close();
    ofDevBalance.close();
    ofDevPass.close();
    ofDevCardNum.close();
    ofstream ofDevGames;
    ofstream ofGamesAbout;
    ofstream ofGamesPrice;
    ofDevGames.open("Data/DevGames/" + signUpLogin + "Games.txt");
    ofGamesAbout.open("Data/DevGames/About/" + signUpLogin + "About.txt");
    ofGamesPrice.open("Data/DevGames/Price/" + signUpLogin + "Price.txt");
    ofDevGames.close();
    ofGamesAbout.close();
    ofGamesPrice.close();
    DevCabinet(writingDevs()[devs.size()]);
}

void topUp(User currentUser) {
    ConsoleCursorVisible(true, 100);
    system("cls");
    string addBalance;
    string cardNum;
    int x = 10, y = 5;
    while (true) {
        x = 10, y = 5;
        GoToXY(x, y);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        cout << "Введите сумму, которую хотите добавить";
        GoToXY(x, ++y);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
        addBalance = cinSum();
        if (addBalance == "e") {
            UsCabinet(currentUser);
            return;
        }
        float faddBalance = stof(addBalance);
        GoToXY(x, ++y);
        if (currentUser.getBalance() + faddBalance > 100000) {
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            cout << "Макс. баланс пользователя: 100000";
            GoToXY(x, ++y);
            cout << "Вы можете положить на баланс только " << 100000 - currentUser.getBalance();
            this_thread::sleep_for(std::chrono::milliseconds(2200));
            system("cls");
        }
        else break;
    }
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "CardNum: ";
    while (true) {
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
        cardNum = cinCardNum();
        if (cardNum == "e") {
            UsCabinet(currentUser);
            return;
        }
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        if (!validateCardNumber(cardNum)) {
            GoToXY(x, ++y);
            std::cout << "Некорректный номер карты";
            ConsoleCursorVisible(false, 100);
            this_thread::sleep_for(std::chrono::milliseconds(1200));
            system("cls");
            x = 10, y = 5;
            GoToXY(x, y);
            cout << "Введите сумму, которую хотите добавить";
            GoToXY(x, ++y);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
            cout << addBalance;
            GoToXY(x, ++y);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            cout << "CardNum: ";
        }
        else break;
    }
    float faddBalance = stof(addBalance);
    currentUser.setBalance(currentUser.getBalance() + faddBalance);
    vector<User> users = writingUsers();
    users[currentUser.getIndex()].setBalance(currentUser.getBalance());
    ofstream ofUsBalance;
    ofUsBalance.open("Data/userBalances.txt");
    ofUsBalance << users[0].getBalance();
    for (int i = 1; i < users.size(); i++) {
        ofUsBalance << endl << users[i].getBalance();
    }
    ofUsBalance.close();
    bankRequest();
    UsCabinet(currentUser);
    return;
}

void writeOff(Dev currentDev) {
    vector<Dev> devs = writingDevs();
    currentDev.setBalance(0);
    devs[currentDev.getIndex()].setBalance(currentDev.getBalance());

    ofstream ofDevBalance;
    ofDevBalance.open("Data/devBalances.txt");
    ofDevBalance << devs[0].getBalance();
    for (int i = 1; i < devs.size(); i++) {
        ofDevBalance << endl << devs[i].getBalance();
    }

    ofDevBalance.close();
    DevCabinet(currentDev);
    return;
}

void UsCabinet(User currentUser) {
    ConsoleCursorVisible(false, 100);
    system("cls");

    vector<string> Menu = { "Пополнить баланс в приложении", "Библиотека купленных мной игр", "Библиотека всех игр", "Вернуться на первое окно", "Выйти из приложения" };
    int active_menu = 0;

    char ch;

    while (true) {
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        int x = 3, y = 1;
        GoToXY(3, 1);
        cout << "Ваш логин: " << currentUser.getLogin();
        GoToXY(3, 2);
        cout << "Ваш баланс: " << currentUser.getBalance();
        x = 20, y = 8;
        GoToXY(x, y);
        for (int i = 0; i < Menu.size(); i++) {
            if (i == active_menu) {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            }
            else {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
            }
            GoToXY(x, y++);
            cout << Menu[i] << endl;
        }
        ch = _getch();
        if (ch == -32) ch = _getch();
        switch (ch) {
        case 27:
            break;
        case 72:
            if (active_menu == 0) {
                active_menu = Menu.size() - 1;
            }
            else if (active_menu > 0) {
                --active_menu;
            }
            break;
        case 80:
            if (active_menu == Menu.size() - 1) {
                active_menu = 0;
            }
            else if (active_menu < Menu.size() - 1) {
                ++active_menu;
            }
            break;
        case 13:
            switch (active_menu) {
            case 0:
                topUp(currentUser);
                return;
            case 1:
                system("cls");
                GamesList(writingUseGamesData(currentUser), false, "", false);
                ConsoleCursorVisible(false, 100);
                break;
            case 2:
                system("cls");
                GamesList(writngAllGames(), true, currentUser.getLogin(), false);
                ConsoleCursorVisible(false, 100);
                break;
            case 3:
                system("cls");
                if (Quit() == true) {
                    firstWin();
                    return;
                }
                break;
                
            case 4:
                if (Quit() == true) {
                    exit(0);
                    return;
                }
                break;

            }
            break;
        }
    }
    _getch();
}

void BuyGame(Game game, string UsName) {
    system("cls");
    vector<User> users = writingUsers();
    vector<string> userGames = writingUseGames(UsName);

    User user;
    
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == UsName) user = users[i];
    }
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    for (int i = 0; i < userGames.size(); i++) {
        if (userGames[i] == game.getName()) {
            system("cls");
            GoToXY(30, 10);
            cout << "Игра уже куплена";
            this_thread::sleep_for(std::chrono::milliseconds(1200));
            system("cls");
            return;
        }
    }

    if (user.getBalance() > game.getPrice()) {
        //bankRequest();
        user.setBalance(user.getBalance() - game.getPrice());
        system("cls");
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        GoToXY(24, 10);
        cout << "Игра добавлена в вашу библиотеку";
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");

    }
    else {
        system("cls");
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        GoToXY(30, 10);
        cout << "У вас недостаточно денег";
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");
        return;
    }

    ofstream ofUsGames;
    ofUsGames.open("Data/UserGames/" + UsName + "Games.txt", ofstream::app);
    
    if (userGames[0] == "") {
        ofUsGames << game.getName();
    }
    else {
        ofUsGames << endl << game.getName();
    }
    ofUsGames.close();

    ofstream ofUsBalance;
    ofUsBalance.open("Data/userBalances.txt");

    users[user.getIndex()] = user;

    ofUsBalance << users[0].getBalance();
    for (int i = 1; i < users.size(); i++) {
        ofUsBalance << endl << users[i].getBalance();
    }
    ofUsBalance.close();
    vector<Dev> devs = writingDevs();
    ofstream ofDevBalance;
    ofDevBalance.open("Data/devBalances.txt");
    for (int i = 0; i < devs.size(); i++) {
        if (i != 0) {
            ofDevBalance << "\n";
        }
        if (devs[i].getLogin() == game.getDevName()) {
            ofDevBalance << devs[i].getBalance() + 0.9 * game.getPrice();
        }
        else {
            ofDevBalance << devs[i].getBalance();
        }
    }
    ofDevBalance.close();

    system("cls");
    UsCabinet(user);
    return;
}

void PageList(Game game, bool isUser, string UsName) {
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    system("cls");
    GoToXY(5, 1);
    cout << game.getName();
    GoToXY(60, 1);
    cout << game.getPrice() << "$";
    BigText(2, 3, 68, game.getAbout());
    if (isUser) {
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        GoToXY(20, 19);
        cout << "Купить(Enter)             Назад(esc)";
    }
    else {
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        GoToXY(30, 19);
        cout << "Назад(esc)";
    }
    
    /*GoToXY(5, 2);
    cout << game.getAbout();*/
    while (true) {
        char ch = _getch();
        if (ch == 27) {
            system("cls");
            return;
        }
        if (isUser && ch == 13) {
            BuyGame(game, UsName);
            return;
        }

    }
}

void FindGame(vector<Game> games, bool isUser, string UsName) {
    vector<Game> filtergames;
    GoToXY(2, 7);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    ConsoleCursorVisible(true, 100);
    cout << "Введите название игры: ";
    string name;
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    name = cinGameNameOrDesc(true);
    if (name == "<") {
        system("cls");
        return;

    }

    for (int i = 0; i < games.size(); i++) {
        size_t found = games[i].getName().find(name);
        if (found != std::string::npos) filtergames.push_back(games[i]);
    }

    system("cls");
    if (filtergames.size() == 0) {
        GoToXY(4, 7);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        ConsoleCursorVisible(false, 100);
        cout << "Игр с такими параметрами не найдено";
        this_thread::sleep_for(std::chrono::milliseconds(2200));
        system("cls");
        FindGame(games, isUser, UsName);

        return;
    }
    ConsoleCursorVisible(false, 100);
    GamesList(filtergames, isUser, UsName, true);
    return;
}

void GamesList(vector<Game> games, bool isUser, string UsName, bool isFind) {
    ConsoleCursorVisible(false, 100);
    if (!isFind && games.size() == 0) {
        GoToXY(20, 8);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        cout << "У вас нет игр пока что";
        this_thread::sleep_for(std::chrono::milliseconds(2200));
        return;
    }
    int x = 5, x1 = 40, y = 1;
    int active_menu = 0;
    char ch;
    int minShowGame = 0, maxShomGame = 17;
    if (maxShomGame > games.size()) maxShomGame = games.size();
    while (true) {
        GoToXY(10, 19);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        cout << "Пр. Стр.(<-)                              Сл. Стр.(->)";
        if (!isFind) {
            GoToXY(19, 20);
            cout << "Назад(Ecs)        Поиск игр(Space)";
        }
        else {
            GoToXY(30, 20);
            cout << "Назад(Ecs)";
        }
        int x = 5, x1 = 57, y = 1;
        GoToXY(x, y);
        for (int i = minShowGame; i < maxShomGame; i++) {
            if (i == active_menu) {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            }
            else {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
            }
            GoToXY(x, y++);
            cout << games[i].getName() << endl;
            y--;
            GoToXY(x1, y++);
            cout << games[i].getPrice() << "$";
        }
        ch = _getch();
        if (ch == -32) ch = _getch();
        switch (ch) {
        case 27:
            system("cls");
            return;
        case 72:
            if (active_menu > 0) {
                --active_menu;
                if (active_menu < minShowGame) {
                    system("cls");
                    maxShomGame = active_menu + 1;
                    if (minShowGame - 17 < 0) {
                        minShowGame = 0;
                    }
                    else minShowGame -= 17;
                }
            }
            break;
        case 80:
            if (active_menu < games.size() - 1) {
                ++active_menu;
                if (active_menu > maxShomGame - 1) {
                    system("cls");
                    minShowGame = active_menu;
                    if (maxShomGame + 17 > games.size())
                        maxShomGame = games.size();
                    else maxShomGame += 17;
                }
            }
            break;
        case 77:
            system("cls");
            if (maxShomGame + 17 > games.size()) {
                if (minShowGame + 17 < games.size()) {
                    minShowGame += 17;
                    if (active_menu + 17 > games.size()) active_menu = games.size() - 1;
                    else active_menu += 17;
                }
                maxShomGame = games.size();
            }
            else {
                active_menu += 17;
                minShowGame += 17;
                maxShomGame += 17;
            }
            break;
        case 75:
            system("cls");
            if (minShowGame - 17 < 0) {
                minShowGame = 0;
                if (maxShomGame - 17 < 0) {
                    maxShomGame = 17;
                }
                if (maxShomGame > games.size()) maxShomGame = games.size();
            }
            else {
                active_menu -= 17;
                maxShomGame = minShowGame;
                minShowGame -= 17;
            }
            break;
        case 13:
            PageList(games[active_menu], isUser, UsName);
            ConsoleCursorVisible(false, 100);
            break;
        case 32:
            if (!isFind) {
                system("cls");
                FindGame(games, isUser, UsName);
                ConsoleCursorVisible(false, 100);
            }
            break;
        }
    }
    _getch();
}

void addGame(string DevName) {
    system("cls");
    vector<Game> allGames = writngAllGames();
    int x = 3, y = 2;

    string name;
    string about;
    string price;

    GoToXY(x, y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "Название игры: ";
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    ConsoleCursorVisible(true, 100);
    name = cinGameNameOrDesc(true);
    if (name == "<") {
        system("cls");
        return;
    }

    if (!validateGameName(name)) {
        GoToXY(x, ++y);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        cout << "Название игры должно быть длиннее 5 символов и содержать хотя бы 1 букву." << endl;
        this_thread::sleep_for(chrono::milliseconds(1200));
        addGame(DevName);
        return;
    }
    for (int i = 0; i < allGames.size(); i++) {
        if (name == allGames[i].getName()) {
            GoToXY(x, ++y);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            cout << "Такое название уже занято";
            this_thread::sleep_for(std::chrono::milliseconds(1200));
            addGame(DevName);
            return;
        }
    }
    

    GoToXY(x, ++y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "Цена для игры: ";
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    ConsoleCursorVisible(true, 100);
    price = cinSum();
    if (price == "e") {
        system("cls");
        return;
    }

    GoToXY(x, ++y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "Описание игры: ";
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    ConsoleCursorVisible(true, 100);
    //GoToXY(3, ++y);
    about = cinGameNameOrDesc(false);
    if (about == ">") {
        return;
        system("cls");
    }
       //440 символов максимум

    ofstream ofGameName;
    ofstream ofAboutGame;
    ofstream ofPriceGame;

    ofGameName.open("Data/DevGames/" + DevName + "Games.txt", ofstream::app);
    ofAboutGame.open("Data/DevGames/About/" + DevName + "About.txt", ofstream::app);
    ofPriceGame.open("Data/DevGames/Price/" + DevName + "Price.txt", ofstream::app);
    
    if (writingDevGames(DevName).size() == 0) {
        ofGameName << name;
        ofAboutGame << about;
        ofPriceGame << price;
    }
    else {
        ofGameName << endl << name;
        ofAboutGame << endl << about;
        ofPriceGame << endl << price;
    }
    

    ofGameName.close();
    ofAboutGame.close();
    ofPriceGame.close();
    
    system("cls");
    return;
}

void DevCabinet(Dev currentDev) {
    ConsoleCursorVisible(false, 100);
    system("cls");

    vector<string> Menu = { "Списать деньги на карту", "Список, разработанных вами, игр", "Добавить новую игру", "Выход на 1-ое окно", "Выход из приложения" };
    int active_menu = 0;

    char ch;

    while (true) {
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        GoToXY(3, 1);
        cout << "Ваше название: " << currentDev.getLogin();
        GoToXY(45, 1);
        cout << "Ваш баланс: " << currentDev.getBalance();
        int x = 20, y = 8;
        GoToXY(x, y);
        for (int i = 0; i < Menu.size(); i++) {
            if (i == active_menu) {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            }
            else {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
            }
            GoToXY(x, y++);
            cout << Menu[i] << endl;
        }
        ch = _getch();
        if (ch == -32) ch = _getch();
        switch (ch) {
        case 27:
            break;
        case 72:
            if (active_menu == 0) {
                active_menu = Menu.size() - 1;
            }
            else if (active_menu > 0) {
                --active_menu;
            }
            break;
        case 80:
            if (active_menu == Menu.size() - 1) {
                active_menu = 0;
            }
            else if (active_menu < Menu.size() - 1) {
                ++active_menu;
            }
            break;
        case 13:
            switch (active_menu) {
            case 0:
                if (currentDev.getBalance() > 0) {
                    bankRequest();
                    writeOff(currentDev);
                    return;
                }
                break;
            case 1:
                system("cls");
                GamesList(writingDevGames(currentDev.getLogin()), false, "", false);
                break;
            case 2:
                addGame(currentDev.getLogin());
                ConsoleCursorVisible(false, 100);
                break;
            case 3:
                system("cls");
                if (Quit() == true) {
                    firstWin();
                    return;
                }
                break;

            case 4:
                if (Quit() == true) {
                    exit(0);
                    return;
                }
                break;
            }
            break;
        case 32:
            system("cls");
            _getch();
            system("cls");
            cout << " Ну и расскажу анекдот: Занимется сексом отец с сыном, и спрашивает его: 'Рад, что мать сдохла?'";
            return;
        }
    }
    _getch();
    return;
}

void AboutApp() {
    cout << "Синие текст -- это просто текст\nКрасный текст -- это кнопки между которыми можно переключаться с помощью стрелок вверх-вниз. Если текст подсвечен розовым(светло-красным), то можно нажать enter и выполнится розовое действие\nЗеленый -- ввод значений с клавиатуры";
    _getch();
    system("cls");
}

void firstWin() {
    system("mode con cols=70 lines=22");
    ConsoleCursorVisible(false, 100);

    vector<string> Menu = { "Выберите действие", "Войти как игрок(покупатель)", "Войти как издатель игр(продавец)", "Выход из программы" };

    int active_menu = 1;

    char ch;

    bool isUser;

    GoToXY(19, 8);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << Menu[0];
    while (true) {
        int x = 19, y = 10;
        GoToXY(x, y);
        for (int i = 1; i < Menu.size(); i++) {
            if (i == active_menu) {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            }
            else {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
            }
            GoToXY(x, y++);
            cout << Menu[i] << endl;
        }
        ch = _getch();
        if (ch == -32) ch = _getch();
        switch (ch) {
        case 27:
            break;
        case 72:
            if (active_menu == 1) {
                active_menu = Menu.size() - 1;
            }
            else if (active_menu > 1) {
                --active_menu;
            }
            break;
        case 80:
            if (active_menu == Menu.size() - 1) {
                active_menu = 1;
            }
            else if (active_menu < Menu.size() - 1) {
                ++active_menu;
            }
            break;
        case 13:
            switch (active_menu) {
            case 1:
                system("cls");
                isUser = true;
                SignInUp(isUser);
                return;
            case 2:
                system("cls");
                isUser = false;
                SignInUp(isUser);
                return;
            case 3:
                exit(0);
                break;
            }
            break;
        
        }
    }
}