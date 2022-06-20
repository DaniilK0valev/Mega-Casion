#include <iostream>
#include <string> // Нужно для написания строк
#include <cstdlib> // Нужно для использования рандома чисел
#include <ctime>
using namespace std;

int game(int Balance, string PlayerName, int LevelChoice);
void End();
int Gratitude(int Balance);
int Level(int Balance, string PlayerName);
int Hint();

void drawLine(int n, char symbol);
void rules3();
void rules2();
void rules1();
void rules();
void printProgress ();

int main() {
    string PlayerName;
    int Balance;

    drawLine(50, '_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
    drawLine(50, '_');

    cout << "\n\nEnter your name : ";
    getline(cin, PlayerName);

    system("cls");
    rules();

    cout << "\n\nEnter deposit amount to play game: $";
    cin >> Balance;
    if (Balance<50){
        while(Balance<50){
        cout << "Please! Specify the correct balance!\n"
             <<"\nRe-enter data\n ";
            cout << "\n\nEnter deposit amount to play game: $";
            cin >> Balance;
        }
    }

    Level(Balance, PlayerName);
    return 0;
}
int Level(int Balance, string PlayerName){
    int LevelChoice;
    cout << "\n\nYour current balance is $ " << Balance << "\n";
    cout << "\n" << PlayerName << ", choose level (1,2,3):";
    cin >> LevelChoice;
    if ((LevelChoice==2 && Balance<150) || (LevelChoice==3 && Balance<500) || LevelChoice<1 || LevelChoice>3){
        while((LevelChoice==2 && Balance<150) || (LevelChoice==3 && Balance<500)){
        cout << "You don't have enough money for the current level of the game or you entered the level incorrectly\n"
             <<"\nRe-enter data\n ";
            Level(Balance, PlayerName);
        }
    }
    game(Balance, PlayerName, LevelChoice);
}
int game(int Balance, string PlayerName, int LevelChoice) {
    int UseBal;
    char Choice;

    srand(time(0));
    int YourNum11;
    int Num11;
    if (LevelChoice == 1){
        system("cls");
        rules1();
        do
        {
            cout << "\n" << PlayerName <<", enter money to bet : $";
            cin >> UseBal;
            if(UseBal > Balance)
                cout << "Your betting amount is more than your current balance\n"
                     <<"\nRe-enter data\n ";
        }while(UseBal > Balance);

        cout << "Guess your number to bet between 0 to 9 :";
        cin >> YourNum11;
        if(YourNum11 < 0 || YourNum11 > 9){
            while(YourNum11 < 0 || YourNum11 > 9){
                cout << "Please check the number! should be between 0 to 9\n"
                <<"\nRe-enter data\n ";
                cout << "Guess your number to bet between 0 to 9 :";
                cin >> YourNum11;
            }
        }
        Num11 = rand()%10;
        if(Num11 == YourNum11)
        {
            cout << "\n\nGood Luck!! You won Rs." << UseBal * 2;
            Balance = Balance + UseBal * 2;
        }
        else
        {
            cout << "Bad Luck this time !! You lost $ "<< UseBal <<"\n";
            Balance = Balance - UseBal;
        }
        cout << "\nThe winning number was: " << Num11 <<"\n";
        cout << "\n"<<PlayerName<<", You have $ " << Balance << "\n";

    }
    if (LevelChoice==2){
        int Num21, Num22, Num23;
        int YourNum21,YourNum22,YourNum23;
        system("cls");
        rules2();
        do
        {
            cout << "\n" << PlayerName <<", enter money to bet : $";
            cin >> UseBal;
            if(UseBal > Balance)
                cout << "Your betting amount is more than your current balance\n"
                     <<"\nRe-enter data\n ";
        }while(UseBal > Balance);
        do
        {
            cout << "Guess your numbers to bet between 0 to 9 :";
            cin >> YourNum21 >> YourNum22 >> YourNum23;
            if((YourNum21 < 0 || YourNum21 > 9) || (YourNum22 < 0 || YourNum22 > 9) || (YourNum23 < 0 || YourNum23 > 9))
                cout << "Please check the number! should be between 0 to 9\n"
                     <<"\nRe-enter data\n ";
        }
        while((YourNum21 < 0 || YourNum21 > 9) || (YourNum22 < 0 || YourNum22 > 9) || (YourNum23 < 0 || YourNum23 > 9));
        Num21 = rand()%10; Num22 = rand()%10; Num23 = rand()%10;
        if (YourNum21==5 && YourNum22 == 1 && YourNum23==3){
            cout << "\n\nWow! You unlock easter egg! You get super price! "<< UseBal * 100;
            Balance = Balance + UseBal * 100;
        }
        else if (Num21 == YourNum21 && Num22 == YourNum22 && Num23 == YourNum23){
            cout << "\n\nGood Luck!! You won Rs." << UseBal * 5;
            Balance = Balance + UseBal * 5;
        }
        else if (Num21 ==7 && Num22 == 7 && Num23==7){
            cout << "\n\nUltra Luck!! You won Rs." << UseBal*7;
            Balance = Balance + UseBal * 7;
        }
        else if (Num21 == Num22 && Num22 == Num23 && Num23 == Num21){
            cout << "\n\nMega Luck! You won Rs." << 100*Num21;
            Balance = Balance + 100*Num21;
        }
        else{
            cout << "Bad Luck this time !! You lost $ "<< UseBal*2 <<"\n";
            Balance = Balance - UseBal*2;
        }
        cout << "\nThe winning number was: " << Num21 << Num22 << Num23 <<"\n";
        cout << "\n"<<PlayerName<<", You have $ " << Balance << "\n";

    }
    if(Balance == 0)
    {
        Gratitude(Balance);
        End();
    }
    else{
        cout << "\n\n-->Do you want to play again (y/n)? ";

        cin >> Choice;
        if (Choice=='Y' || Choice=='y'){
            Level(Balance, PlayerName);
        }
        else{
            End();
            Gratitude(Balance);
        }
    }
    return 0;
}

int Hint(){
    
}
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


void rules(){
    system("cls");
    cout << "\n\n";
    drawLine(70,'-');
    cout << "\t\tWELCOME IN OUR CASINO!\n";
    drawLine(70,'-');
    cout << "\tYou can choose 3 difficulty levels. The higher the level, more the winnings and more loss!\n";
    cout << "\tEach level requires more balance\n";
    cout << "\t1 level - Guess one number. Minimum: $50\n";
    cout << "\t2 level - Guess three numbers. Minimum: $150\n";
    cout << "\t3 level - Guess five numbers. Minimum: $500\n";
}

void rules1()
{
    system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 0 to 9\n";
    cout << "\t2. If you win you will get 2 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}

void rules2(){
    system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any combination of three numbers between 0 to 9. You can choose the same ones\n";
    cout << "\t2. If you win you will get 5 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}

void rules3(){

}
