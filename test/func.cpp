#include "func.h"

void DataPlayer::readNameFromUser(){
    std::cout << "\n\nEnter your name : ";
    getline(cin, name);
}

auto DataPlayer::getName(){
    return name;
}

void DataPlayer::readBalanceFromUser(){
    do{
        cout << "\n\nEnter deposit amount to play game: $";
        cin >> bal;
        if (not checkBal()){
            cout << "Please! Specify the correct balance!\n"
                 <<"\nRe-enter data\n ";
        }
    }while(not checkBal());
}

bool DataPlayer::checkBal()
{
    return not(bal<50);
}

auto DataPlayer::getBalance(){
    return bal;
}

int DataPlayer::chooseLevel(){
    do{
        cin >> level;
        if (not checkLevel())
        {
            cout << "You don't have enough money for the current level of the game!\n"
                 <<"\nRe-enter data\n ";}
    }while(not checkLevel());
    return level;
}

bool DataPlayer::checkLevel()
{
    return not((level==2 && bal<150) || (level==3 && bal<500));
}

void DataPlayer::openBet(){
    do
    {
        cout << "\n" << name <<", enter money to bet : $";
        cin >> bet;
        if(not checkBet())
        {
            cout << "Your betting amount is more than your current balance\n"
                 <<"\nRe-enter data\n ";
        }
    }while(not checkBet());
}

bool DataPlayer::checkBet()
{
    return not(bet > bal);
}

void DataPlayer::Level1(){
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
    if(not checkBal())
    {
        GameOver();
    }
    else{
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> Choice;
        if (Choice=='Y' || Choice=='y'){
            cout << "Let's play another one!!!\n";
        }
        else{
            GameOver();
        }
    }
}

void DataPlayer::Level2(){
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
    if(not checkBal())
    {

        GameOver();
    }
    else{
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> Choice;
        if (Choice=='Y' || Choice=='y'){
            cout << "Let's play another one!!!\n";
        }
        else{
            GameOver();
        }
    }
}

void DataPlayer::Level3(){
    do
    {
        cout << "Guess your numbers to bet between 0 to 9 :";
        cin >> useNumber1 >> useNumber2 >> useNumber3 >> useNumber4 >> useNumber5;
        if((useNumber1 < 0 || useNumber1 > 9) || (useNumber2 < 0 || useNumber2 > 9) || (useNumber3 < 0 || useNumber3 > 9) || (useNumber4 < 0 || useNumber4 > 9) || (useNumber5 < 0 || useNumber5 > 9))
            cout << "Please check the number! should be between 0 to 9\n"
                 <<"\nRe-enter data\n ";
    }
    while((useNumber1 < 0 || useNumber1 > 9) || (useNumber2 < 0 || useNumber2 > 9) || (useNumber3 < 0 || useNumber3 > 9) || (useNumber4 < 0 || useNumber4 > 9) || (useNumber5 < 0 || useNumber5 > 9));

    if (useNumber1 == 5 && useNumber2 == 1 && useNumber3 == 1 && useNumber4 == 0 && useNumber5 == 3)
    {
        cout << "\n\nWow! You unlock easter egg! You get super price! "<< bet * 100;
        bal = bal + bet * 100;
    }
    else if (number1 == useNumber1 && number2 == useNumber2 && number3 == useNumber3 && number4 == useNumber4 && number5 == useNumber5){
        cout << "\n\nGood Luck!! You won $" << bet * 10;
        bal = bal + bet * 10;
    }
    else{
        cout << "Bad Luck this time !! You lost $ "<< bet*2 <<"\n";
        bal = bal - bet*2;
    }
    cout << "\nThe winning number was: " << number1 << number2 << number3<< number4 << number5  <<"\n";
    cout << "\n"<<name<<", You have $ " << bal << "\n";
    if(not checkBal())
    {

        GameOver();
    }
    else{
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> Choice;
        if (Choice=='Y' || Choice=='y'){
            cout << "Let's play another one!!!\n";
        }
        else{
            GameOver();
        }
    }
}

void DataPlayer::GameOver()
{
    inGame = false;
    End();
    Gratitude(bal);
}

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

auto rules3(){
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any combination of five numbers between 0 to 9. You can choose the same ones\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
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

void Gratitude(int Balance){
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

