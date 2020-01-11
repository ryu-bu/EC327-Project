//
//  BattleArena.hpp
//  PA3
//
//  Created by Ryuichi Ohhata on 12/2/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#ifndef BattleArena_h
#define BattleArena_h

#include <stdio.h>
#include "Building.h"
enum BattleArenaStates {
    RIVALS_AVAILABLE = 0,
    NO_RIVALS_AVAILABLE = 1
};

class BattleArena : public Building{
private:
    unsigned int max_num_rivals = 3;
    unsigned int num_rivals_remaining = max_num_rivals;
    double dollar_cost_per_fight;
    unsigned int stamina_cost_per_fight;
    unsigned int pokemon_count;
    
public:
    BattleArena();
    BattleArena(unsigned int, unsigned int, double, int, Point2D);
    unsigned int GetNumRivalsRemaining();
    bool HasEnoughRivals();
    double GetDollarCost();
    unsigned int GetStaminaCost();
    bool IsAbleToFight(double, unsigned int);
    bool Update();
    bool IsBeaten();
    void ShowStatus();
    void RemoveRival();
};

#endif /* BattleArena_h */
