//
//  BattleArena.cpp
//  PA3
//
//  Created by Ryuichi Ohhata on 12/2/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#include "BattleArena.h"
using namespace std;

BattleArena::BattleArena(){
    display_code = 'A';
    pokemon_count = 0;
    max_num_rivals = 3;
    num_rivals_remaining = max_num_rivals;
    dollar_cost_per_fight = 4;
    stamina_cost_per_fight = 3;
    state = RIVALS_AVAILABLE;
    
    cout << "BattleArena default constructed" << endl;
}

BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_id, Point2D in_loc) : Building('A', in_id, in_loc){
    max_num_rivals = max_rivals;
    stamina_cost_per_fight = stamina_cost;
    dollar_cost_per_fight = dollar_cost;
    state = RIVALS_AVAILABLE;
    
    cout << "BattleArena constructed" << endl;
}

unsigned int BattleArena::GetNumRivalsRemaining(){
    return num_rivals_remaining;
}

bool BattleArena::HasEnoughRivals(){
    if (num_rivals_remaining >= 1){
        return true;
    }
    else
        return false;
}

double BattleArena::GetDollarCost(){
    return dollar_cost_per_fight;
}

unsigned int BattleArena::GetStaminaCost(){
    return stamina_cost_per_fight;
}

bool BattleArena::IsAbleToFight(double budget, unsigned int stamina){
    if (budget >= dollar_cost_per_fight && stamina >= stamina_cost_per_fight){
        return true;
    }
    else
        return false;
}

bool BattleArena::Update(){
    if (state != NO_RIVALS_AVAILABLE && num_rivals_remaining == 0){//check
        state = NO_RIVALS_AVAILABLE;
        return true;
    }
    else
        return false;
}

bool BattleArena::IsBeaten(){
    if (num_rivals_remaining == 0){
        return true;
    }
    else
        return false;
}

void BattleArena::RemoveRival(){
    num_rivals_remaining--;
}

void BattleArena::ShowStatus(){
    cout << "Battle Arena Status: ";
    Building::ShowStatus();
    cout << "\tMax number of rivals: " << max_num_rivals << endl;
    cout << "\tStamina cost per fight: " << stamina_cost_per_fight << endl;
    cout << "\tPokemon dollar per fight: " << dollar_cost_per_fight << endl;
    cout << "\t" << num_rivals_remaining << " rivals(s) are remaining for this arena" << endl;
}
