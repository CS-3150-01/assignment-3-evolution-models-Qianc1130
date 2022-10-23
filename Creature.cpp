


#include "Creature.h"



char Creature::getName() const {
    return name;
}

void Creature::setName(char name) {
    Creature::name = name;
}

Creature::Creature(char name) : name(name) {
    survival= true;
}

Creature::Creature() {
    name=EMPTY;
    survival=true;
}


bool Creature::isSurvival() const {
    return survival;
}

void Creature::setSurvival(bool survival) {
    Creature::survival = survival;
}

void Creature::eat() {
    cout<<"I`m Eating!"<<endl;
    hunger= false;
}

bool Creature::isHunger() const {
    return hunger;
}

void Creature::setHunger(bool hunger) {
    Creature::hunger = hunger;
}

