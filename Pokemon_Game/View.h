//
//  View.hpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/23/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#ifndef View_h
#define View_h

#include <stdio.h>
//#include "Model.h"
#include "Point2D.h"
#include "GameObject.h"

const int view_maxsize = 20;

class View {
private:
    int size;
    double scale;
    Point2D origin;
    char grid[view_maxsize][view_maxsize][2];
    bool GetSubscripts(int&, int&, Point2D);
    
public:
    View();
    void Clear();
    void Plot(GameObject*);
    void Draw();
    
};
#endif /* View_h */
