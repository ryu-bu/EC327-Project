//
//  Rival.hpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/30/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#ifndef Rival_h
#define Rival_h

#include <stdio.h>
#include "Point2D.h"
//#include "Pokemon.h"
#include "BattleArena.h"
#include <stdlib.h>

enum RivalStates {
    ALIVE_RIVAL = 0,
    FAINTED_RIVAL= 1
};

class Rival : public GameObject{
protected:
    double health = 20;
    double physical_damage = 5;
    double magical_damage = 4;
    double defense;
    double stamina_cost_per_fight;
    bool is_in_arena;
    BattleArena *current_arena;
    string name;
    
public:
    Rival(string, double, double, double, double, double, int, Point2D);
    void TakeHit(double, double, double);
    double get_phys_dmg();
    double get_magic_dmg();
    double get_defense();
    double get_health();
    bool Update();
    void ShowStatus();
    bool IsAlive();
    bool ShouldBeVisible();
};

#endif /* Rival_h */
