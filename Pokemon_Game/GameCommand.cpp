//
//  GameCommand.cpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/20/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#include "GameCommand.h"

void DoMoveCommand(Model &model, int pokemon_id, Point2D p1){
    
    if (model.GetPokemonPtr(pokemon_id) != 0){
        cout << "Moving " << model.GetPokemonPtr(pokemon_id) -> getName() << " to " << p1 << endl;
        model.GetPokemonPtr(pokemon_id) -> StartMoving(p1);
    }
    else{
        throw Invalid_Input("Invalid Pokemon ID\n");
    }
}

void DoMoveToCenterCommand(Model &model, int pokemon_id, int center_id){

    if(model.GetPokemonCenterPtr(center_id) != 0 && model.GetPokemonPtr(pokemon_id) != 0){//if they both exist
        cout << "Moving " << model.GetPokemonPtr(pokemon_id) -> getName() << " to center " << center_id << endl;
        model.GetPokemonPtr(pokemon_id) -> StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
    }
    else {
        throw Invalid_Input("Invalid Pokemon ID or Pokemon Center ID\n");
    }
}

void DoMoveToArenaCommand(Model &model, int pokemon_id, int arena_id){
    if (model.GetArenaPtr(arena_id) != 0 && model.GetPokemonPtr(pokemon_id) != 0){
        cout << "Moving " << model.GetPokemonPtr(pokemon_id) -> getName() << " to Arena " << arena_id << endl;
        model.GetPokemonPtr(pokemon_id) -> StartMovingToArena(model.GetArenaPtr(arena_id));
    }
    
    else{
        throw Invalid_Input("Invalid Pokemon ID or Battle Arena ID\n");
    }
}

void DoMoveToGymCommand(Model &model, int pokemon_id, int gym_id){
    if (model.GetPokemonGymPtr(gym_id) != 0 && model.GetPokemonPtr(pokemon_id) != 0){
        cout << "Moving " << model.GetPokemonPtr(pokemon_id) -> getName() << " to gym " << gym_id << endl;
        model.GetPokemonPtr(pokemon_id) -> StartMovingToGym(model.GetPokemonGymPtr(gym_id));
        
    }
    else {
        throw Invalid_Input("Invalid Pokemon ID or Pokemon Gym ID\t");
    }
}

void DoStopCommand(Model &model, int pokemon_id){
    if (model.GetPokemonPtr(pokemon_id) != 0){
        cout << "Stopping " << model.GetPokemonPtr(pokemon_id) -> getName() << endl;
        model.GetPokemonPtr(pokemon_id) -> Stop();
        //model.Update();
    }
    else {
        throw Invalid_Input("Invalid Pokemon ID\n");
    }
}

void DoTrainInGymCommand(Model &model, int pokemon_id, unsigned int training_units){
    if (model.GetPokemonPtr(pokemon_id) != 0){
        cout << "Training " << model.GetPokemonPtr(pokemon_id) -> getName() << endl;
        model.GetPokemonPtr(pokemon_id) -> StartTraining(training_units);

    }
        else{
            throw Invalid_Input("Invalid Pokemon ID\n");
    }
}

void DoRecoverInCenterCommand(Model &model, int pokemon_id, unsigned int stamina_points){
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        cout << "Recovering " << model.GetPokemonPtr(pokemon_id) -> getName()  << "\'s stamina" << endl;
        model.GetPokemonPtr(pokemon_id) -> StartRecoveringStamina(stamina_points);
    }
    else
        throw Invalid_Input("Invalid Pokemon ID\n");
}

void DoBattleInArenaCommand(Model &model, int pokemon_id, int rival_id){
    if (model.GetRivalPtr(rival_id) != 0 && model.GetPokemonPtr(pokemon_id)){
        //cout <<"Getting ready for the battle" << endl;
        model.GetPokemonPtr(pokemon_id) -> ReadyBattle(model.GetRivalPtr(rival_id));
    }
    else
        throw Invalid_Input("Invalid Pokemon ID or Rival ID\n");
}

void DoGoCommand(Model &model, View &view){
     cout << "Advancing one tick" << endl;
    view.Clear();
    model.Update();
    model.ShowStatus();
   
}

void DoRunCommand(Model &model, View &view){
     cout << "Advancing to next event" << endl;
    int counthis = 0;
    view.Clear(); //in the program does not reach to clean in while loop
    while (model.Update() != true && counthis < 4) {
        view.Clear();
        counthis++;
    }
    model.ShowStatus();
}

void DoMakeNewObject(Model& model, char command, int in_id, Point2D in_loc){
    cout << "Making a new object..." << endl;
    if (command == 'g'){
        if (model.GetPokemonGymPtr(in_id) != 0){
            throw Invalid_Input("Duplicated Pokemom Gym ID number\n");
        }
        else {
            model.MakeNewGym(new PokemonGym(5, 5, 5, 5, in_id, in_loc));
        }
    }
    else if (command == 'c'){
        if (model.GetPokemonCenterPtr(in_id) != 0){
            throw Invalid_Input("Dupulicated Pokemon Center ID number\n");
    }
        else {
            model.MakeNewCenter(new PokemonCenter(in_id, 5, 5, in_loc));
        }
    }
    else if (command == 'p'){
        if (model.GetPokemonPtr(in_id) != 0){
            throw Invalid_Input("Duplicated Pokemon ID number\n");
        }
        else {
            model.MakeNewPokemon(new Pokemon("Pokemon", in_id, 'P', 5, in_loc));
        }
    }
    else if (command == 'r'){
        if (model.GetRivalPtr(in_id) != 0){
            throw Invalid_Input("Duplicated Rival ID number\n");
        }
        else {
            model.MakeNewRival(new Rival("Rival", 5, 5, 5, 5, 5, in_id, in_loc));
        }
    }
}





