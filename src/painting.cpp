//
// Created by AZ on 8/25/2021.
//

#include "painting.h"

painting::painting(){
    price = 0;
    x = 0;
    y = 0;
    ID = 0;
    locX = 0;
    locY = 0;
}

painting::painting(int p, int xin, int yin, int IDin){
    price = p;
    x = xin;
    y = yin;
    ID = IDin;
    locX = 0;
    locY = 0;
}

painting::painting(const painting &p1){
    price = p1.price;
    x = p1.x;
    y = p1.y;
    ID = p1.ID;
    locX = p1.locX;
    locY = p1.locY;
}

int painting::getPrice(){
    return price;
}
void painting::setPrice(int in){
    price = in;
}
int painting::getX(){
    return x;
}
void painting::setX(int in){
    x = in;
}
int painting::getY(){
    return y;
}
void painting::setY(int in){
    y = in;
}
int painting::getID(){
    return ID;
}
void painting::setID(int in){
    ID = in;
}
int painting::getLocX(){
    return locX;
}
void painting::setLocX(int in){
    locX = in;
}
int painting::getLocY(){
    return locY;
}
void painting::setLocY(int in){
    locY = in;
}
void painting::setLoc(int xin, int yin){
    locX = xin;
    locY = yin;
}

