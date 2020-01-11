//
//  Point2D.cpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/1/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#include "Point2D.h"
#include <cmath>
#include <iostream>

using namespace std;

double GetDistanceBetween(Point2D p1, Point2D p2){
    
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)); //calculates the distance between two loc
    
}

ostream &operator << (ostream &out, Point2D &p1){
    out << "(" << p1.x << ", " << p1.y << ")" ;
    
    return out;
}

Point2D operator + (Point2D p1, Vector2D v1){
    return Point2D(p1.x + v1.x, p1.y + v1.y);
}

Vector2D operator - (Point2D p1, Point2D p2){
    return Vector2D(p1.x - p2.x, p1.y - p2.y);
}
