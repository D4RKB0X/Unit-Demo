#include <iostream>
#include <string>
#include <limits>
#include <ctime>

template <typename T>
T getInput(const std::string& prompt) {
    T value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid Input! Try Again!\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

void takeDamage(int damage, int strikes, int &currentHP) {
    int totalDamage = damage * strikes;
    int chance = rand() % 10 + 1;

    if (chance == 1) {
        totalDamage *= 2;
        std::cout << "\nCritical Hit!";
    }

    currentHP -= totalDamage;
    if (currentHP < 0) currentHP = 0;

    std::cout << "\nEnemy dealt " << totalDamage << " damage!";
    std::cout << "\nYour Current Health is " << currentHP;

    if (currentHP >= 250) {
        std::cout << "\nContinue Fighting!\n";
    } else if (currentHP >= 100) {
        std::cout << "\nRetreat and Regroup!\n";
    } else if (currentHP > 0) {
        std::cout << "\nRun! Dammit, Run!\n";
    } else {
        std::cout << "\nYou're Dead!\n";
    }
}

void heal(int &currentHP, int potion, int maxHP) {
    int oldHP = currentHP;
    currentHP += potion;

    if (currentHP >= maxHP) {
        int shield = currentHP - maxHP;
        currentHP = maxHP;

        if (shield > 0) {
            std::cout << "\nRemaining " << shield << " will be used as shield!";
        } else {
            std::cout << "\nFully Healed!";
        }
    } else if (currentHP > oldHP) {
        std::cout << "\nPartially Healed!";
    } else {
        std::cout << "\nStill Weak! Buy a Health Potion now!";
    }

    std::cout << "\nYour Current Health is " << currentHP << "\n";
}

int main() {
    srand(time(NULL));

    const int maxHP = 500;
    int currentHP = maxHP;

    std::cout << "You are a Knight and you have " << maxHP << " Health.\n";

    int damage = getInput<int>("Enter enemy damage: ");
    int strikes = getInput<int>("Enter enemy strikes: ");

    takeDamage(damage, strikes, currentHP);

    int potion = getInput<int>("\nEnter the potion HP recovered: ");
    heal(currentHP, potion, maxHP);

    return 0;
}
