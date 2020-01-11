//
//  PokemonCenter.cpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/4/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#include "PokemonCenter.h"

PokemonCenter::PokemonCenter(){
    display_code = 'C';
    stamina_capacity = 100;
    num_stamina_points_remaining = stamina_capacity;
    dollar_cost_per_stamina_point = 5;
    state = STAMINA_POINTS_AVAILABLE;
    cout << "PokemonCenter default constructed" << endl;
}

PokemonCenter::PokemonCenter(int in_Id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc){
    display_code = 'C';
    id_num = in_Id;
    location = in_loc;
    dollar_cost_per_stamina_point  = stamina_cost;
    stamina_capacity = stamina_cap;
    num_stamina_points_remaining = stamina_capacity;
    cout << "PokemonCenter constructed" << endl;
    state = STAMINA_POINTS_AVAILABLE;
}

PokemonCenter::~PokemonCenter(){
    cout << "PokemonCenter destructed." << endl;
}

bool PokemonCenter::HasStaminaPoints(){
    if (STAMINA_POINTS_AVAILABLE >= 1){
        return true;
    }
    else
        return false;
}

unsigned int PokemonCenter::GetNumStaminaPointsRemaining(){
    return num_stamina_points_remaining;
}

bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget){
    if (budget >= stamina_points * dollar_cost_per_stamina_point) //check if player can afford
        return true;
    else
        return false;
}

double PokemonCenter::GetDollarCost(unsigned int stamina_points){
    return dollar_cost_per_stamina_point * stamina_points; //price
}

unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed){
    if (points_needed <= num_stamina_points_remaining){ // subtract stamina from center
        num_stamina_points_remaining -= points_needed;
        return points_needed;
    }
    else {
        num_stamina_points_remaining = 0;
        return num_stamina_points_remaining;
    }
}

bool PokemonCenter::Update(){
    if (num_stamina_points_remaining == 0){
        state = NO_STAMINA_POINTS_AVAILABLE;
        display_code = 'c';
        cout << "PokemonCenter " << id_num << " has ran out of stamina points." << endl;
        
        static int count = 0;
        //only returns true once
        if (count == 0){
            count++;
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

void PokemonCenter::ShowStatus(){
    cout << "Pokemon Center status: ";
    Building::ShowStatus();
    cout << "\tPokemon dollars per stamina point: " << dollar_cost_per_stamina_point << endl;
    cout << "\thas " << num_stamina_points_remaining << " stamina points(s) remaining" << endl;
}


