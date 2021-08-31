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
//        load painting into vectors
        painting tempP(price, picX, picY, ID);
        archive_default.emplace_back(tempP);
        archive_price.emplace_back(tempP);
        archive_area.emplace_back(tempP);
    }
}

void manager::sortPic(){
    sort(archive_price.begin(), archive_price.end(), cmpPrice);
    sort(archive_area.begin(), archive_area.end(), cmpArea);
}

