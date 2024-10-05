#include <iostream>

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
            
            if (robotTwo.hp <= 0) {
                battleOver = true;
            }

            while (!battleOver) {
                


            }

        
        }
};

/*** Other functions and procedures ***/
double randomNumber() { // rng for attack and defense value, ranging from -0.3 to 0.3
    return (static_cast<double>(std::rand()) / RAND_MAX * 0.6) - 0.3; 
}

double damageBattle(int ATK, int DEF) { // returns the damage dealt by the attacking robot to the defending robot
    double damageDealt = (randomNumber() * ATK) + ATK;
    double damageTaken = (randomNumber() * DEF + DEF) - damageDealt;
    return damageTaken;
}

void damageHP (double damage, double HP) { // reduces defending robot's HP
    HP -= damage;
}

void menu() {
    std::cout << "Welcome to Battle of Robots!\n";
    std::cout << "\n";

    std::cout << "Select your action:\n";

    std::cout << "1. Add robot\n";
    std::cout << "2. Start battle!\n";
}

/*** Main program ***/
int main() {



    menu();



    return 0;
}
