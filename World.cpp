#include "World.h"

World::World(int width, int height) : width(width), height(height) {
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            map[i][j]=Creature(EMPTY);
        }

    }
}

void World::printInfo() {
    cout<<"------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
             cout<<map[i][j].getName();

            cout<<"  ";
        }
        cout<<endl;

    }
    cout<<"------------------------------------------------------------------------------------"<<endl;
}

void World::clear() {
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(!map[i][j].isSurvival()){
                map[i][j]=Creature();
            }
        }

    }
}

void World::CeateRandCreature(Creature creature) {

    while (true)
    {
        int randH=rand()%height;
        int randW=rand()%width;
        if(!map[randH][randW].isSurvival() || map[randH][randW].getName()==EMPTY)
        {
            map[randH][randW]=creature;
            break;
        }

    }
}

void World::actions() {
    clear();
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(map[i][j].getName()!=EMPTY)//death
            {
                int random=rand()%100;

                if(random<10)
                {
                    map[i][j] = Creature();
                }
                else if(random<30)//move
                {
                    if(map[i][j].isHunger())return;
                    int move[][2]={{1,0},{-1,0},{0,1},{0,-1}};

                    int dir=rand()%4;
                    int newI=i+move[dir][0];
                    int newJ=j+move[dir][1];
                    if(newI>=0&&newI<height && newJ>=0&&newJ<width && map[newI][newJ].getName()==EMPTY)
                    {

                        map[i][j].setHunger(true);
                        map[newI][newJ]=map[i][j];
                        map[i][j].setSurvival(false);
                        continue;
                    }
                }
                else if(random<70)
                {
                    map[i][j].eat();
                }
                else//copy
                {
                    int move[][2]={{1,0},{-1,0},{0,1},{0,-1}};

                    int dir=rand()%4;
                    int newI=i+move[dir][0];
                    int newJ=j+move[dir][1];
                    if(newI>=0&&newI<height && newJ>=0&&newJ<width && map[newI][newJ].getName()==EMPTY)
                    {

                        if(map[i][j].getName()=='C')
                        {
                            map[newI][newJ]=Creature('C');
                        }
                        else{

                            map[newI][newJ]=Paramecium('P');
                        }

                        continue;
                    }
                }
            }
            else
            {
                //create
                bool create =rand()%100>90;
                if(create)
                {
                    if(rand()%10>5)
                    {

                        map[i][j]=Creature('C');
                    }
                    else{

                        map[i][j]=Paramecium('P');
                    }
                }

            }
        }

    }
}
