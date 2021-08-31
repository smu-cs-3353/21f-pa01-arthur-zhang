//
// Created by AZ on 8/29/2021.
//

#ifndef INC_21F_PA01_ARTHUR_ZHANG_MANAGER_H
#define INC_21F_PA01_ARTHUR_ZHANG_MANAGER_H

#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class manager {
public:
    manager()=default;

    void run(ifstream& input, ofstream& brute_force, ofstream& high_value, ofstream& custom);

    void readPic(ifstream& Text);
};


#endif //INC_21F_PA01_ARTHUR_ZHANG_MANAGER_H
