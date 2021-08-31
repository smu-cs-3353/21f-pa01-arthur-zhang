//
// Created by AZ on 8/29/2021.
//

#include "manager.h"

void manager::run(ifstream& input, ofstream& brute_force, ofstream& high_value, ofstream& custom){
    readPic(input);
}

void manager::readPic(ifstream& Text){
    if(!Text.is_open()){
        cout<<"Text file fail to open"<<endl;
    }
//    declare int to use
    string strtemp;
    int wallX, wallY, num, ID, price, picX, picY;
    string line;
//  read in first line (wall size)
    getline(Text, line);
    stringstream first_line(line);
    getline(first_line, strtemp, ' ');
    wallX = stoi(strtemp);
    getline(first_line, strtemp, ' ');
    wallY = stoi(strtemp);

//  read in second line (num of paintings)
    getline(Text, line);
    stringstream second_line(line);
    getline(second_line, strtemp, ' ');
    num = stoi(strtemp);

//    read in third to N lines
    while(getline(Text, line)){
        stringstream ss(line);
        getline(ss, strtemp, ' ');
        ID = stoi(strtemp);
        getline(ss, strtemp, ' ');
        price = stoi(strtemp);
        getline(ss, strtemp, ' ');
        picX = stoi(strtemp);
        getline(ss, strtemp, ' ');
        picY = stoi(strtemp);
//        test printout
        cout<< ID << " " << price << " " << picX << " " << picY <<endl;
    }




    pair <int, int> xANDy;

//        get number of pictures


//        get pictures: ID, price, size_x, size_y

}