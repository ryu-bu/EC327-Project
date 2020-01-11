//
//  PokemonCenter.hpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/4/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#ifndef PokemonCenter_h
#define PokemonCenter_h

#include <stdio.h>
#include "Building.h"

class PokemonCenter : public Building {
    enum PokemonCenterStates {
        STAMINA_POINTS_AVAILABLE = 0,
        NO_STAMINA_POINTS_AVAILABLE = 1
    };
    
private:
    unsigned int stamina_capacity = 100;
    unsigned int num_stamina_points_remaining = stamina_capacity;
    double dollar_cost_per_stamina_point;
    
public:
    PokemonCenter();
    PokemonCenter(int, double, unsigned int, Point2D);
    ~PokemonCenter();
    
    bool HasStaminaPoints();
    unsigned int GetNumStaminaPointsRemaining();
    bool CanAffordStaminaPoints(unsigned int, double);
    double GetDollarCost(unsigned int);
    unsigned int DistributeStamina(unsigned int);
    bool Update();
    void ShowStatus();
};

#endif /* PokemonCenter_h */
