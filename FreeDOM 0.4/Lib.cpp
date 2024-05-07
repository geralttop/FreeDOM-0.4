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

using namespace std;

// Функция для чтения пользователей из файлов и записи их в вектор
vector<User> writingUsers() {
    // Создание вектора пользователей
    vector<User> users;

    // Открытие файлов для чтения
    ifstream ifUsLogin;
    ifstream ifUsPass;
    ifstream ifUsBalance;
    ifUsLogin.open("Data/userNames.txt");
    ifUsPass.open("Data/passOfUsers.txt");
    ifUsBalance.open("Data/userBalances.txt");

    // Цикл считывания данных из файлов и записи их в объекты пользователя
    // Цикл продолжается, пока не достигнут конец файла (eof) для ifUsLogin
    int i = 0;
    while (!ifUsLogin.eof()) {
        // Переменные для хранения данных пользователя
        string login;
        string pass;
        string balance;

        // Считывание данных из файлов
        getline(ifUsLogin, login);
        getline(ifUsPass, pass);
        getline(ifUsBalance, balance);

        // Преобразование строки с балансом в число с плавающей точкой
        float fbalance = stof(balance);

        // Создание объекта пользователя с прочитанными данными и добавление его в вектор
        users.push_back(User(login, pass, fbalance, i));
        i++;
    }

    // Закрытие файлов после считывания данных
    ifUsLogin.close();
    ifUsPass.close();
    ifUsBalance.close();

    // Возврат вектора пользователей
    return users;
}

vector<Dev> writingDevs() {
    // Создание вектора разработчиков
    std::vector<Dev> devs;

    // Открытие файлов для чтения
    std::ifstream ifDevLogin;
    std::ifstream ifDevPass;
    std::ifstream ifDevBalance;
    std::ifstream ifDevCardNum;

    ifDevLogin.open("Data/devNames.txt");
    ifDevPass.open("Data/passOfDevs.txt");
    ifDevBalance.open("Data/devBalances.txt");
    ifDevCardNum.open("Data/devCardNum.txt");

    // Цикл считывания данных из файлов и записи их в объекты разработчика
    // Цикл продолжается, пока не достигнут конец файла (eof) для ifDevLogin
    int i = 0;
    while (!ifDevLogin.eof()) {
        // Переменные для хранения данных разработчика
        std::string login;
        std::string pass;
        std::string balance;
        std::string cardNum;

        // Считывание данных из файлов
        std::getline(ifDevLogin, login);
        std::getline(ifDevPass, pass);
        std::getline(ifDevBalance, balance);
        std::getline(ifDevCardNum, cardNum);

        // Преобразование строки с балансом в число с плавающей точкой
        float fbalance = std::stof(balance);

        // Создание объекта разработчика с прочитанными данными и добавление его в вектор
        devs.push_back(Dev(login, pass, fbalance, cardNum , i));
        i++;
    }

    // Закрытие файлов после считывания данных
    ifDevLogin.close();
    ifDevPass.close();
    ifDevBalance.close();
    ifDevCardNum.close();

    // Возврат вектора разработчиков
    return devs;
}

vector<Game> writingDevGames(string devName) {
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

        if (price == "") price = "0";
        float fprice = stof(price);
        //cout << fprice;
        devGames.push_back(Game(name, about, fprice, i));
        i++;
    }

    ifAbout.close();
    ifName.close();
    ifPrice.close();

    return devGames;
}

vector<Game> writngAllGames() {
    /*std::vector<int> vec1{ 1, 2, 3, 4, 5 };
    std::vector<int> vec2{ 0, 9, 8, 7, 6 };
    std::vector<int> sum(vec1.size());
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    cout << vec1[6];*/
    vector<Game> allGames;
    vector<Dev> devs = writingDevs();
    for (int i = 0; i < devs.size(); i++) {
        vector<Game> devGames = writingDevGames(devs[i].getLogin());
        allGames.insert(allGames.end(), devGames.begin(), devGames.end());
    }
    return allGames;
}
//Все это надо для крутого меню
// Получаем дескриптор консоли
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

// Функция для перемещения курсора в консоли в позицию (x, y)
void GoToXY(short x, short y) {
    // Устанавливаем позицию курсора в консоли
    SetConsoleCursorPosition(hStdOut, { x, y });
}

// Функция для управления видимостью курсора в консоли
void ConsoleCursorVisible(bool show, short size) {
    // Получаем информацию о текущем состоянии курсора
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);

    // Изменяем видимость курсора
    structCursorInfo.bVisible = show;

    // Изменяем размер курсора
    structCursorInfo.dwSize = size;

    // Применяем изменения к состоянию курсора
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}
//Все, что надо было для крутого меню закончилось, не считая моего профессионализма

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
// Функция для входа пользователя в систему
void SignInUs(bool isUser) {
    // Отображение курсора в консоли и его видимость
    ConsoleCursorVisible(true, 100);
  
    vector<User> users  = writingUsers();
    vector<Dev> devs = writingDevs();
    //cout << devs[0].getLogin() << endl << devs[0].getPass() << endl << devs[0].getBalance() << endl << devs[0].getCardNum();
    // Переменные для хранения логина и пароля пользователя
    string signInLogin;
    string signInPass;

    // Координаты для отображения текста в консоли
    int x = 15, y = 5;
    GoToXY(x, y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "Введите логин и пароль";
    GoToXY(x, ++y);

    // Ввод логина пользователя
    std::cout << "login: ";
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    std::getline(std::cin, signInLogin);

    // Ввод пароля пользователя
    GoToXY(x, ++y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    std::cout << "pass: ";
    char ch;
    while ((ch = _getch()) != '\r') {
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);// Чтение символов, пока не будет нажата Enter
        if (ch == '\b') { // Если нажата клавиша Backspace
            if (!signInPass.empty()) {
                signInPass.pop_back(); // Удаляем последний символ
                cout << "\b \b"; // Выводим пробел и снова символ Backspace для удаления звездочки
            }
        }
        else {
            signInPass.push_back(ch); // Добавляем символ в пароль
            cout << '*'; // Выводим звездочку вместо символа
        }
    }
    cout << endl;

    if (isUser) {
        // Проверка логина и пароля для каждого пользователя в списке
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getLogin() == signInLogin) {
                // Если логин найден, проверяем пароль
                if (users[i].getPass() == signInPass) {
                    // Если пароль верный, выводим сообщение об успешном входе
                    UsCabinet(users[i]);
                }
                else {
                    // Если пароль неверный, выводим сообщение об ошибке и повторяем вход
                    GoToXY(x, ++y);
                    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
                    cout << "Введён неправильный пароль или логин";
                    this_thread::sleep_for(std::chrono::milliseconds(1200));
                    system("cls");
                    SignInUs(isUser);
                }
                // Выход из функции после успешного входа или после повторного ввода пароля
                return;
            }
        }
    }
    else {
        // Проверка логина и пароля для каждого пользователя в списке
        for (int i = 0; i < devs.size(); i++) {
            if (devs[i].getLogin() == signInLogin) {
                // Если логин найден, проверяем пароль
                if (devs[i].getPass() == signInPass) {
                    // Если пароль верный, выводим сообщение об успешном входе
                    DevCabinet(devs[i]);
                }
                else {
                    // Если пароль неверный, выводим сообщение об ошибке и повторяем вход
                    GoToXY(x, ++y);
                    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
                    cout << "Введён неправильный пароль или логин";
                    this_thread::sleep_for(std::chrono::milliseconds(1200));
                    system("cls");
                    SignInUs(isUser);
                }
                // Выход из функции после успешного входа или после повторного ввода пароля
                return;
            }
        }
    }
    
    

    // Если логин не найден, выводим сообщение об ошибке и повторяем вход
    GoToXY(x, ++y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "Введен неправильный пароль или логин\n";
    this_thread::sleep_for(std::chrono::milliseconds(1200));
    system("cls");
    SignInUs(isUser);
    // Выход из функции после повторного ввода логина
    return;
}

// Функция для отображения окна выбора авторизации или регистрации
void SignInUp(bool isUser) {
    // Массив пунктов меню для выбора действия
    string Menu[] = { "Войти", "Зарегистрироваться", "Назад", "Выход" };
    // Переменная для отслеживания активного пункта меню
    int active_menu = 0;

    // Флаг для управления циклом
    bool T = true;
    // Переменная для считывания нажатых клавиш
    char ch;
    // Бесконечный цикл для отображения меню и обработки ввода пользователя
    while (T) {
        int x = 15, y = 5;
        GoToXY(x, y);
        // Цикл для отображения пунктов меню
        for (int i = 0; i < size(Menu); i++) {
            // Установка цвета текста в зависимости от активного пункта меню
            if (i == active_menu) {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            }
            else {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
            }
            GoToXY(x, y++);
            cout << Menu[i] << endl;
        }
        // Считывание нажатой клавиши
        ch = _getch();
        // Обработка нажатий стрелок для перемещения по меню
        if (ch == -32) ch = _getch();
        switch (ch) {
        case 27: // ESC - выход из программы
            exit(0);
        case 72: // UP - перемещение вверх по меню
            if (active_menu == 0) {
                active_menu = size(Menu) - 1;
            }
            else if (active_menu > 0) {
                --active_menu;
            }
            break;
        case 80: // DOWN - перемещение вниз по меню
            if (active_menu == size(Menu) - 1) {
                active_menu = 0;
            }
            else if (active_menu < size(Menu) - 1) {
                ++active_menu;
            }
            break;
        case 13: // ENTER - выбор пункта меню
            switch (active_menu) {
            case 0: // Вход в систему
                system("cls");
                SignInUs(isUser);
                return;
            case 1: // Регистрация нового пользователя
                system("cls");
                if (isUser)
                    SignUpUs();
                else
                    SignUpDev();
                return;
            case 2: // Возврат в предыдущее окно
                system("cls");
                firstWin();
                return;
            case 3: // Выход из программы
                exit(0);
                break;
            }
            break;
        case 32: // SPACE - ничего не делает, так как меню не должно реагировать на пробел
            break;
        }
    }
}

// Функция для валидации пароля
bool validatePassword(const std::string& password) {
    // Проверка длины пароля
    if (password.length() < 8) {
        // Перемещение курсора в консоли и вывод сообщения об ошибке
        GoToXY(15, 8);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Пароль должен содержать не менее 8 символов.";
        // Скрытие курсора и задержка перед очисткой экрана
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        return false;
    }

    // Флаги для проверки наличия строчных букв, прописных букв, цифр и пробелов
    bool hasLowercase = false;
    bool hasUppercase = false;
    bool hasDigit = false;
    bool hasSpace = false;

    // Проверка каждого символа в пароле
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
            // Проверка на кириллические символы
            GoToXY(15, 8);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            std::cout << "Пароль не должен содержать кириллических символов.";
            ConsoleCursorVisible(false, 100);
            this_thread::sleep_for(std::chrono::milliseconds(1200));
            system("cls");
            return false;
        }
    }

    // Проверка наличия пробелов
    if (hasSpace) {
        GoToXY(15, 8);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Пароль не должен содержать пробелов.";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");
        return false;
    }

    // Проверка наличия строчных букв
    if (!hasLowercase) {
        GoToXY(15, 8);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Пароль должен содержать хотя бы одну строчную букву.";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");
        return false;
    }

    // Проверка наличия прописных букв
    if (!hasUppercase) {
        GoToXY(15, 8);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Пароль должен содержать хотя бы одну заглавную букву.";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");
        return false;
    }

    // Проверка наличия цифр
    if (!hasDigit) {
        GoToXY(15, 8);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Пароль должен содержать хотя бы одну цифру.";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");
        return false;
    }

    // Если все проверки пройдены успешно, возвращаем true
    return true;
}

// Функция для валидации логина
bool validateLogin(const std::string& login) {
    // Проверка длины логина
    if (login.length() < 6) {
        // Перемещение курсора в консоли и вывод сообщения об ошибке
        GoToXY(15, 7);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Длина логина должна быть не менее 6 символов.\n";
        // Скрытие курсора и задержка перед очисткой экрана
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");
        return false;
    }

    // Флаг для проверки наличия буквы в логине
    bool hasLetter = false;
    for (char c : login) {
        // Проверка на буквенный символ
        if (isalpha(static_cast<unsigned char>(c))) {
            hasLetter = true;
        }
        // Проверка на кириллические символы
        if (!isascii(c)) {
            GoToXY(15, 7);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            std::cout << "Логин не должен содержать кириллические символы.\n";
            ConsoleCursorVisible(false, 100);
            this_thread::sleep_for(std::chrono::milliseconds(1200));
            system("cls");
            return false;
        }
    }
    // Проверка наличия буквы в логине
    if (!hasLetter) {
        GoToXY(15, 7);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Логин должен содержать хотя бы одну букву.\n";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");
        return false;
    }

    // Проверка на отсутствие пробелов в логине
    for (char c : login) {
        // Проверка на пробельный символ
        if (isspace(static_cast<unsigned char>(c))) {
            GoToXY(15, 7);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            std::cout << "Логин не должен содержать пробелы.\n";
            ConsoleCursorVisible(false, 100);
            this_thread::sleep_for(std::chrono::milliseconds(1200));
            system("cls");
            return false;
        }
    }
    // Если все проверки пройдены успешно, возвращаем true
    return true;
}

bool validateCardNumber(const std::string& cardNumber) {
    // Проверка на длину номера карты
    if (cardNumber.length() != 16) {
        return false;
    }

    // Проверка на то, что все символы - цифры
    for (char ch : cardNumber) {
        if (!isdigit(ch)) {
            return false;
        }
    }

    // Если номер карты прошел все проверки, возвращаем true
    return true;
}

bool validateGameName(const std::string& name) {
    if (name.length() <= 5) {
        return false;
    }

    // Регулярное выражение для поиска букв (русских или английских)
    std::regex letterRegex("[а-яА-Яa-zA-Z]");
    return std::regex_search(name, letterRegex);
}

// Функция для регистрации нового пользователя
void SignUpUs() {
    vector<User> users = writingUsers();
    // Отображение курсора в консоли и его видимость
    ConsoleCursorVisible(true, 100);

    // Переменные для хранения логина, пароля и повторного ввода пароля
    string signUpLogin;
    string signUpPass;
    string signUpRepitPass;

    // Координаты для отображения текста в консоли
    int x = 15, y = 5;
    GoToXY(x, y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "Введите данные для регистрации";
    GoToXY(x, ++y);

    // Ввод логина пользователя
    cout << "login: ";
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    getline(cin, signUpLogin);

    // Валидация логина
    if (!validateLogin(signUpLogin)) {
        // Если логин не прошел валидацию, запрашиваем новый логин
        SignUpUs();
        return;
    }
    User currentUser;
    // Проверка наличия логина в базе пользователей
    for (auto& user : users) {
        if (signUpLogin == user.getLogin()) {
            // Если логин уже занят, выводим сообщение и запрашиваем новый логин
            GoToXY(x, ++y);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            std::cout << "Такой логин уже занят";
            ConsoleCursorVisible(false, 100);
            this_thread::sleep_for(std::chrono::milliseconds(1200));
            system("cls");
            SignUpUs();
            return;
        }
    }

    GoToXY(x, ++y);

    // Ввод пароля пользователя
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "pass: ";
    char ch;
    while (true) {
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);// Бесконечный цикл для ввода пароля
        signUpPass.clear(); // Очищаем переменную для пароля
        while ((ch = _getch()) != '\r') { // Чтение символов, пока не будет нажата Enter
            if (ch == '\b') { // Если нажата клавиша Backspace
                if (!signUpPass.empty()) {
                    signUpPass.pop_back(); // Удаляем последний символ
                    cout << "\b \b"; // Выводим пробел и снова символ Backspace для удаления звездочки
                }
            }
            else {
                signUpPass.push_back(ch); // Добавляем символ в пароль
                cout << '*'; // Выводим звездочку вместо символа
            }
        }
        cout << endl;

        // Валидация пароля
        if (validatePassword(signUpPass)) {
            break; // Если пароль прошел валидацию, выходим из цикла
        }
        else {
            reppas:
            // Если пароль не прошел валидацию, выводим сообщение и просим ввести заново
            system("cls");
            x = 15, y = 5;
            GoToXY(x, y);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            cout << "Введите данные для регистрации";
            GoToXY(x, ++y);

            // Ввод логина пользователя
            cout << "login: "; 
            SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
            cout << signUpLogin;
            GoToXY(x, ++y);

            // Ввод пароля пользователя
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            cout << "pass: ";
        }
    }

    // Ввод повторного пароля пользователя
    GoToXY(x, ++y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    std::cout << "repit pass: ";
    signUpRepitPass.clear(); // Очищаем переменную для повторного ввода пароля
    while ((ch = _getch()) != '\r') {
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);// Чтение символов, пока не будет нажата Enter
        if (ch == '\b') { // Если нажата клавиша Backspace
            if (!signUpRepitPass.empty()) {
                signUpRepitPass.pop_back(); // Удаляем последний символ
                cout << "\b \b"; // Выводим пробел и снова символ Backspace для удаления звездочки
            }
        }
        else {
            signUpRepitPass.push_back(ch); // Добавляем символ в пароль
            cout << '*'; // Выводим звездочку вместо символа
        }
    }
    cout << endl;

    // Проверка соответствия паролей
    if (signUpPass != signUpRepitPass) {
        // Если пароли не совпадают, выводим сообщение и запрашиваем новый пароль
        GoToXY(x, ++y);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Пароль неправильно повторен\n";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        goto reppas;
    }
    users.push_back(User(signUpLogin, signUpPass, 0, users.size()));
    // Открытие файлов для записи данных пользователя
    std::ofstream ofUsLogin;
    std::ofstream ofUsPass;
    std::ofstream ofUsBalance;
    ofUsLogin.open("Data/userNames.txt", std::ofstream::app);
    ofUsBalance.open("Data/userBalances.txt", std::ofstream::app);
    ofUsPass.open("Data/passOfUsers.txt", std::ofstream::app);

    // Запись данных пользователя в файлы
    ofUsLogin << std::endl << signUpLogin;
    ofUsBalance << std::endl << 0;
    ofUsPass << std::endl << signUpPass;

    // Закрытие файлов после записи данных
    ofUsLogin.close();
    ofUsBalance.close();
    ofUsPass.close();

    // Вывод сообщения об успешной регистрации
    UsCabinet(users[users.size()-1]);

    
}

void SignUpDev() {
    vector<Dev> devs = writingDevs();

    ConsoleCursorVisible(true, 100);

    // Переменные для хранения логина, пароля и повторного ввода пароля
    string signUpLogin;
    string signUpPass;
    string signUpRepitPass;
    string signDevCardNum;

    // Координаты для отображения текста в консоли
    int x = 15, y = 5;
    GoToXY(x, y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "Введите данные для регистрации";
    GoToXY(x, ++y);

    // Ввод логина пользователя
    cout << "login: ";
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    getline(cin, signUpLogin);

    // Валидация логина
    if (!validateLogin(signUpLogin)) {
        // Если логин не прошел валидацию, запрашиваем новый логин
        SignUpDev();
        return;
    }

    // Проверка наличия логина в базе пользователей
    for (auto& dev : devs) {
        if (signUpLogin == dev.getLogin()) {
            // Если логин уже занят, выводим сообщение и запрашиваем новый логин
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
        getline(cin, signDevCardNum);
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
            cout << "login: ";
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
    // Ввод пароля пользователя
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "pass: ";
    
    char ch;
    while (true) { // Бесконечный цикл для ввода пароля
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
        signUpPass.clear(); // Очищаем переменную для пароля
        while ((ch = _getch()) != '\r') { // Чтение символов, пока не будет нажата Enter
            if (ch == '\b') { // Если нажата клавиша Backspace
                if (!signUpPass.empty()) {
                    signUpPass.pop_back(); // Удаляем последний символ
                    cout << "\b \b"; // Выводим пробел и снова символ Backspace для удаления звездочки
                }
            }
            else {
                signUpPass.push_back(ch); // Добавляем символ в пароль
                cout << '*'; // Выводим звездочку вместо символа
            }
        }
        cout << endl;

        // Валидация пароля
        if (validatePassword(signUpPass)) {
            break; // Если пароль прошел валидацию, выходим из цикла
        }
        else {
        reppasdev:
            // Если пароль не прошел валидацию, выводим сообщение и просим ввести заново
            system("cls");
            x = 15, y = 5;
            GoToXY(x, y);
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            cout << "Введите данные для регистрации";
            GoToXY(x, ++y);

            // Ввод логина пользователя
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            cout << "login: ";
            SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
            cout << signUpLogin;
            GoToXY(x, ++y);

            //Ввовд номера карты
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            cout << "CardNum: ";
            SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
            cout << signDevCardNum;
            GoToXY(x, ++y);

            // Ввод пароля пользователя
            SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
            cout << "pass: ";
        }
    }

    // Ввод повторного пароля пользователя
    GoToXY(x, ++y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    std::cout << "repit pass: ";
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    signUpRepitPass.clear(); // Очищаем переменную для повторного ввода пароля
    while ((ch = _getch()) != '\r') { // Чтение символов, пока не будет нажата Enter
        if (ch == '\b') { // Если нажата клавиша Backspace
            if (!signUpRepitPass.empty()) {
                signUpRepitPass.pop_back(); // Удаляем последний символ
                cout << "\b \b"; // Выводим пробел и снова символ Backspace для удаления звездочки
            }
        }
        else {
            signUpRepitPass.push_back(ch); // Добавляем символ в пароль
            cout << '*'; // Выводим звездочку вместо символа
        }
    }
    cout << endl;

    // Проверка соответствия паролей
    if (signUpPass != signUpRepitPass) {
        // Если пароли не совпадают, выводим сообщение и запрашиваем новый пароль
        GoToXY(x, ++y);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        std::cout << "Пароль неправильно повторен\n";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        goto reppasdev;
        return;
    }
    
    
    // Открытие файлов для записи данных пользователя
    std::ofstream ofDevLogin;
    std::ofstream ofDevPass;
    std::ofstream ofDevBalance;
    std::ofstream ofDevCardNum;
    ofDevLogin.open("Data/devNames.txt", std::ofstream::app);
    ofDevBalance.open("Data/devBalances.txt", std::ofstream::app);
    ofDevPass.open("Data/passOfDevs.txt", std::ofstream::app);
    ofDevCardNum.open("Data/devCardNum.txt", std::ofstream::app);

    // Запись данных пользователя в файлы
    ofDevLogin << std::endl << signUpLogin;
    ofDevBalance << std::endl << "0";
    ofDevPass << std::endl << signUpPass;
    ofDevCardNum << std::endl << signDevCardNum;

    // Вывод сообщения об успешной регистрации
    devs.push_back(Dev(signUpLogin, signUpPass, 0, signDevCardNum, devs.size()));

    // Закрытие файлов после записи данных
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

    DevCabinet(devs[devs.size() - 1]);
}

void topUp(User currentUser) {
    system("cls");
    int x = 10, y = 5;
    GoToXY(x, y);

    string addBalance;
    string cardNum;
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "Введите сумму, которую хотите добавить";
    GoToXY(x, ++y);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
    getline(cin, addBalance);
    GoToXY(x, ++y);

    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << "CardNum: ";
    while (true) {
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
        getline(cin, cardNum);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        if (!validateCardNumber(cardNum)) {
            // Если номер карты не прошел валидацию, выводим сообщение и запрашиваем новый номер
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
            // Ввод логина пользователя
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

void writeOff(Dev currenDev) {
    vector<Dev> devs = writingDevs();
    currenDev.setBalance(0);
    devs[currenDev.getIndex()].setBalance(currenDev.getBalance());
    
    ofstream ofDevBalance;
    ofDevBalance.open("Data/devBalances.txt");
    ofDevBalance << devs[0].getBalance();
    for (int i = 1; i < devs.size(); i++) {
        ofDevBalance << endl << devs[i].getBalance();
    }

    ofDevBalance.close();
    DevCabinet(currenDev);
    return;
}

void UsCabinet(User currentUser) {
    ConsoleCursorVisible(false, 100);
    system("cls");
    system("mode con cols=49 lines=15");
    /*int x = 10, y = 5;
    GoToXY(x, y);
    cout << "Ваш баланс:";
    GoToXY(x, ++y);
    cout << currentUser.getBalance();
    GoToXY(x, ++y);
    cout << "Ваше имя:";
    GoToXY(x, ++y);
    cout << currentUser.getLogin();*/
    

    string Menu[] = { "Пополнить баланс", "Список моих игр", "Поиск игр", "Выход на 1-ое окно", "Выход"};
    int active_menu = 0;

    // Переменная для чтения нажатых клавиш
    char ch;

    while (true) {
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        int x = 3, y = 1;
        GoToXY(3, 1);
        cout << "Ваше имя: " << currentUser.getLogin();
        GoToXY(30, 1);
        cout << "Ваш баланс: " << currentUser.getBalance();
        x = 15, y = 5;
        GoToXY(x, y);
        // Цикл для отображения пунктов меню
        for (int i = 0; i < size(Menu); i++) {
            // Установка цвета текста в зависимости от активного пункта меню
            if (i == active_menu) {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            }
            else {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
            }
            GoToXY(x, y++);
            cout << Menu[i] << endl;
        }
        // Считывание нажатой клавиши
        ch = _getch();
        // Обработка нажатий стрелок для перемещения по меню
        if (ch == -32) ch = _getch();
        switch (ch) {
        case 27: // ESC - выход из программы
            exit(0);
        case 72: // UP - перемещение вверх по меню
            if (active_menu == 0) {
                active_menu = size(Menu) - 1;
            }
            else if (active_menu > 0) {
                --active_menu;
            }
            break;
        case 80: // DOWN - перемещение вниз по меню
            if (active_menu == size(Menu) - 1) {
                active_menu = 0;
            }
            else if (active_menu < size(Menu) - 1) {
                ++active_menu;
            }
            break;
        case 13: // ENTER - выбор пункта меню
            switch (active_menu) {
            case 0:
                topUp(currentUser);
                return;
                //balance
            case 1: // Вход как пользователь
                system("cls");
                return;
            case 2: // Вход как разработчик (не реализовано)
                system("cls");
                GamesList(writngAllGames());
                break;
            case 3: // Выход из программы
                system("cls");
                firstWin();
                return;
            case 4:
                exit(0);
                return;
            }
            break;
        case 32: // SPACE - вывод информации о разработчике и выход из меню
            system("cls");
 
            _getch();
            system("cls");
            cout << " Ну и расскажу анекдот: Занимется сексом отец с сыном, и спрашивает его: 'Рад, что мать сдохла?'";
            return;
        }
    }
    _getch();
}

void PageList(Game game) {
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    system("cls");
    GoToXY(5, 1);
    cout << game.getName();
    GoToXY(40, 1);
    cout << game.getPrice();
    BigText(2, 3, 48, game.getAbout());
    /*GoToXY(5, 2);
    cout << game.getAbout();*/
    while (true) {
        char ch = _getch();
        if (ch == 27) {
            system("cls");
            return;
        }
    }
}

void FindGame(vector<Game> games) {
    vector<Game> filtergames;

    cout << "Введите название игры";
    string name;
    getline(cin, name);

    for (int i = 0; i < games.size(); i++) {
        size_t found = games[i].getName().find(name);
        if (found != std::string::npos) filtergames.push_back(games[i]);
    }

    system("cls");
    GamesList(filtergames);
    return;
}

void GamesList(vector<Game> games) {
    
    int x = 5, x1 = 40, y = 1;

    int active_menu = 0;

    // Переменная для чтения нажатых клавиш
    char ch;
    int minShowGame = 0, maxShomGame = 10;
    if (maxShomGame > games.size()) maxShomGame = games.size();
    while (true) {
        GoToXY(10, 12);
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        cout << "<- Пр. Стр.          Сл. Стр. -> ";
        GoToXY(10, 13);
        cout << "Назад(Ecs)        Поиск игр(Space)";
        bool isCanNext = true, isCanPrev = true;
        int x = 5, x1 = 42, y = 1;
        GoToXY(x, y);
        // Цикл для отображения пунктов меню
        for (int i = minShowGame; i < maxShomGame; i++) {
            // Установка цвета текста в зависимости от активного пункта меню
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
            cout << games[i].getPrice();
        }
        // Считывание нажатой клавиши
        ch = _getch();
        // Обработка нажатий стрелок для перемещения по меню
        if (ch == -32) ch = _getch();
        switch (ch) {
        case 27: // ESC - выход из программы
            system("cls");
            return;
        case 72: // UP - перемещение вверх по меню
            
            if (active_menu > 0) {
                --active_menu;
                if (active_menu < minShowGame) {
                    system("cls");
                    maxShomGame = active_menu + 1;
                    if (minShowGame - 10 < 0) {
                        minShowGame = 0;
                    }
                    else minShowGame -= 10;

                }
            }
            break;
        case 80: // DOWN - перемещение вниз по меню
            
            if (active_menu < games.size() - 1) {
                ++active_menu;
                if (active_menu > maxShomGame - 1) {
                    system("cls");
                    minShowGame = active_menu;
                    if (maxShomGame + 10 > games.size())
                        maxShomGame = games.size();
                    else maxShomGame += 10;
                }
            }
            break;
        case 77:
            system("cls");
            if (maxShomGame + 10 > games.size()) {
                if (minShowGame + 10 < games.size()) {
                    minShowGame += 10;
                    if (active_menu + 10 > games.size()) active_menu += games.size() - 1;
                    else active_menu += 10;
                }
               
                maxShomGame = games.size();
            }
            else {
                active_menu += 10;
                minShowGame += 10;
                maxShomGame += 10;
            }
            break;
        case 75:
            system("cls");
            if (minShowGame - 10 < 0) {
                minShowGame = 0;
                if (maxShomGame - 10 < 0) {
                    maxShomGame = 10;
                }
                if (maxShomGame > games.size()) maxShomGame = games.size();
            }
            else {
                active_menu -= 10;
                maxShomGame = minShowGame;
                minShowGame -= 10;
            }
            break;
        case 13: // ENTER - выбор пункта меню
            PageList(games[active_menu]);
            //return;
            break;
        case 70: // SPACE - вывод информации о разработчике и выход из меню
            system("cls");
            _getch();
            system("cls");
            cout << " Ну и расскажу анекдот: Занимется сексом отец с сыном, и спрашивает его: 'Рад, что мать сдохла?'";
            return;
        case 32:
            system("cls");
            FindGame(games);
            break;
        }
    }



    /*for (int i = 0; i < games.size(); i++) {
        y += 1;
        GoToXY(x, y);
        cout << games[i].getName();
        GoToXY(x1, y);
        cout << games[i].getPrice();
    }*/
    _getch();
}

void addGame(string DevName) {
    system("cls");
    vector<Game> allGames = writngAllGames();
    int x = 10, y = 2;

    string name;
    string about;
    string price;

    GoToXY(x, y);
    cout << "Название игры: ";
    getline(cin, name);

    if (!validateGameName(name)) {
        GoToXY(x, ++y);
        cout << "Название игры должно быть длиннее 5 символов и содержать хотя бы 1 букву." << endl;
        this_thread::sleep_for(chrono::milliseconds(1200));
        addGame(DevName);
        return;
    }
    for (int i = 0; i < allGames.size(); i++) {
        if (name == allGames[i].getName()) {
            GoToXY(x, ++y);
            cout << "Такое название уже занято";
            this_thread::sleep_for(std::chrono::milliseconds(1200));
            addGame(DevName);
            return;
        }
    }
    

    GoToXY(x, ++y);
    cout << "Цена для игры: ";
    getline(cin, price);

    GoToXY(x, ++y);
    cout << "Описание игры: ";
    GoToXY(3, ++y);
    getline(cin, about); //440 символов максимум

    ofstream ofGameName;
    ofstream ofAboutGame;
    ofstream ofPriceGame;

    ofGameName.open("Data/DevGames/" + DevName + "Games.txt", ofstream::app);
    ofAboutGame.open("Data/DevGames/About/" + DevName + "About.txt", ofstream::app);
    ofPriceGame.open("Data/DevGames/Price/" + DevName + "Price.txt", ofstream::app);
    
    if (writingDevGames(DevName)[0].getName() == "") {
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

    string Menu[] = { "Списать деньги на карту", "Список моих игр", "Добавить игру", "Выход на 1-ое окно", "Выход" };
    int active_menu = 0;

    // Переменная для чтения нажатых клавиш
    char ch;

    while (true) {
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
        GoToXY(3, 1);
        cout << "Ваша назва: " << currentDev.getLogin();
        GoToXY(30, 1);
        cout << "Ваш баланс: " << currentDev.getBalance();
        int x = 15, y = 5;
        GoToXY(x, y);
        // Цикл для отображения пунктов меню
        for (int i = 0; i < size(Menu); i++) {
            // Установка цвета текста в зависимости от активного пункта меню
            if (i == active_menu) {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            }
            else {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
            }
            GoToXY(x, y++);
            cout << Menu[i] << endl;
        }
        // Считывание нажатой клавиши
        ch = _getch();
        // Обработка нажатий стрелок для перемещения по меню
        if (ch == -32) ch = _getch();
        switch (ch) {
        case 27: // ESC - выход из программы
            exit(0);
        case 72: // UP - перемещение вверх по меню
            if (active_menu == 0) {
                active_menu = size(Menu) - 1;
            }
            else if (active_menu > 0) {
                --active_menu;
            }
            break;
        case 80: // DOWN - перемещение вниз по меню
            if (active_menu == size(Menu) - 1) {
                active_menu = 0;
            }
            else if (active_menu < size(Menu) - 1) {
                ++active_menu;
            }
            break;
        case 13: // ENTER - выбор пункта меню
            switch (active_menu) {
            case 0:
                bankRequest();
                writeOff(currentDev);
                return;
                //balance
            case 1: // Вход как пользователь
                system("cls");
                GamesList(writingDevGames(currentDev.getLogin()));
                break;
            case 2: // Вход как разработчик (не реализовано)
                //system("cls");
                addGame(currentDev.getLogin());
                break;
            case 3: // Выход из программы
                system("cls");
                firstWin();
                return;
            case 4:
                exit(0);
                return;
            }
            break;
        case 32: // SPACE - вывод информации о разработчике и выход из меню
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
    cout << "Синие текст -- это просто текст\nКрасный текст -- это кнопки между которыми можно переключаться с помощью стрелок вверх-вниз\nЗеленый -- ввод значений с клавиатуры";
    _getch();
    system("cls");
}
// Первое окно программы
void firstWin() {
    // Устанавливает размер окна консоли
    system("mode con cols=49 lines=15");
    //AboutApp();
    // Отключает видимость курсора в консоли
    ConsoleCursorVisible(false, 100);

    // Массив пунктов меню
    string Menu[] = { "Войти как", "User", "Developer", "Выход" };

    // Переменная для отслеживания активного пункта меню
    int active_menu = 1;

    // Переменная для чтения нажатых клавиш
    char ch;

    bool isUser;

    // Бесконечный цикл для отображения меню и обработки ввода пользователя
    GoToXY(15, 5);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
    cout << Menu[0];
    while (true) {
        int x = 15, y = 6;
        GoToXY(x, y);
        // Цикл для отображения пунктов меню
        for (int i = 1; i < size(Menu); i++) {
            // Установка цвета текста в зависимости от активного пункта меню
            if (i == active_menu) {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            }
            else {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
            }
            GoToXY(x, y++);
            cout << Menu[i] << endl;
        }
        // Считывание нажатой клавиши
        ch = _getch();
        // Обработка нажатий стрелок для перемещения по меню
        if (ch == -32) ch = _getch();
        switch (ch) {
        case 27: // ESC - выход из программы
            exit(0);
        case 72: // UP - перемещение вверх по меню
            if (active_menu == 1) {
                active_menu = size(Menu) - 1;
            }
            else if (active_menu > 1) {
                --active_menu;
            }
            break;
        case 80: // DOWN - перемещение вниз по меню
            if (active_menu == size(Menu) - 1) {
                active_menu = 1;
            }
            else if (active_menu < size(Menu) - 1) {
                ++active_menu;
            }
            break;
        case 13: // ENTER - выбор пункта меню
            switch (active_menu) {
            case 1: // Вход как пользователь
                system("cls");
                isUser = true;
                SignInUp(isUser);
                return;
            case 2: // Вход как разработчик (не реализовано)
                system("cls");
                isUser = false;
                SignInUp(isUser);
                return;
            case 3: // Выход из программы
                exit(0);
                break;
            }
            break;
        case 32: // SPACE - вывод информации о разработчике и выход из меню
            system("cls");
            cout << "Какой же Кодзима гений";
            _getch();
            system("cls");
            cout << " Ну и расскажу анекдот: Занимется сексом отец с сыном, и спрашивает его: 'Рад, что мать сдохла?'";
            return;
        }
    }
}