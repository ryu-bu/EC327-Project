//
//  PokemonGym.cpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/4/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#include "PokemonGym.h"

PokemonGym::PokemonGym() {
    display_code = 'G';
    state = NOT_BEATEN;
    max_number_of_training_units = 10;
    num_training_units_remaining = max_number_of_training_units;
    stamina_cost_per_training_unit = 1;
    dollar_cost_per_training_unit = 1.0;
    experience_points_per_training_unit = 2;
    cout << "PokemonGym default constructed" << endl;
}
    
PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc){
    display_code = 'G';
    id_num = in_id;
    state = NOT_BEATEN;
    max_number_of_training_units = max_training_units;
    num_training_units_remaining = max_number_of_training_units;
    stamina_cost_per_training_unit = stamina_cost;
    dollar_cost_per_training_unit  = dollar_cost;
    experience_points_per_training_unit = exp_points_per_unit;
    location = in_loc;
    cout << "PokemonGym constructed" << endl;
}

PokemonGym::~PokemonGym(){
    cout << "PokemonGym destructed." << endl;
}

double PokemonGym::GetDollarCost(unsigned int unit_qty){
    return dollar_cost_per_training_unit * unit_qty;
}

unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty){
    return stamina_cost_per_training_unit * unit_qty;
}

unsigned int PokemonGym::GetNumTrainingUnitsRemaining(){
    return num_training_units_remaining;
}

bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina){
    if (budget >= dollar_cost_per_training_unit * unit_qty && stamina >= stamina_cost_per_training_unit * unit_qty)
        return true;
    else
        return false;
}

unsigned int PokemonGym::TrainPokemon(unsigned int training_units){
    if (num_training_units_remaining >= training_units){
        num_training_units_remaining -= training_units;
    }
    else {
        training_units = num_training_units_remaining;
        num_training_units_remaining -= training_units;
    }
    
    return training_units * experience_points_per_training_unit;
}

bool PokemonGym::Update(){
    if (IsBeaten() == true){
        state = BEATEN;
        display_code = 'g';
        cout << display_code << id_num << " has been beaten" << endl;
        
        static int count = 0;
        if (count == 0){ //return true only once
            count++;
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

bool PokemonGym::IsBeaten(){
    if (num_training_units_remaining == 0)
        return true;
    else
        return false;
}

void PokemonGym::ShowStatus(){
    cout << "Pokemon Gym Status: ";
    Building::ShowStatus();
    cout << "\tMax number of training units: " << max_number_of_training_units << endl;
    cout << "\tStamina cost per training units: " << stamina_cost_per_training_unit << endl;
    cout << "\tPokemon dollar cost per training unit: " << dollar_cost_per_training_unit << endl;
    cout << "\tExperience points per training: " << experience_points_per_training_unit << endl;
    cout << "\t" << num_training_units_remaining << " training unit(s) are remaining for this gym" << endl;
    
}
