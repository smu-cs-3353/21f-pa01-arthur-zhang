//
// Created by AZ on 8/30/2021.
//

#include "wall.h"
wall::wall(){
    total_val = 0;
};

wall::wall(int x, int y){
//    initialize the wall with its x and y size
    painting R(0, x, y, 0);
    free.emplace_back(R);
//    initialize total value as 0
    total_val = 0;
}

wall:: wall(const wall &c){
    for (auto& it_used: c.used){
        used.emplace_back(it_used);
    }
    for (auto& it_free: c.free){
        free.emplace_back(it_free);
    }
    total_val = c.total_val;
}

wall& wall:: operator = (const wall &c){
    used.clear();
    free.clear();
    for (auto& it_used: c.used){
        used.emplace_back(it_used);
    }
    for (auto& it_free: c.free){
        free.emplace_back(it_free);
    }
    total_val = c.total_val;
    return *this;
}

void wall:: setup_free(int x, int y){
    //    initialize the wall with its x and y size
    painting R(0, x, y, 0);
    free.emplace_back(R);
}

int wall::getVal(){
    return total_val;
}

void wall::output_max(ofstream& out){
    for (auto& it: used){
        out<< it.getID() <<" "<< it.getPrice() <<" "<< it.getX() <<" "<< it.getY() <<" "<< it.getLocX() <<" "<< it.getLocY() <<endl;
    }
}

//todo: bug inserting the rectangles, adding unwanted things into used bin
//    insert a painting R into a FREE rectangle:

bool wall::insert_R(painting R){
//    find the first fitting free space with the largest x value possible
    for (auto& it: free){
        int it_x = it.getX();
        int it_y = it.getY();
        int R_x = R.getX();
        int R_y = R.getY();
        if ( it_x >= R_x && it_y >= R_y){
//            generate the R to put into USED
              painting tempR(R.getPrice(), R_x, R_y, R.getID());
//            location (bottom left corner) # are the same for the free space and the USED R
              tempR.setLoc(it.getLocX(), it.getLocY());
//            update price
              total_val = total_val + tempR.getPrice();
//            put into USED
              if (tempR.getPrice() == 0){
                  cout << "null price" <<endl;
              }
              else {
                  used.emplace_back(tempR);
              }

//            then split the remaining space into 2 free rectangles
//            replace the original space with one of the 2 free rectangles, then emplace_back the other one
//            sort
//            when splitting, try to get as much Y as possible , so Y remains it_y
//            bigger Free
              int newFree_a_x = it_x - R_x;
              painting newFree_a(0, newFree_a_x, it_y, 0);
              newFree_a.setLocX(it.getLocX() + R_x);
              newFree_a.setLocY(it.getLocY());
//            smaller Free
              int newFree_b_y = it_y - R_y;
              painting newFree_b(0, R_x, newFree_b_y, 0);
              newFree_a.setLocY(it.getLocY() + R_y);
              newFree_a.setLocX(it.getLocX());
//            manipulate FREE vector
              it = newFree_a;
              free.emplace_back(newFree_b);
//            sort the FREE vector based on longest X side
              sort(free.begin(), free.end(), cmpX);
//            exit out out the loop and function because task completes
              return true;
        }
//
    }
//    no free space satisfies the current R, jump into the next bin!
    return false;
}