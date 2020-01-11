//
//  Pokemon.h
//  PA3
//
//  Created by Ryuichi Ohhata on 11/8/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#ifndef Pokemon_h
#define Pokemon_h

#include <stdio.h>
#include <iostream>
#include "string.h"
#include "Point2D.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "math.h"
#include <stdlib.h>
//#include "Model.h"
#include "BattleArena.h"
#include "Rival.h"

class Pokemon : public GameObject{
    enum PokemonStates {
        STOPPED = 0,
        MOVING = 1,
        EXHAUSTED = 2,
        IN_GYM = 3,
        IN_CENTER = 4,
        MOVING_TO_GYM = 5,
        MOVING_TO_CENTER = 6,
        TRAINING_IN_GYM = 7,
        RECOVERING_STAMINA = 8,
        //pa4
        IN_ARENA = 9,
        MOVING_TO_ARENA = 10,
        BATTLE = 11,
        FAINTED = 12
    };
    
public:
    Pokemon();
    Pokemon(char);
    Pokemon(string, int, char, unsigned int, Point2D);
    ~Pokemon();
    
    void StartMoving(Point2D);
    void StartMovingToCenter(PokemonCenter*);
    void StartMovingToGym(PokemonGym*);
    void StartTraining(unsigned int);
    void StartRecoveringStamina(unsigned int);
    void Stop();
    bool IsExhausted();
    bool ShouldBeVisible();
    void ShowStatus();
    bool Update();
    
    string getName(); // get pokemon name
    
    //pa4
    Pokemon(string, double, double, double, double, double, int, char, Point2D);
    bool IsAlive();
    void TakeHit(double, double, double);
    void ReadyBattle(Rival*);
    bool StartBattle();
    void StartMovingToArena(BattleArena* arena);
    
protected:
    bool UpdateLocation(); 
    void SetupDestination(Point2D);
    //pa4
    double health = 20;
    double store_health = health;
    double physical_damage = 5;
    double magical_damage = 4;
    double defense;
    Rival* target;
    bool is_in_arena = false;
    BattleArena* current_arena;
    
    
private:
    double speed;
    bool is_in_gym = false;
    bool is_in_center = false;
    unsigned int stamina = 20;
    unsigned int experience_points = 0;
    double pokemon_dollars = 0;
    unsigned int training_units_to_buy = 0;
    unsigned int stamina_points_to_buy = 0;
    string name;
    PokemonCenter* current_center = 0;
    PokemonGym* current_gym = 0;
    Point2D destination;
    Vector2D delta;
    
    
};

double GetRandomAmountOfPokemonDollars();

#endif /* Pokemon_h */

