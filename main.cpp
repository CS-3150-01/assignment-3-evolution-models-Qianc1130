#include <iostream>
#include "World.h"
#include "Paramecium.h"

World world(20,20);
void init(){
    for(int i=0;i<5;i++)
    {
        Creature creature('C');
        world.CeateRandCreature(creature);
    }

    for(int i=0;i<5;i++)
    {
        Paramecium paramecium('P');
        world.CeateRandCreature(paramecium);
    }
}
// test
void testCase()
{
    cout<<"---------------------test case---------------------"<<endl;
    Creature creature('C');
    cout<<"creature.getName()=='C': "<<(creature.getName()=='C')<<endl;

    cout<<"creature.isHunger()== false: "<<(creature.isHunger()== false)<<endl;
    cout<<"creature.isSurvival()== true: "<<(creature.isSurvival()== true)<<endl;
    creature.setHunger(true);
    cout<<"creature.isHunger()== true: "<<(creature.isHunger()== true)<<endl;

    Paramecium paramecium('P');
    cout<<"paramecium.getName()=='P': "<<(paramecium.getName()=='P')<<endl;

    cout<<"paramecium.isHunger()== false: "<<(paramecium.isHunger()== true)<<endl;
    cout<<"paramecium.isSurvival()== true: "<<(paramecium.isSurvival()== true)<<endl;
    paramecium.setHunger(true);
    cout<<"paramecium.isHunger()== true: "<<(paramecium.isHunger()== true)<<endl;


    cout<<"---------------------test case---------------------"<<endl;
}
int main() {

//    world.printInfo();
//    world.clear();

    //init
    init();
    for(int round=1;round<5;round++)
    {
        cout<<"round: "<<round<<endl;
        world.printInfo();
        world.actions();
    }
    testCase();

    return 0;
}
