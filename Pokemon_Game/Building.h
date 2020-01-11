//
//  Building.hpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/4/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#ifndef Building_h
#define Building_h

#include <stdio.h>
#include "GameObject.h"

class Building : public GameObject{
private:
    unsigned int pokemon_count = 0;
    
    
public:
    void AddOnePokemon();
    void RemoveOnePokemon();
    void ShowStatus();
    bool ShouldBeVisible();
    
    Building();
    Building(char, int, Point2D);
};

#endif /* Building_h */
