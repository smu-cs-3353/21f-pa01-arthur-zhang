//
// Created by AZ on 8/29/2021.
//

#include "manager.h"

void manager::run(ifstream& input, ofstream& brute_force, ofstream& high_value, ofstream& custom){
    readPic(input);
    brute_packing();
    expensive_packing();
    custom_packing();
    outputFile(brute_force, high_value, custom);
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


    int best_val = 0;
    if (archive_size > 10){
//        output "data set size exceeds maximum" to file
    }
    for (int i=0; i<archive_size; i++){
        wall temp_bin(wall_x, wall_y);
        for (auto& it: archive_default){
//        if no free space fit, return false and go next R
            temp_bin.insert_R(it);
        }
        int temp_int = temp_bin.getVal();
        if (temp_int > best_val){
            best_val = temp_int;
            default_bin = temp_bin;
        }
//        move the last element to the first
        archive_default.emplace(archive_default.end());
        archive_default.pop_back();

    }
    cout<< "brute" <<endl;
}

//todo: debug custom packing
void manager::custom_packing(){
//    while stay_bin stays true, don't change bin
    bool stay_bin = true;
//    initialize with one bin
    wall init_bin (wall_x, wall_y);
    bins.emplace_back(init_bin);
//    for (archive doesnt run out)
    for (auto& it: archive_custom){
//        for all the existing bins
        for (auto&it_bin: bins){
//        insert R into current wall
//        if no free space fit, return false and go next
            stay_bin = it_bin.insert_R(it);
            if (stay_bin == true){
                break;
            }
            else {
                cout<<"doesn't fit, move to next bin"<<endl;
            }
        }
//        if not a single bin fits, create new bin then insert IT
        if (stay_bin == false){
            wall temp_bin(wall_x, wall_y);
            temp_bin.insert_R(it);
            bins.emplace_back(temp_bin);
            stay_bin = true;
        }
    }
}

void manager::outputFile(ofstream& brute_force, ofstream& high_value, ofstream& custom){
//    output brute_force
    if (archive_default.size()>10){
        brute_force << "data set size exceeds maximum"<<endl;
    }
    else {
        brute_force << default_bin.getVal() <<endl;
        default_bin.output_max(brute_force);
    }
//    output expensive
    high_value << price_bin.getVal() <<endl;
    price_bin.output_max(high_value);
//    output custom
    int best_val = 0;
    wall best_bin;
    for (auto&it_bin: bins){
        if (it_bin.getVal() > best_val){
            best_bin = it_bin;
            best_val = it_bin.getVal();
        }
    }
    custom << best_bin.getVal() <<endl;
    best_bin.output_max(custom);


}
