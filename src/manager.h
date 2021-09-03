//
// Created by AZ on 8/29/2021.
//

#ifndef INC_21F_PA01_ARTHUR_ZHANG_MANAGER_H
#define INC_21F_PA01_ARTHUR_ZHANG_MANAGER_H

#include <set>
#include <iostream>
#include <fstream>
#include <sstream>


#include "wall.h"

using namespace std;
class manager {
private:
    vector<painting> archive_default;
    vector<painting> archive_price;
    vector<painting> archive_custom;
    vector<wall> bins;
    wall default_bin;
    wall price_bin;
    wall custom_bin;
public:
    int wall_x, wall_y, archive_size;


    manager()=default;

    void run(ifstream& input, ofstream& brute_force, ofstream& high_value, ofstream& custom);

    void readPic(ifstream& Text);

    void sortPic();

//    using functions from wall class to dump all of the pictures from archive into bins
    void brute_packing();

    void expensive_packing();

    void custom_packing();




//    CMP logic
//    sort by bigger first
    static bool cmpPrice(painting i, painting j){
        return (i.getPrice() > j.getPrice());
    }
    static bool cmpArea(painting i1, painting i2){
        int first_area = i1.getX() * i1.getY();
        int sec_area = i2.getX() * i2.getY();
        return (first_area > sec_area);
    }
    static bool cmpBin(wall i, wall j){
        return (i.getVal() > j.getVal());
    }

};




#endif //INC_21F_PA01_ARTHUR_ZHANG_MANAGER_H
