#include <iostream>
#include "../src/robot.hpp"
#include "../src/battle.hpp"

/*** Robot Class Implementation ***/
class Robot {
    public:
        int robotID;
        std::string robotName;
        int robotATK;
        int robotDEF;
        double robotHP;
};

/* Simplify terms */
#define name robotName
#define atk robotATK
#define def robotDEF
#define hp robotHP

/*** Battle Class Implementation ***/

class Battle {
    private:
        bool battleOver = false; // boolean variable for the battle loop

    public:
        void start_fight(Robot robotOne, Robot robotTwo) {

            std::srand(static_cast<unsigned>(time(0)));

            std::cout << "Battle start!\n";

            std::cout << robotOne.name << " attacks " << robotTwo.name << " for " << damageBattle(robotOne.atk, robotTwo.def);

            damageHP(damageBattle(robotOne.atk, robotTwo.def), robotTwo.hp);
            
            if (robotTwo.hp <= 0) battleOver = true;

            while (!battleOver) {
                


            }

        
        }
};

/*** Game Class Implementation ***/

class Game {
    public:
        void add_robot() { // Method to add a new robot

        }

        void start_game() {
            
        }
};

/*** Other functions and procedures ***/
bool validInput(int input) {
    return input == input;
}

double randomNumber() { // rng for attack and defense value, ranging from -0.3 to 0.3
    return (static_cast<double>(std::rand()) / RAND_MAX * 0.6) - 0.3; 
}

double damageBattle(int ATK, int DEF) { // returns the damage dealt by the attacking robot to the defending robot
    double damageDealt = (randomNumber() * ATK) + ATK;
    double damageTaken = damageDealt - (damageDealt * (DEF / 100));
    return damageTaken;
}

void damageHP(double damage, double HP) { // reduces defending robot's HP
    HP -= damage;
}

void initRobots() {
    Robot Mip;
    Robot Mup;
    Robot Mop;

    // Mip attributes
    Mip.name = "Mip";
    Mip.atk = 500;
    Mip.def = 20;
    Mip.hp = 700;

    // Mup attributes
    Mup.name = "Mup";
    Mup.atk = 300;
    Mup.def = 40;
    Mup.hp = 800;

    // Mop attributes
    Mop.name = "Mop";
    Mop.atk = 600;
    Mop.def = 30;
    Mop.hp = 500;
}

/*** Main program ***/
int main() {

    Game NewGame;
    initRobots();

    std::cout << "Welcome to Battle of Robots!\n";
    std::cout << "\n";

    std::cout << "Select your action:\n";

    std::cout << "1. Add robot\n";
    std::cout << "2. Start battle!\n";

    int action;
    do
    {
        std::cin >> action;
    } while (!validInput(action) && action >= 1 && action <= 2);
    
    if (action == 1) {
        NewGame.add_robot();
    }
    else {
        NewGame.start_game();
    }



    return 0;
}
