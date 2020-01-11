//
//  PokemonGym.hpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/4/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#ifndef PokemonGym_h
#define PokemonGym_h

#include <stdio.h>
#include "Building.h"

class PokemonGym : public Building {
    enum PokemonGymStates {
        NOT_BEATEN = 0,
        BEATEN = 1
    };
    
private:
    double num_training_units_remaining = 0;
    unsigned int max_number_of_training_units;
    unsigned int stamina_cost_per_training_unit;
    double dollar_cost_per_training_unit;
    unsigned int experience_points_per_training_unit;
    
public:
    PokemonGym();
    PokemonGym(unsigned int, unsigned int, double, unsigned int, int,  Point2D);
    ~PokemonGym();
    
    double GetDollarCost(unsigned int);
    unsigned int GetStaminaCost(unsigned int);
    unsigned int GetNumTrainingUnitsRemaining();
    bool IsAbleToTrain(unsigned int, double, unsigned int);
    unsigned int TrainPokemon(unsigned int);
    bool Update();
    bool IsBeaten();
    void ShowStatus();
};


#endif /* PokemonGym_h */

