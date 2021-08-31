//
// Created by AZ on 8/25/2021.
//

#ifndef INC_21F_PA01_ARTHUR_ZHANG_PAINTING_H
#define INC_21F_PA01_ARTHUR_ZHANG_PAINTING_H


class painting {
private:
    int price, x, y, ID;
    int locX, locY;

public:

    painting();
    painting(int p, int xin, int yin, int IDin);

//    getters and setters
    int getPrice();
    void setPrice(int in);
    int getX();
    void setX(int in);
    int getY();
    void setY(int in);
    int getID();
    void setID(int in);
    int getLocX();
    void setLocX(int in);
    int getLocY();
    void setLocY(int in);
    void setLoc(int xin, int yin);

};


#endif //INC_21F_PA01_ARTHUR_ZHANG_PAINTING_H
