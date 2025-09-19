#include <iostream>
#include <string>
#include <limits>
#include <ctime>

template <typename T> 
T getInput(const std::string& prompt) {
    T value;
    while(true) {
        std::cout << prompt;
        std::cin >> value;
        
        if(std::cin.fail()) {
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
           std::cout << "Invalid Input! Try Again!\n";
           continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

void takeDamage(int &hp, int damage, int strikes) {
    
    int totalDamage = damage * strikes;
    int roll = rand() % 10 + 1;

    // Chance to Critical Strike
    if(roll == 1) {
        totalDamage *= 2;
        std::cout << "\nCritical Hit!";
        std::cout << "\nYour Current Health is " << hp;
    }
    
    hp -= totalDamage;
    std::cout << "\nEnemy Dealt " << totalDamage << " Damage!";

    if(hp >= 250) {
        std::cout << "\nYour Current Health is " << hp;
        std::cout << "\nContinue Fighting!";
    }
    else if(hp >= 100) {
        std::cout << "\nYour Current Health is " << hp;
        std::cout << "\nRetreat and Regroup!";
    }
    else if(hp == 1) {
        std::cout << "\nRun! Dammit, Run!";
    }
    else {
        std::cout << "\nYou're Dead!";
    }
}

int main() {
    
    srand(time(NULL));
    
    int hp = getInput<int>("Enter you current HP: ");
    int damage = getInput<int>("Enter the damage you've recieved: ");
    int strikes = getInput<int>("Enter how many strikes the enemy dealt: ");
    
    takeDamage(hp, damage, strikes);
    
    return 0;
}
