#include "battle.hpp"
#include <iostream> 

float randomNumber() {
    std::srand((unsigned) std::time(NULL));
    int rng = std::rand() % 30; 
    
    return rng;
}

void Battle::start_fight(Robot robotOne, Robot robotTwo) {

        std::cout << "Battle start!\n";

        damageDealt = 0;
        damageTaken = 0;



        std::cout << robotOne.name << " attacks " << robotTwo.name << " for " << damageTaken;

}
