#include "test/func.cpp"
using namespace std;

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


