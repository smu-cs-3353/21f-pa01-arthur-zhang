//
// Created by AZ on 8/29/2021.
//

#ifndef INC_21F_PA01_ARTHUR_ZHANG_MANAGER_H
#define INC_21F_PA01_ARTHUR_ZHANG_MANAGER_H

#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "wall.h"

using namespace std;
class manager {
private:
    vector<painting> archive_default;
    vector<painting> archive_price;
    vector<painting> archive_area;
    vector<wall> bins;
public:
    manager()=default;

    void run(ifstream& input, ofstream& brute_force, ofstream& high_value, ofstream& custom);

    void readPic(ifstream& Text);

    void sortPic();
//    CMP logic
    static bool cmpPrice(painting i, painting j){
        return (i.getPrice() < j.getPrice());
    }
    static bool cmpArea(painting i1, painting i2){
        int first_area = i1.getX() * i1.getY();
        int sec_area = i2.getX() * i2.getY();
        return (first_area < sec_area);
    }

};




#endif //INC_21F_PA01_ARTHUR_ZHANG_MANAGER_H
