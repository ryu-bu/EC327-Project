//
//  GameObject.cpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/1/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#include "GameObject.h"
#include "Point2D.h"
#include <iostream>

using namespace std;

GameObject::GameObject(char in_code){
    display_code = in_code;
    id_num = 1;
    state = 0;
    cout <<"GameObject constructed" << endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code){
    display_code = in_code;
    id_num = in_id;
    location = in_loc;
    state = 0;
    cout << "GameObject constructed" << endl;
}

GameObject::~GameObject(){
    cout << "GameObject destructed." << endl;
}

void GameObject::ShowStatus(){
    cout << display_code << id_num << " at "<< location << " ";
}

void GameObject::DrawSelf(char* ptr){
    *ptr = display_code;
    *(ptr + 1) = static_cast<char>(id_num + '0'); //draw the object on the grid
}







