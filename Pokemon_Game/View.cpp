//
//  View.cpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/23/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#include "View.h"

bool View::GetSubscripts(int &out_x, int &out_y, Point2D location){
    out_x = (location.x - origin.x) / scale;
    out_y = (location.y - origin.y) / scale;
    
    if (out_x <= view_maxsize/scale && out_y <= view_maxsize/scale){
        return true;
    }
    else {
        cout << "An object is outside the display" << endl;
        return false;
    }
}

View::View(){
    size = 11;
    scale = 2;
    origin = Point2D(0, 0);
}

void View::Clear(){
       
       for (int i = 0; i < (view_maxsize/scale) + 1; i++){
           for (int j = 0; j < (view_maxsize/scale) + 1; j ++){
               grid[i][j][0] = '.'; //plot default
               grid[i][j][1] = ' ';//plot default
           }
       }
}

void View::Plot(GameObject* ptr){
    int out_x;
    int out_y;
    if (GetSubscripts(out_x, out_y, ptr -> GetLocation()) == true){
        int y = (view_maxsize/scale) - out_y;//becasue the grid is upside down
        if (grid[y][out_x][0] != '.' /*&& grid[y][out_x][1] != ' '*/){//if there is an object
            grid[y][out_x][0] = '*';
            grid[y][out_x][1] = ' ';
        }
        else {
             ptr -> DrawSelf(&grid[y][out_x][0]);//plot object on grid
        }
    }
}

void View::Draw(){
    int num = view_maxsize;
           int count1 = 0;
           
           for (int i = 0; i < (view_maxsize/scale) + 1; i++){
               if (count1 % 4 == 0){
                   if ((num-count1) < 10){
                       cout << num - count1 << " ";
                   }
                   else {
                       cout << num - count1;
                   }
               }
               else {
                   cout << "  ";
               }
               for (int j = 0; j < (view_maxsize/scale) + 1; j ++){
                   cout <<  grid[i][j][0] << grid[i][j][1];
               }
                count1 += 2;
               cout << endl;
           }
           cout << "  " << 0 << "   " << 4 << "   " << 8 << "   " << 12 << "  " << 16 << "  " << 20 << endl;
}
    
