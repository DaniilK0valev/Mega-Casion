#include <iostream>
#include <string> // Нужно для написания строк
#include <cstdlib> // Нужно для использования рандома чисел
#include <ctime>
using namespace std;


class DataPlayer {
public:
    std::string name;
    int bal;
    int level;
    int bet;

    char Choice;
    int number1 = rand() % 10;
    int number2 = rand() % 10;
    int number3 = rand() % 10;
    int useNumber1;
    int useNumber2;
    int useNumber3;

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
};
auto rules();

auto rules1();

auto rules2();

auto infoNameBal(string name, int bal);

void End();

int Gratitude(int Balance);

void drawLine(int n, char symbol);

