//
// Created by AZ on 8/30/2021.
//

#ifndef INC_21F_PA01_ARTHUR_ZHANG_WALL_H
#define INC_21F_PA01_ARTHUR_ZHANG_WALL_H

#include "painting.h"
#include <vector>

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
//    input size of the canvas
    wall(int x, int y);


    int getVal();

//    insert a painting R into the bottom left corner of a FREE rectangle with the longest X value (while fit)
//    then split the remaining space into 2 free rectangles
    void insert_R(painting R);





};


#endif //INC_21F_PA01_ARTHUR_ZHANG_WALL_H
