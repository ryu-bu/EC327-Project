//
//  Vector2D.hpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/1/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#ifndef Vector2D_h
#define Vector2D_h

#include <stdio.h>
#include <iostream>

using namespace std;

class Vector2D{
public:
    double x;
    double y;
    
    Vector2D(){
        x = 0.0;
        y = 0.0;
    }//constructor
    
    Vector2D(double in_x, double in_y){
        x = in_x;
        y = in_y;
    }//constructor
};

Vector2D operator * (Vector2D, double);

Vector2D operator / (Vector2D, double);

ostream &operator << (ostream&, Vector2D);


#endif /* Vector2D_hpp */
