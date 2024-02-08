#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <unistd.h>

class Character {
private:
    std::string name;
    int healthPoints;
    int baseDamage;

public:
    Character(std::string n, int hp, int damage) : name(n), healthPoints(hp), baseDamage(damage) {}

    std::string getName() const { return name; }

    int getHealth() const { return healthPoints; }

    int attack(int choice) {
        int damage = (choice * 2);
        int critChance = (choice == 10) ? rand() % 10 : 0;

        if (critChance == 0) {
            return damage;
        } else {
            return 0;
        }
    }

    void takeDamage(int damage) {
        healthPoints -= damage;
    }

    bool isAlive() {
        return healthPoints > 0;
    }
};

int main() {
    srand(time(0));
    std::cout << "—---------------------------------------------------------------" << std::endl;
    std::cout << "У нас есть три кита игры:" << std::endl;
    std::cout << "1) Даже колдун не умеет читать, вводите цифры!" << std::endl;
    std::cout << "2) Валькирия умеет считать только до 10, введит меньше число." << std::endl;
    std::cout << "3) Отрицательные числа еще не изобрели." << std::endl;
    std::cout << "—---------------------------------------------------------------" << std::endl;
    std::cout << "Подождите игра грузиться [##--------] 20%" << std::endl;
    sleep(2); system("clear");
    
    std::cout << "—---------------------------------------------------------------" << std::endl;
    std::cout << "У нас есть три кита игры:" << std::endl;
    std::cout << "1) Даже колдун не умеет читать, вводите цифры!" << std::endl;
    std::cout << "2) Валькирия умеет считать только до 10, введит меньше число." << std::endl;
    std::cout << "3) Отрицательные числа еще не изобрели." << std::endl;
    std::cout << "—---------------------------------------------------------------" << std::endl;
    std::cout << "Подождите игра грузиться [####------] 40%" << std::endl;
    sleep(1); system("clear");
    
    std::cout << "—---------------------------------------------------------------" << std::endl;
    std::cout << "У нас есть три кита игры:" << std::endl;
    std::cout << "1) Даже колдун не умеет читать, вводите цифры!" << std::endl;
    std::cout << "2) Валькирия умеет считать только до 10, введит меньше число." << std::endl;
    std::cout << "3) Отрицательные числа еще не изобрели." << std::endl;
    std::cout << "—---------------------------------------------------------------" << std::endl;
    std::cout << "Подождите игра грузиться [#######---] 70% " << std::endl;
    sleep(2); system("clear");
    
     std::cout << "—---------------------------------------------------------------" << std::endl;
    std::cout << "У нас есть три кита игры:" << std::endl;
    std::cout << "1) Даже колдун не умеет читать, вводите цифры!" << std::endl;
    std::cout << "2) Валькирия умеет считать только до 10, введит меньше число." << std::endl;
    std::cout << "3) Отрицательные числа еще не изобрели." << std::endl;
    std::cout << "—---------------------------------------------------------------" << std::endl;
    std::cout << "Подождите игра грузиться [##########] 99% " << std::endl;
    sleep(4); system("clear");



    Character player1("Валькирия", 120, 0);
    Character player2("Колдун", 100, 0);
    int round = 1;

    while (player1.isAlive() && player2.isAlive()) {
        system("clear");
        std::cout << "—---------------------------------------------------------------" << std::endl;
        std::cout << " (｡•̀ᴗ-)✧                         (シ. .)シ                      " << std::endl;
        std::cout << player1.getName() << " - " << player1.getHealth() << " хп.     ||     " << player2.getName() << " - " << player2.getHealth() << " хп." << std::endl;
        std::cout << "—---------------------------------------------------------------" << std::endl;

        int choice;
        std::cout << "Ход " << player1.getName() << " игрока 1 (｡•̀ᴗ-)✧ : ";
        std::cin >> choice;

        int damage = player1.attack(choice);
        player2.takeDamage(damage);

        if (!player2.isAlive()) break;

        std::cout << "Ход " << player2.getName() << " игрока 2 (シ. .)シ: ";
        std::cin >> choice;

        damage = player2.attack(choice);
        player1.takeDamage(damage);

        round++;
    }

    system("clear");
    std::cout << "—---------------------------------------------------------------" << std::endl;
    if (player1.isAlive()) {
        std::cout << "Победил 1 игрок: " << player1.getName() << ": " << "    (｡•̀ᴗ-)✧" << std::endl;
    } else {
        std::cout << "Победил 2 игрок: " << player2.getName() << ": " << "   (シ. .)シ" << std::endl;
    }
    std::cout << "Кол. раундов: " << round << ". Кол. жизней в конце: " << player1.getHealth() << std::endl;
    std::cout << "—---------------------------------------------------------------" << std::endl;

    return 0;
}
