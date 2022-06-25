#include <iostream>
#include <string> // Нужно для написания строк
#include <cstdlib> // Нужно для использования рандома чисел
#include <ctime>
using namespace std;

void End();
int Gratitude(int Balance);
void drawLine(int n, char symbol);
void printProgress ();

class DataPlayer{
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
public:
    void readNameFromUser(){
        std::cout << "\n\nEnter your name : ";
        getline(cin, name);
    }
    auto getName(){
        return name;
    }
    int readBalanceFromUser(){
        do{
            cout << "\n\nEnter deposit amount to play game: $";
            cin >> bal;
            if (bal<50){
                cout << "Please! Specify the correct balance!\n"
                     <<"\nRe-enter data\n ";
            }
        }while(bal<50);
    }
    auto getBalance(){
        return bal;
    }
    int chooseLevel(){
        do{
            cin >> level;
            if ((level==2 && bal<150) || (level==3 && bal<500))
            {
                cout << "You don't have enough money for the current level of the game!\n"
                     <<"\nRe-enter data\n ";}
        }while((level==2 && bal<150) || (level==3 && bal<500));
        return level;
    }
    int openBet(){
        do
        {
            cout << "\n" << name <<", enter money to bet : $";
            cin >> bet;
            if(bet > bal)
            {
                cout << "Your betting amount is more than your current balance\n"
                     <<"\nRe-enter data\n ";
            }
        }while(bet > bal);
    }
    int Level1(){
        do{
            cout << "Guess your number to bet between 0 to 9 :";
            cin >> useNumber1;
            if(useNumber1 < 0 || useNumber1 > 9){
                cout << "Please check the number! should be between 0 to 9\n"
                <<"\nRe-enter data\n ";
            }
        }while(useNumber1 < 0 || useNumber1 > 9);
        if(number1 == useNumber1)
        {
            cout << "\n\nGood Luck!! You won $" << bet * 2;
            bal = bal + bet * 2;
        }
        else
        {
            cout << "Bad Luck this time !! You lost $ "<< bet <<"\n";
            bal = bal - bet;
        }
        cout << "\nThe winning number was: " << number1 <<"\n";
        cout << "\n"<<name<<", You have $ " << bal << "\n";
        if(bal == 0)
        {
            End();
        }
        else{
            cout << "\n\n-->Do you want to play again (y/n)? ";
            cin >> Choice;
            if (Choice=='Y' || Choice=='y'){
                End();
            }
            else{
                End();
                Gratitude(bal);
            }
        }
    }
    int Level2(){
        do
        {
            cout << "Guess your numbers to bet between 0 to 9 :";
            cin >> useNumber1 >> useNumber2 >> useNumber3;
            if((useNumber1 < 0 || useNumber1 > 9) || (useNumber2 < 0 || useNumber2 > 9) || (useNumber3 < 0 || useNumber3 > 9))
                cout << "Please check the number! should be between 0 to 9\n"
                     <<"\nRe-enter data\n ";
        }
        while((useNumber1 < 0 || useNumber1 > 9) || (useNumber2 < 0 || useNumber2 > 9) || (useNumber3 < 0 || useNumber3 > 9));

        if (useNumber1==5 && useNumber2 == 1 && useNumber3==3){
            cout << "\n\nWow! You unlock easter egg! You get super price! "<< bet * 100;
            bal = bal + bet * 100;
        }
        else if (number1 == useNumber1 && number2 == useNumber2 && number3 == useNumber3){
            cout << "\n\nGood Luck!! You won $" << bet * 5;
            bal = bal + bet * 5;
        }
        else if (number1 ==7 && number2 == 7 && number3==7){
            cout << "\n\nUltra Luck!! You won $" << bet*7;
            bal = bal + bet * 7;
        }
        else if (number1 == number2 && number2 == number3 && number3 == number1){
            cout << "\n\nMega Luck! You won $" << 100*number1;
            bal = bal + 100*number1;
        }
        else{
            cout << "Bad Luck this time !! You lost $ "<< bet*2 <<"\n";
            bal = bal - bet*2;
        }
        cout << "\nThe winning number was: " << number1 << number2 << number3 <<"\n";
        cout << "\n"<<name<<", You have $ " << bal << "\n";
        if(bal == 0)
        {

            End();
        }
        else{
            cout << "\n\n-->Do you want to play again (y/n)? ";
            cin >> Choice;
            if (Choice=='Y' || Choice=='y'){

            }
            else{
                End();
                Gratitude(bal);
            }
        }
    }

};

auto rules() {
    cout << "\n\n";
    drawLine(70, '-');
    cout << "\t\tWELCOME IN OUR CASINO!\n";
    drawLine(70, '-');
    cout << "\tYou can choose 3 difficulty levels. The higher the level, more the winnings and more loss!\n";
    cout << "\tEach level requires more balance\n";
    cout << "\t1 level - Guess one number. Minimum: $50\n";
    cout << "\t2 level - Guess three numbers. Minimum: $150\n";
    cout << "\t3 level - Guess five numbers. Minimum: $500\n";
}
auto rules1(){
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 0 to 9\n";
    cout << "\t2. If you win you will get 2 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}

auto rules2(){
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any combination of three numbers between 0 to 9. You can choose the same ones\n";
    cout << "\t2. If you win you will get 5 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}

auto infoNameBal(string name, int bal){
        cout << "\n\nYour current balance is $ " << bal << "\n";
        cout << "\n" << name << ", choose level (1,2,3):";
};

void End(){
    cout << "\n\n";
    drawLine(45,'-');
    cout << "\t\tGAME OVER\n";
    drawLine(45,'-');

}
int Gratitude(int Balance){
    if (Balance==0){
        cout << "\n\nThanks for playing game. You have no money to play";
    }
    else{
        cout << "\n\nThanks for playing game. Your balance amount is $ " << Balance << "\n\n";
    }
    drawLine(60, '=');
}
void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}


int main() {
    srand(time(0));

    DataPlayer Player;

    string PlayerName;
    int Balance;
    int Level;

    drawLine(50, '_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
    drawLine(50, '_');
    Player.readNameFromUser();
    Player.readBalanceFromUser();
    PlayerName = Player.getName();
    Balance = Player.getBalance();
    rules();
    infoNameBal(PlayerName, Balance);

    Level = Player.chooseLevel();

    Player.openBet();
    if (Level == 1){
        rules1();
        Player.Level1();
    }
    if (Level == 2){
        rules2();
        Player.Level2();
    }

    return 0;
}




