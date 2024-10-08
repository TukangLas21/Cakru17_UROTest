#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

/* Other functions and procedures */
double randomNumber() { // rng for attack and defense value, ranging from -0.3 to 0.3
    return (static_cast<double>(std::rand()) / RAND_MAX * 0.6) - 0.3; 
}

double damageBattle(int ATK, int DEF) { // returns the damage dealt by the attacking robot to the defending robot
    double damageDealt = (randomNumber() * ATK) + ATK;
    double damageTaken = damageDealt - (damageDealt * (DEF / 100));
    return damageTaken;
}

// double damageHP(double damage, double HP) { // reduces defending robot's HP
//     return (HP -= damage);
// }

class Robot {
    public:
        string name;
        int atk;
        int def;
        double hp;

        // Konstruktor
        Robot(string RobotName, int RobotATK, int RobotDEF, double RobotHP) {
            name = RobotName;
            atk = RobotATK;
            def = RobotDEF;
            hp = RobotHP;
        }

        void display() const {
            std::cout << name <<  "(ATK: "  << atk << " DEF: " << def << " HP: " << hp << ")" << endl;
        }
};

class Battle {
    public:
        void start_fight(Robot RoboOne, Robot RoboTwo) {
            double HP1 = RoboOne.hp;
            double HP2 = RoboTwo.hp;

            while (HP1 > 0 || HP2 > 0) {
                HP2 -= damageBattle(RoboOne.atk, RoboTwo.def);
                cout << RoboOne.name << " attacks " << RoboTwo.name << " for " << damageBattle(RoboOne.atk, RoboTwo.def) << " damage!" << endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
                HP1 -= damageBattle(RoboTwo.atk, RoboOne.def);
                cout << RoboTwo.name << " attacks " << RoboOne.name << " for " << damageBattle(RoboTwo.atk, RoboOne.def) << " damage!" << endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
            }

            if (HP2 < 0) {
                cout << RoboTwo.name << " is defeated!" << endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
                cout << RoboOne.name << " wins!" << endl;
            }
            else if (HP1 < 0) {
                cout << RoboOne.name << " is defeated!" << endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
                cout << RoboTwo.name << " wins!" << endl;
            }
        }
};

class Game {
    public:
        void add_robot(vector<Robot> &robot_vec) {
            cout << "Please fill in the new robot's data!" << endl;

            string RoboName;
            cout << "Insert the new robot's name: ";
            cin >> RoboName;
            cout << endl;

            int RoboAttack;
            cout << "Insert " << RoboName << "\'s attack power: ";
            cin >> RoboAttack;
            cout << endl;

            int RoboDef;
            cout << "Insert " << RoboName << "\'s defense power: ";
            cin >> RoboDef;
            cout << endl;

            double RoboHP;
            cout << "Insert " << RoboName << "\'s HP: ";
            cin >> RoboHP;
            cout << endl;

            robot_vec.push_back(Robot(RoboName, RoboAttack, RoboDef, RoboHP));

            cout << "Robot has been successfully added!" << endl;
        }

        void start_game(vector<Robot> &robot_vec) {
            cout << "Choose robots for the battle: " << endl;
            for (size_t i = 0; i < robot_vec.size(); i++) {
                cout << (i+1) << ". ";
                robot_vec[i].display();
            }
            
            cout << "Choose the first Robot : ";
            int RoboOne;
            cin >> RoboOne;

            cout << "Choose the second Robot : ";
            int RoboTwo;
            cin >> RoboTwo;

            Robot roboOne = robot_vec[RoboOne-1];
            Robot roboTwo = robot_vec[RoboTwo-1];

            Battle battle;
            battle.start_fight(roboOne, roboTwo);
        }
};

vector<Robot> initialize_robot_vector() {
    vector<Robot> robot_vec = {
        Robot("Mip", 500, 30, 700),
        Robot("Mup", 300, 40, 800),
        Robot("Mop", 600, 20, 500)
    };

    return robot_vec;
}

int main() {
    vector<Robot> RoboVector = initialize_robot_vector();

    Game NewGame;

    while (true) {
        cout << "Welcome to Battle of Robots!\n";
        cout << "\n";

        cout << "Select your action:\n";

        cout << "1. Add robot\n";
        cout << "2. Start battle!\n";
        cout << "3. Quit\n";

        cout << "Choose your action: ";
        int action;
        do
        {
            cin >> action;
        } while (action < 1 && action > 3);

        if (action == 1) {
            NewGame.add_robot(RoboVector);
        }
        else if (action == 2) {
            NewGame.start_game(RoboVector);
        }
        else {
            break;
        }
    }

    return 0;
}