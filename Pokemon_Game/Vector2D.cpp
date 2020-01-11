//
//  Vector2D.cpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/1/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#include "Vector2D.h"
#include <iostream>

using namespace std;

Vector2D operator * (Vector2D v1, double d){
    return Vector2D(v1.x * d, v1.y * d);
}

Vector2D operator / (Vector2D v1, double d){
    return Vector2D(v1.x / d, v1.y / d);
}

ostream &operator << (ostream &out, Vector2D v1){
    out << "<" << v1.x << ", " << v1.y << ">";
    
    return out;
}
