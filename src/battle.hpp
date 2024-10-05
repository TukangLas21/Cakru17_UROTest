#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include "robot.hpp"

float randomNumber();

class Battle {
    private:
        double damageDealt;
        double damageTaken;

    public:
        void start_fight(Robot robotOne, Robot robotTwo);

};

#endif 