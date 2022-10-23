


#ifndef PROJECT_CREATURE_H
#define PROJECT_CREATURE_H
#include <iostream>
using  namespace  std;
#define EMPTY '#'

class Creature {
private:
    char name;
    bool survival;
    bool hunger;
public:
    bool isSurvival() const;

    void setSurvival(bool survival);

    Creature(char name);
    Creature();
    char getName() const;

    void setName(char name);
    void eat();

    bool isHunger() const;

    void setHunger(bool hunger);
};


#endif //PROJECT_CREATURE_H
