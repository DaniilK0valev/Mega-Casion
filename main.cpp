#include "test/func.cpp"
using namespace std;

int main() {
    srand(time(NULL));

    DataPlayer Player;

    string PlayerName;

    drawLine(50, '_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
        drawLine(50, '_');
        Player.readNameFromUser();
        Player.name = Player.getName();
        Player.readBalanceFromUser();
        Player.bal = Player.getBalance();
    while (Player.inGame) {
        rules();

        Player.level = Player.chooseLevel();

        Player.openBet();
        if (Player.level == 1) {
            rules1();
            Player.Level1();
        }
        if (Player.level == 2) {
            rules2();
            Player.Level2();
        }
        if (Player.level == 3) {
            rules3();
            Player.Level3();
        }
    }
    return 0;
}


