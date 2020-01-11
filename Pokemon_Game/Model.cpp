//
//  Model.cpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/19/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#include "Model.h"

Model :: Model() {
    time = 0;
    pokemon_ptrs.push_back(new Pokemon("Pickachu", 2, 23, 3, 6, 12, 1, 'P', Point2D(5, 1)));
    pokemon_ptrs.push_back( new Pokemon("Bulbasaur", 1, 26, 4, 3.7, 16, 2, 'P', Point2D(10, 1)));
    rival_ptrs.push_back(new Rival("burhack", 0, 16, 3, 7.2, 20, 1, Point2D(15, 12)));
    rival_ptrs.push_back(new Rival("mmark9", 0, 29, 4, 5.2, 12, 2, Point2D(15, 12)));
    rival_ptrs.push_back(new Rival("Densmore(aka BigBoss)", 0, 41, 6, 8.2, 18, 3, Point2D(15, 12)));
    center_ptrs.push_back(new PokemonCenter(1, 1, 100, Point2D(1, 20)));
    center_ptrs.push_back(new PokemonCenter(2, 2, 200, Point2D(10, 20)));
    gym_ptrs .push_back(new PokemonGym(10, 1, 2.0, 3, 1, Point2D(0, 0)));
    gym_ptrs.push_back(new PokemonGym(20, 5, 7.5, 8, 2, Point2D(5, 5)));
    arena_ptrs.push_back(new BattleArena(3, 3, 2.5, 1, Point2D(15, 12)));
    
    object_ptrs.insert(object_ptrs.end(), pokemon_ptrs.begin(), pokemon_ptrs.end());
    object_ptrs.insert(object_ptrs.end(), rival_ptrs.begin(), rival_ptrs.end());
    object_ptrs.insert(object_ptrs.end(), center_ptrs.begin(), center_ptrs.end());
    object_ptrs.insert(object_ptrs.end(), gym_ptrs.begin(), gym_ptrs.end());
    object_ptrs.insert(object_ptrs.end(), arena_ptrs.begin(), arena_ptrs.end());
    
    active_ptrs = object_ptrs;
    
    
    cout << "Model default constructed" << endl;
    
    
}

Model :: ~Model() {
    
    object_ptrs.clear();//deallocate the list
    
    /*for (int i = 0; i < num_objects; i++){
        delete = num_objects[i];
    }*/
    
    cout << "Model destructed." << endl;
}

Pokemon* Model :: GetPokemonPtr(int id){
    list<Pokemon* > :: iterator it;
    for (it = pokemon_ptrs.begin(); it != pokemon_ptrs.end(); it++){
        if (id == (*it) -> GetId()){
            return *it;
        }
    }
    
    return 0;
}

PokemonCenter* Model :: GetPokemonCenterPtr(int id){//return true if input is valid
    list<PokemonCenter*> :: iterator it;
    for (it = center_ptrs.begin(); it != center_ptrs.end(); it++){
        if (id == (*it) -> GetId()){
            return *it;
        }
    }
   
        return 0;
}

PokemonGym* Model :: GetPokemonGymPtr(int id){//return true if input is valid
    list<PokemonGym*> :: iterator it;
    for (it = gym_ptrs.begin(); it != gym_ptrs.end(); it++){
        if (id == (*it) -> GetId()){
            return *it;
        }
    }
   
    return 0;
}

BattleArena* Model :: GetArenaPtr(int id){
    list<BattleArena*> :: iterator it;
    for (it = arena_ptrs.begin(); it != arena_ptrs.end(); it++){
        if (id == (*it) -> GetId()){
            return *it;
        }
    }
    
    return 0;
}

Rival* Model :: GetRivalPtr(int id){
    list<Rival*> :: iterator it;
    for (it = rival_ptrs.begin(); it != rival_ptrs.end(); it++){
        if (id == (*it) -> GetId()){
            return *it;
        }
    }
    
    return 0;
}


bool Model :: Update(){
    time++;
    int checkGym = 0;
    
    list<PokemonGym*> :: iterator gymit;
    for (gymit = gym_ptrs.begin(); gymit != gym_ptrs.end(); gymit++){
        if ((*gymit) -> IsBeaten() == true){
            checkGym++;
        }
    }
    
    if (checkGym == gym_ptrs.size()){
           cout << "GAME OVER! You win! All Pokemon Gyms beaten" << endl;
           _Exit(10);
       }
    
    //check exhausted
    int checkEx = 0;
    list<Pokemon*> :: iterator pokeit;
    for (pokeit = pokemon_ptrs.begin(); pokeit != pokemon_ptrs.end(); pokeit++){
        if ((*pokeit) -> IsExhausted() == true || (*pokeit) -> IsAlive() == false) {
            checkEx++;
        }
    }

    if (checkEx == pokemon_ptrs.size()){// if all pokemons are exhausted, then gameover
        cout << "GAME OVER! You lose! All of your Pokemon are tired or fainted!" << endl;
        _Exit(10);
    }
    int count = 0;
    
    list<GameObject*> :: iterator checkactive;
    for (checkactive = active_ptrs.begin(); checkactive != active_ptrs.end(); advance(checkactive, 1)){
        if (((*checkactive) -> ShouldBeVisible()) == false){
                checkactive = active_ptrs.erase(checkactive);//remove if dead
        }
    }
    //if any of object's update is true, return true
        list<GameObject* > :: iterator it;
        for (it = active_ptrs.begin(); it != active_ptrs.end(); ++it){
            if ((*it) -> Update() == true){
                count++;
            }
    }
    if (count > 0){
           return true;
       }
       else
           return false;
       
}

void Model :: Display(View& view){
    list<GameObject*> :: iterator deadit;
    for (deadit = active_ptrs.begin(); deadit != active_ptrs.end(); deadit++){
        view.Plot(*deadit);
    }
    view.Draw();//display on screen
}

void Model::ShowStatus(){
    cout << "Time: " << time << endl;
    list<GameObject* > :: iterator it;
    for (it = object_ptrs.begin(); it != object_ptrs.end(); ++it){
        (*it) -> ShowStatus();
    }
}

void Model::MakeNewGym(PokemonGym *in_gym){
    gym_ptrs.push_back(in_gym);
    object_ptrs.push_back(in_gym);
    active_ptrs.push_back(in_gym);
}

void Model::MakeNewCenter(PokemonCenter * in_center){
    center_ptrs.push_back(in_center);
    object_ptrs.push_back(in_center);
    active_ptrs.push_back(in_center);
}

void Model::MakeNewPokemon(Pokemon* in_pok){
    pokemon_ptrs.push_back(in_pok);
    object_ptrs.push_back(in_pok);
    active_ptrs.push_back(in_pok);
}

void Model :: MakeNewRival(Rival *in_rival){
    rival_ptrs.push_back(in_rival);
    object_ptrs.push_back(in_rival);
    active_ptrs.push_back(in_rival);
}


