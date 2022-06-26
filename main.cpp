#include "test/func.cpp"
using namespace std;

int main() {
    srand(time(NULL));
    ///Открываем доступ к данным для игрока///
    DataPlayer Player;
    ///Печатаются границы///
    drawLine(50, '_');
    ///Ввыводит текст с названием игры и дальше мы вводим необходимую информацию для начала игры///
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
        drawLine(50, '_');
        Player.readNameFromUser();
        Player.name = Player.getName();
        Player.readBalanceFromUser();
        Player.bal = Player.getBalance();
    ///Пока игра не объявлена завершенной, она будет работать и мы сможем играть, выбирая уровень///
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


