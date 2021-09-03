//
// Created by AZ on 8/29/2021.
//

#include "manager.h"

void manager::run(ifstream& input, ofstream& brute_force, ofstream& high_value, ofstream& custom){
    readPic(input);
    expensive_packing();
}

void manager::readPic(ifstream& Text){
    if(!Text.is_open()){
        cout<<"Text file fail to open"<<endl;
    }
//    declare int to use
    string strtemp;
    int ID, price, picX, picY;
    string line;
//  read in first line (wall size)
    getline(Text, line);
    stringstream first_line(line);
    getline(first_line, strtemp, ' ');
    wall_x = stoi(strtemp);
    getline(first_line, strtemp, ' ');
    wall_y = stoi(strtemp);

//  read in second line (num of paintings)
    getline(Text, line);
    stringstream second_line(line);
    getline(second_line, strtemp, ' ');
    archive_size = stoi(strtemp);

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
        archive_custom.emplace_back(tempP);
    }
    sortPic();
    cout<<"pause prog"<<endl;
}

void manager::sortPic(){
    sort(archive_price.begin(), archive_price.end(), cmpPrice);
    sort(archive_custom.begin(), archive_custom.end(), cmpArea);
}

//    using functions from wall class to dump all of the pictures from archive into bins
void manager::expensive_packing(){
    price_bin.setup_free(wall_x, wall_y);
    for (auto& it: archive_price){
//        if no free space fit, return false and go next R
        price_bin.insert_R(it);
    }
    cout<< "expensive packing done"<<endl;
}

void manager::brute_packing(){

    if (archive_size <= 10){

    }
    else {
//        output "data set size exceeds maximum" to file
    }
}


void manager::custom_packing(){
//    while stay_bin stays true, don't change bin
    bool stay_bin = true;
//    for (archive doesnt run out)
    for (auto& it: archive_custom){
        for (auto&it_bin: bins){
            //        insert R into current wall
            wall temp_bin (wall_x, wall_y);
//        if no free space fit, return false and go next R
// todo: needs work on moving to next bin
            stay_bin = temp_bin.insert_R(it);
        }

    }

}
