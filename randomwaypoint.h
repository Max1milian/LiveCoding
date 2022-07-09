#ifndef RANDOMWAYPOINT_H
#define RANDOMWAYPOINT_H
#include <cstdlib>
#include <iostream>
class RandomWaypoint{
public:
    void proceed(){
        xpos += xspeed;
        ypos += yspeed;
        if(xpos < xpos_stop || ypos < ypos_stop){
            xpos = xpos_stop;
            ypos = ypos_stop;
            newMovement();
        }

    }
    void newMovement(){
        srand(400);
        xpos_stop = rand() % 400 + 1;
        ypos_stop = rand() % 400 + 1;
        steps = rand() % 1000  + 10;
        xspeed = steps;
        yspeed = steps;
    }
    float getXpos(){
        return xpos;
    }
    float getYpos(){
        return ypos;
    }
    RandomWaypoint(float xpos, float ypos): xpos(xpos), ypos(ypos){}
private:
    float xpos = 0;
    float ypos = 0;
    float xpos_stop = 0;
    float ypos_stop = 0;
    float xspeed = 0;
    float yspeed = 0;
    float steps = 0;
};
#endif // RANDOMWAYPOINT_H
