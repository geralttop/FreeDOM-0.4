// Заголовочные файлы
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include "User.h" // Пользовательский заголовочный файл с определением класса User
#include "Lib.h" // Пользовательский заголовочый файл с определением функций
#include <Windows.h> // Библиотека для работы с Windows API
#include "Dev.h"
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <thread>

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
        devs.push_back(Dev(login, pass, fbalance, cardNum));
    }

    // Закрытие файлов после считывания данных
    ifDevLogin.close();
    ifDevPass.close();
    ifDevBalance.close();
    ifDevCardNum.close();

    // Возврат вектора разработчиков
    return devs;
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
    cout << "Введите логин и пароль";
    GoToXY(x, ++y);

    // Ввод логина пользователя
    std::cout << "login: ";
    std::getline(std::cin, signInLogin);

    // Ввод пароля пользователя
    GoToXY(x, ++y);
    std::cout << "pass: ";
    char ch;
    while ((ch = _getch()) != '\r') { // Чтение символов, пока не будет нажата Enter
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
                    GoToXY(x, ++y);
                    cout << "Вход выполнен успешно";
                }
                else {
                    // Если пароль неверный, выводим сообщение об ошибке и повторяем вход
                    GoToXY(x, ++y);
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
                SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }
            else {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
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
        std::cout << "Пароль не должен содержать пробелов.";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");
        return false;
    }

    // Проверка наличия строчных букв
    if (!hasLowercase) {
        GoToXY(15, 8);
        std::cout << "Пароль должен содержать хотя бы одну строчную букву.";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");
        return false;
    }

    // Проверка наличия прописных букв
    if (!hasUppercase) {
        GoToXY(15, 8);
        std::cout << "Пароль должен содержать хотя бы одну заглавную букву.";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        system("cls");
        return false;
    }

    // Проверка наличия цифр
    if (!hasDigit) {
        GoToXY(15, 8);
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
    cout << "Введите данные для регистрации";
    GoToXY(x, ++y);

    // Ввод логина пользователя
    cout << "login: ";
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
    cout << "pass: ";
    char ch;
    while (true) { // Бесконечный цикл для ввода пароля
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
            cout << "Введите данные для регистрации";
            GoToXY(x, ++y);

            // Ввод логина пользователя
            cout << "login: " << signUpLogin;
            GoToXY(x, ++y);

            // Ввод пароля пользователя
            cout << "pass: ";
        }
    }

    // Ввод повторного пароля пользователя
    GoToXY(x, ++y);
    std::cout << "repit pass: ";
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
    cout << "Введите данные для регистрации";
    GoToXY(x, ++y);

    // Ввод логина пользователя
    cout << "login: ";
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
            std::cout << "Такой логин уже занят";
            ConsoleCursorVisible(false, 100);
            this_thread::sleep_for(std::chrono::milliseconds(1200));
            system("cls");
            SignUpDev();
            return;
        }
    }

    GoToXY(x, ++y);
    cout << "CardNum: ";
    while (true) {
        getline(cin, signDevCardNum);
        if (!validateCardNumber(signDevCardNum)) {
            // Если номер карты не прошел валидацию, выводим сообщение и запрашиваем новый номер
            GoToXY(x, ++y);
            std::cout << "Некорректный номер карты";
            ConsoleCursorVisible(false, 100);
            this_thread::sleep_for(std::chrono::milliseconds(1200));
            system("cls");
            x = 15, y = 5;
            GoToXY(x, y);
            cout << "Введите данные для регистрации";
            GoToXY(x, ++y);

            // Ввод логина пользователя
            cout << "login: " << signUpLogin;
            GoToXY(x, ++y);

            // Ввод пароля пользователя
            cout << "CardNum: ";
        }
        else break;
    }

    GoToXY(x, ++y);
    // Ввод пароля пользователя
    cout << "pass: ";
    char ch;
    while (true) { // Бесконечный цикл для ввода пароля
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
            cout << "Введите данные для регистрации";
            GoToXY(x, ++y);

            // Ввод логина пользователя
            cout << "login: " << signUpLogin;
            GoToXY(x, ++y);

            //Ввовд номера карты
            cout << "CardNum: " << signDevCardNum;
            GoToXY(x, ++y);

            // Ввод пароля пользователя
            cout << "pass: ";
        }
    }

    // Ввод повторного пароля пользователя
    GoToXY(x, ++y);
    std::cout << "repit pass: ";
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
        std::cout << "Пароль неправильно повторен\n";
        ConsoleCursorVisible(false, 100);
        this_thread::sleep_for(std::chrono::milliseconds(1200));
        goto reppas;
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
    ofDevBalance << std::endl << 0;
    ofDevPass << std::endl << signUpPass;
    ofDevCardNum << std::endl << signDevCardNum;

    // Вывод сообщения об успешной регистрации
    GoToXY(x, ++y);
    std::cout << "Разработчик успешно зарегистрирован";

    // Закрытие файлов после записи данных
    ofDevLogin.close();
    ofDevBalance.close();
    ofDevPass.close();
    ofDevCardNum.close();
}

void topUp(User currentUser) {
    system("cls");
    int x = 10, y = 5;
    GoToXY(x, y);

    string addBalance;
    string cardNum;
    cout << "Введите сумму, которую хотите добавить";
    GoToXY(x, ++y);
    getline(cin, addBalance);
    GoToXY(x, ++y);

    cout << "CardNum: ";
    while (true) {
        getline(cin, cardNum);
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
            cout << addBalance;
            // Ввод логина пользователя
            GoToXY(x, ++y);
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
    UsCabinet(currentUser);
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
    int x = 3, y = 1;
    GoToXY(3, 1);
    cout << "Ваше имя: " << currentUser.getLogin();
    GoToXY(30, 1);
    cout << "Ваш баланс: " << currentUser.getBalance();

    string Menu[] = { "Пополнить баланс", "Список моих игр", "Поиск игр", "Выход на 1-ое окно", "Выход"};
    int active_menu = 0;

    // Переменная для чтения нажатых клавиш
    char ch;

    while (true) {
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
                topUp(currentUser);
                return;
                //balance
            case 1: // Вход как пользователь
                system("cls");
                return;
            case 2: // Вход как разработчик (не реализовано)
                system("cls");
                return;
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
            cout << "Эта великолепнейшая программа разработана величайшим Тимофеем Солдатенковым, с которым вы можете связаться через тг: @geralttop. В инсте, по идее, также. Хотелось бы сказать спасибо за помощь в разработке моим друзьям: Бордюру, Даниилу, МегаВане315. Спасибо Хидео Кодзиме за то, что он создал великолепнейшую игру, продолжение которой я очень жду. Спасибо моей бро Протасене (ударение на первое е. И мою бро зовут Полина, моя одноклассница, которая помогала мне в школе, которая заставила меня задуматься о современной молодежной моде и лицемерии. Спасибо Автору и левым за идеи, которые вложили в меня, и которые я вложил в этот проект.";
            _getch();
            system("cls");
            cout << " Ну и расскажу анекдот: Занимется сексом отец с сыном, и спрашивает его: 'Рад, что мать сдохла?'";
            return;
        }
    }
    _getch();
}
// Первое окно программы
void firstWin() {
    // Устанавливает размер окна консоли
    system("mode con cols=49 lines=15");
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
            cout << "Эта великолепнейшая программа разработана величайшим Тимофеем Солдатенковым, с которым вы можете связаться через тг: @geralttop. В инсте, по идее, также. Хотелось бы сказать спасибо за помощь в разработке моим друзьям: Бордюру, Даниилу, МегаВане315. Спасибо Хидео Кодзиме за то, что он создал великолепнейшую игру, продолжение которой я очень жду. Спасибо моей бро Протасене (ударение на первое е. И мою бро зовут Полина, моя одноклассница, которая помогала мне в школе, которая заставила меня задуматься о современной молодежной моде и лицемерии. Спасибо Автору и левым за идеи, которые вложили в меня, и которые я вложил в этот проект.";
            _getch();
            system("cls");
            cout << " Ну и расскажу анекдот: Занимется сексом отец с сыном, и спрашивает его: 'Рад, что мать сдохла?'";
            return;
        }
    }
}