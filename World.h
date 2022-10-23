


#ifndef PROJECT_WORLD_H
#define PROJECT_WORLD_H
#include <iostream>
#include "Creature.h"

#include "Paramecium.h"
#define MAXN 100
using namespace std;
class World {
    int width,height;
    Creature map[MAXN][MAXN];
public:
    World(int width, int height);

    void actions();
    void clear();
    void printInfo();
    void CeateRandCreature(Creature creature);
};


#endif //PROJECT_WORLD_H
