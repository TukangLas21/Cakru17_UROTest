#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>

class Robot {
    public:
        int robotID;
        std::string robotName;
        int robotATK;
        int robotDEF;
        int robotHP;
};

/* Simplify terms */
#define name robotName
#define atk robotATK
#define def robotDEF
#define hp robotHP

#endif