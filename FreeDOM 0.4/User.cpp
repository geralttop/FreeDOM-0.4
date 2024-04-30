#include "User.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

User::User(string log, string p, float bal) {
	login = log;
	pass = p;
	balance = bal;
}
User::User() {

}
float User::getBalance() {
	return balance;
}
void User::setBalance(float bal) {
	balance = bal;
}

vector<User> User::writingUsers()
{
    vector<User> users; //создается вектор пользователей

    //открывает файлы для чтения
    ifstream ifUsLogin;
    ifstream ifUsPass;
    ifstream ifUsBalance;
    ifUsLogin.open("userNames.txt");
    ifUsPass.open("passOfUsers.txt");
    ifUsBalance.open("userBalances.txt");

    //цикл считывающий данные из файла и записывающий их в объекты пользователя
    while (!ifUsLogin.eof())
    {
        string login;
        string pass;
        string balance;

        getline(ifUsLogin, login);
        getline(ifUsPass, pass);
        getline(ifUsBalance, balance);
        float fbalance = stof(balance);

        users.push_back(User(login, pass, fbalance));
    }

    //закрытие считывания файла
    ifUsLogin.close();
    ifUsPass.close();
    ifUsBalance.close();

    return users;
}

void User::checkingLoginData(vector<User> users)
{
    string signInLogin;
    string signInPass;
    cin.ignore();
    std::cout << "login: ";
    std::getline(std::cin, signInLogin);
    std::cout << "pass: ";
    std::getline(std::cin, signInPass);
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == signInLogin) {
            if (users[i].getPass() == signInPass) {
                cout << "Вход выполнен успешно";
            }
            else {
                cout << "Введён неправильный пароль, попробуйте еще раз\n";
                checkingLoginData(users);
            }
            return;
        }
    }
    cout << "Введен неправильный логин, попробуйте еще раз\n";
    checkingLoginData(users);
    return;
}

void User::UsSignInUp(vector<User> users)
{
    int choose;
    cout << "1. Войти\n2. Зарегистрироваться\n";
    cin >> choose;
    system("cls");
    switch (choose)
    {
    case (1):
        checkingLoginData(users);
        break;
    case (2):
        SignInUs(users);
        break;
    default:
        break;
    }
}

bool User::validatePassword(const std::string& password)
{
    if (password.length() < 8) {
        std::cout << "Пароль должен содержать не менее 8 символов." << std::endl;
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
            std::cout << "Пароль не должен содержать кириллических символов." << std::endl;
            return false;
        }
    }

    if (hasSpace) {
        std::cout << "Пароль не должен содержать пробелов." << std::endl;
        return false;
    }

    if (!hasLowercase) {
        std::cout << "Пароль должен содержать хотя бы одну строчную букву." << std::endl;
        return false;
    }

    if (!hasUppercase) {
        std::cout << "Пароль должен содержать хотя бы одну заглавную букву." << std::endl;
        return false;
    }

    if (!hasDigit) {
        std::cout << "Пароль должен содержать хотя бы одну цифру." << std::endl;
        return false;
    }

    return true;
}

bool User::validateLogin(const std::string& login)
{
    // Проверка на длину логина
    if (login.length() < 6) {
        std::cout << "Длина логина должна быть не менее 6 символов.\n";
        return false;
    }

    // Проверка на наличие буквы и отсутствие кириллических символов
    bool hasLetter = false;
    for (char c : login) {
        if (isalpha(static_cast<unsigned char>(c))) {
            hasLetter = true;
        }
        // Проверка на кириллические символы
        if (c >= 128) {
            std::cout << "Логин не должен содержать кириллические символы.\n";
            return false;
        }
    }
    if (!hasLetter) {
        std::cout << "Логин должен содержать хотя бы одну букву.\n";
        return false;
    }

    // Проверка на отсутствие пробелов
    for (char c : login) {
        if (isspace(static_cast<unsigned char>(c))) {
            std::cout << "Логин не должен содержать пробелы.\n";
            return false;
        }
    }

    return true;
}

void User::SignInUs(std::vector<User> users)
{
    std::string signUpLogin;
    std::string signUpPass;
    std::string signUpRepitPass;
    std::cout << "login: ";
    std::cin >> signUpLogin;

    if (!validateLogin(signUpLogin)) {
        SignInUs(users); // Запрашиваем новый логин
        return;
    }

    for (auto& user : users) {
        if (signUpLogin == user.getLogin()) {
            system("cls");
            std::cout << "Такой логин уже занят\n";
            SignInUs(users);
            return;
        }
    }
    std::cout << "pass: ";
    std::cin.ignore(); // Очищаем буфер ввода перед чтением пароля
    std::getline(std::cin, signUpPass); // Считываем пароль с пробелами
    if (!validatePassword(signUpPass)) {
        SignInUs(users);
        return;
    }
    std::cout << "repit pass: ";
    std::getline(std::cin, signUpRepitPass); // Считываем повторный пароль с пробелами
    if (signUpPass != signUpRepitPass) {
        system("cls");
        std::cout << "Пароль неправильно повторен\n";
        SignInUs(users);
        return;
    }

    std::ofstream ofUsLogin;
    std::ofstream ofUsPass;
    std::ofstream ofUsBalance;
    ofUsLogin.open("userNames.txt", std::ofstream::app);
    ofUsBalance.open("userBalances.txt", std::ofstream::app);
    ofUsPass.open("passOfUsers.txt", std::ofstream::app);

    ofUsLogin << std::endl << signUpLogin;
    ofUsBalance << std::endl << 0;
    ofUsPass << std::endl << signUpPass;
    std::cout << "Пользователь успешно зарегистрирован";

    ofUsLogin.close();
    ofUsBalance.close();
    ofUsPass.close();
}
