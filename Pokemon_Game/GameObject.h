//
//  GameObject.hpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/1/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#ifndef GameObject_h
#define GameObject_h

#include <iostream>
#include "Point2D.h"

class GameObject {
protected:
    Point2D location;
    int id_num;
    char display_code;
    char state;
    
public:
    GameObject(char);
    GameObject(Point2D, int, char);
   virtual  ~GameObject();
    Point2D GetLocation(){
        return location;
    }
    
    int GetId(){
        return id_num;
    }
    
    char GetState(){
        return state;
    }
    
    virtual void ShowStatus();
    
    virtual bool Update() = 0;

    virtual bool ShouldBeVisible() = 0;
    
    void DrawSelf(char*);
};



#endif /* GameObject_hpp */
