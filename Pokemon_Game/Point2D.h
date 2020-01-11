//
//  Point2D.hpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/1/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#ifndef Point2D_h
#define Point2D_h

#include <iostream>
#include "Vector2D.h"

using namespace std;

class Point2D{
    public:
        double x;
        double y;
    
    Point2D(){
        x = 0.0;
        y = 0.0;
    }//constructor
    
    Point2D(double in_x, double in_y){
        x = in_x;
        y = in_y;
    }//constructor
};

ostream &operator << (ostream&, Point2D&);

Point2D operator + (Point2D, Vector2D);

Vector2D operator - (Point2D, Point2D);

double GetDistanceBetween(Point2D, Point2D);



#endif /* Point2D_hpp */
