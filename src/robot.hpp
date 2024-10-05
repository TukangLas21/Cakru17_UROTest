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

#define name robotName
#define attack robotATK
#define defense robotDEF
#define health robotHP

#endif