//
//  Model.hpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/19/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#ifndef Model_h
#define Model_h

#include <stdio.h>
#include "Pokemon.h"
#include "View.h"
#include "Rival.h"
#include <cstdlib>
#include <list>
#include "BattleArena.h"

using namespace std;

class Model {
private:
    int time;
    list<GameObject*> object_ptrs;
    list<GameObject*> active_ptrs;
    list<Pokemon*> pokemon_ptrs;
    list<Rival*> rival_ptrs;
    list<PokemonCenter*> center_ptrs;
    list<PokemonGym*> gym_ptrs;
    list<BattleArena*> arena_ptrs;
    
    
public:
    Model();
    ~Model();
    Pokemon* GetPokemonPtr(int);
    PokemonCenter* GetPokemonCenterPtr(int);
    PokemonGym* GetPokemonGymPtr(int);
    Rival* GetRivalPtr(int);
    BattleArena* GetArenaPtr(int);
    void MakeNewGym(PokemonGym*);//make new gym command
    void MakeNewCenter(PokemonCenter*); //make new center command
    void MakeNewPokemon(Pokemon*); //make new pokemon command
    void MakeNewRival(Rival*); //make new rival
    
    bool Update();
    void Display(View&);
    void ShowStatus();
    
};



#endif /* Model_h */
