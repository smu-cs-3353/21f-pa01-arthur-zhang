//
// Created by AZ on 8/30/2021.
//

#ifndef INC_21F_PA01_ARTHUR_ZHANG_WALL_H
#define INC_21F_PA01_ARTHUR_ZHANG_WALL_H

#include <iostream>
#include <fstream>
#include "painting.h"
#include <vector>
#include <algorithm>
using namespace std;

class wall {
private:
//    the class that keeps track of TOTAL value of the R on the wall,
//    and the collection of those R: used
//    and the collection of free rectangles: free
    vector<painting> used;
//    sort the free tree based on the LONGEST x side (after insertion)
    vector<painting> free;
    int total_val;

public:
    wall();
//    input size of the canvas
    wall(int x, int y);

    wall(const wall &c);

    wall& operator = (const wall &c);

    int getVal();

    void output_max(ofstream& out);

    void setup_free(int x, int y);
//    insert a painting R into the bottom left corner of a FREE rectangle with the longest X value (while fit)
//    then split the remaining space into 2 free rectangles
//    return true if inserted, return false if no available free space
    bool insert_R(painting R);

    static bool cmpX(painting i, painting j){
        return (i.getX() > j.getX());
    }

};


#endif //INC_21F_PA01_ARTHUR_ZHANG_WALL_H
