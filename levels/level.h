#pragma once
#include <SFML/Graphics.hpp>
#include "sun.h"
#include"menu.h"
#include"plantfactory.h"
#include"car.h"
#include"grid.h"
#include"zombiefactory.h"
class level
{
    int sunscollected;
    int l;
    bool levelwon;/////
public:
    level();
    grid gri;
    plantfactory pf;
    sun s;
    car c[5];
    zombiefactory zf;
    level(RenderWindow& window, int ll);
    virtual void startgame(RenderWindow& window, Event event) = 0;
    int getlevel();
    void setlevel(int ll);
    void zombie_bullet_collision(RenderWindow& w);
    void plantzombie(RenderWindow& window);
    void  carzombie(RenderWindow& window);
    void setsuns();
    int getsuns();
    void setindsuns(int y);
    int changelevel();/////////
    bool getwon();
    Font font;
    Text textt;
    int returned;
    int indsun;
    void partnercollisons(RenderWindow& w, int i,int which, int cherryGridX, int cherryGridY,int pi,RenderWindow& window);
};

