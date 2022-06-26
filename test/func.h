#include <iostream>
#include <string> /// Нужно для написания строк
#include <cstdlib> /// Нужно для использования рандома чисел
#include <ctime>
using namespace std;


class DataPlayer {
    ///Все данные доступны всем функциям данного класса
public:
    std::string name;
    int bal;
    int level;
    int bet;
    ///Игра загадывает случайные цифры
    char Choice;
    int number1 = rand() % 10;
    int number2 = rand() % 10;
    int number3 = rand() % 10;
    int number4 = rand() % 10;
    int number5 = rand() % 10;
    ///Цифры, которые загадывает игрок
    int useNumber1, useNumber2, useNumber3, useNumber4, useNumber5;
    ///Пока значение правда, цикл с возможность повторить партию работает
    bool inGame = true;

    void readNameFromUser();

    auto getName();

    void readBalanceFromUser();

    auto getBalance();

    bool checkBal();

    int chooseLevel();

    bool checkLevel();

    void openBet();

    bool checkBet();

    void Level1();

    void Level2();

    void Level3();

    void GameOver();
};
auto rules();

auto rules1();

auto rules2();

void End();

void Gratitude(int Balance);

void drawLine(int n, char symbol);

