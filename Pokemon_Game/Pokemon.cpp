//
//  Pokemon.cpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/8/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#include "Pokemon.h"

int centerFlag = 0;

Pokemon::Pokemon() : GameObject('P'){
    speed = 5;
    cout << "Pokemon default constructed" << endl;
}

Pokemon::Pokemon(char in_code) : GameObject(in_code){
    speed = 5;
    cout << "Pokemon constructed" << endl;
    state = STOPPED;
    display_code = in_code;
}

Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) : GameObject(in_loc, in_id, in_code){
    speed = in_speed;
    name = in_name;
    cout << "Pokemon constructed" << endl;
}

//pa4
Pokemon::Pokemon(string in_name, double in_speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc) : GameObject(in_loc, in_id, 'P'){
    name = in_name;
    speed = in_speed;
    health = hp;
    store_health = hp;
    physical_damage = phys_dmg;
    magical_damage = magic_dmg;
    defense = def;
    cout << "Pokemon constructed" << endl;
    //Model::Update();
}

Pokemon::~Pokemon(){
    cout << "Pokemon destructed." << endl;
}

bool Pokemon::IsExhausted(){
    if (stamina == 0){
        stamina = 0; //stamina should not go below 0
        state = STOPPED;
        return true;
    }
    else
        return false;
}

void Pokemon::StartMoving(Point2D dest){
    state = MOVING;
    SetupDestination(dest); // setup new loc
    if (location.x == destination.x && location.y == destination.y){//if there, location is destination
        cout << display_code << id_num <<": I'm already there. See?" << endl;
    }
    if (IsExhausted() == true){
        cout << display_code << id_num << ": I am exhausted. I may move but you cannot see me." << endl;
    }
    if (IsAlive() == false){
        cout << display_code << id_num << " is fainted." << endl;
        state = FAINTED;
    }
    else {
        cout << display_code << id_num << ": On my way." << endl;
        
    }
}

void Pokemon::StartMovingToCenter(PokemonCenter * center){
    current_center = center;
    SetupDestination(current_center -> GetLocation()); // set up a new destination
    state = MOVING_TO_CENTER;
     
    if (IsExhausted() == 1){
        cout << display_code << id_num << ": I am exhausted so I can't move to recover stamina..." << endl;
        //state = STOPPED; //if exhausted, cannot move
    }
    
    else if (state == IN_CENTER || (location.x == destination.x && location.y == destination.y)){
        cout << display_code << id_num << ": I am already at the Pokemon Center!" << endl;
    
    }
    else if (IsAlive() == false){
        cout << display_code << id_num << " is fainted." << endl;
        state = FAINTED;
    }
    else {
        cout << display_code << id_num << ": on my way to center " << center -> GetId() << endl;
       
    }
}

void Pokemon::StartMovingToGym(PokemonGym * gym){
    current_gym = gym;
    SetupDestination(current_gym -> GetLocation());
   
    if (IsExhausted() == 1){
        cout <<  display_code << id_num <<": I am exhausted so I shouldn't be going to the gym.." << endl;
        state = STOPPED; // if exhausted, pokemon cannot move
    }
    else if (state == IN_GYM){
        cout << display_code << id_num << ": I am already at the Pokemon Gym!" << endl;
    }
    else if (IsAlive() == false){
        cout << display_code << id_num << " is fainted." << endl;
        state = FAINTED;
    }
    else {
         state = MOVING_TO_GYM;
        cout << display_code << id_num  << ": On my way to gym " << gym -> GetId() << endl;
        
    }
}

void Pokemon::StartMovingToArena(BattleArena* arena){
    current_arena = arena;
    SetupDestination(current_arena -> GetLocation());
    
    if (IsExhausted() == 1){
        cout <<  display_code << id_num <<": I am exhausted so I shouldn't be going to the arena.." << endl;
        state = STOPPED; // if exhausted, pokemon cannot move
    }
    else if (state == IN_GYM){
        cout << display_code << id_num << ": I am already at the Pokemon Arena!" << endl;
    }
    else {
         state = MOVING_TO_ARENA;
        cout << display_code << id_num  << ": On my way to arena " << arena -> GetId() << endl;
        
    }
    
}

void Pokemon::StartTraining(unsigned int num_training_units){
        state = TRAINING_IN_GYM;
        
    if (is_in_gym == false) {//if not in gym, cannot train
        cout << "Not in gym! Cannot train!" << endl;
    }
        else if (IsExhausted() == 1) {
            cout << display_code << id_num << ": I am exhausted so no more training for me..." << endl;
        }
        else if (current_gym -> IsAbleToTrain(num_training_units, pokemon_dollars, stamina) != 1){
            cout << display_code << id_num << ": Not enough stamina and/or money for training" << endl;
        }
        else if (current_gym -> GetState() == 1){
            cout << display_code << id_num << ": Cannot train! This Pokemon Gym is already beaten!" << endl;
        }
        else {
            cout << display_code << ": Started to train at Pokemon Gym " << current_gym -> GetId() <<" with " << num_training_units << endl;
             //current_gym -> RemoveOnePokemon();
            if (num_training_units >= current_gym -> GetNumTrainingUnitsRemaining()){
                training_units_to_buy = current_gym -> GetNumTrainingUnitsRemaining();
            }
            else {
                training_units_to_buy = num_training_units;
            }
        }
    }

void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points){
      
        
        if (is_in_center == false){// if not in center, cannot recover
            cout << display_code << id_num << ": I can only recover stamina at a Pokemon Center!" << endl;
        }
        
        else if (current_center -> CanAffordStaminaPoints(num_stamina_points, pokemon_dollars) != true){
            cout << display_code << id_num << ": Not enough money to recover stamina" << endl;
        }
        else if (current_center -> GetNumStaminaPointsRemaining() < 1){
            cout << display_code << id_num << ": Cannot recover! No stamina points remaining in this Pokemon Center" << endl;
        }
        
        else {
            state = RECOVERING_STAMINA;
            cout << display_code << id_num << ": Started recovering " << num_stamina_points << " stamina point(s) at Pokemon Center " << current_center -> GetId() << endl;
           // current_center -> RemoveOnePokemon();
            
            if (num_stamina_points >= current_center -> GetNumStaminaPointsRemaining()){
                stamina_points_to_buy  = current_center -> GetNumStaminaPointsRemaining() ;
            }
            else {
                stamina_points_to_buy = num_stamina_points;
            }
        }
    }

void Pokemon::Stop() {
    state = STOPPED;
    cout << display_code << id_num << ": Stopping.." << endl;
}


bool Pokemon::ShouldBeVisible(){
    if (IsExhausted() == true){
        return false;
    }
    else if (state == FAINTED){
        return false;
    }
    else
        return true;
}

void Pokemon::ShowStatus(){
    cout << name << " status: ";
    GameObject::ShowStatus();
    //check how to behave
    if (state == STOPPED){
        cout << "stopped"<< endl;
    }
    else if (state == MOVING){
        cout << "moving at a speed of " << speed << " to destination " << destination << " at each step of " << delta << endl;
    }
    else if (state == MOVING_TO_CENTER){
        cout << "heading to Pokemon Center " << current_center -> GetId() << " at a speed of " << speed << " at each step of " << endl;
    }
    else if (state == MOVING_TO_GYM){
        cout << "heading to Pokemon Gym " << current_gym -> GetId() << " at a speed of " << speed << " at each step of " << delta << endl;;
    }
    else if (state == MOVING_TO_ARENA){
        cout << "heading to Battle Arena " << current_arena -> GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
    }
    else if (state == IN_CENTER){
        cout << "inside Pokemon Center " << current_center -> GetId() << endl;
    }
    else if (state == IN_GYM){
        cout << "inside Pokemon Gym " << current_gym -> GetId() << endl;
    }
    else if (state == IN_ARENA){
        cout << "inside Battle Arena " << current_arena -> GetId() << endl;
    }
    else if (state == FAINTED){
        cout << "fainted" << endl;
    }
    else if (state == TRAINING_IN_GYM){
        cout << " training in Pokemon Gym " << current_gym -> GetId() << endl;
    }
    
    else {//recovering stamina
        cout << " recovering stamina in Pokemon Center " << current_center -> GetId() << endl;
    }
    cout << "\tStamina: " << stamina << endl;
    cout << "\tPokemon Dollars: " << pokemon_dollars << endl;
    cout << "\tExperience Points: " << experience_points << endl;
    cout << "\tHealth: " << health << endl;
    cout << "\tPhysical Damage: " << physical_damage << endl;
    cout << "\tMagical Damage: " << magical_damage << endl;
    cout << "\tDefense: " << defense << endl;
}

bool Pokemon::Update(){
    if (state == STOPPED ){
        return false;
    }
    
    else if (state == MOVING){
        if (UpdateLocation() == true){//it will return true if arrived
            state = STOPPED;
            return true;
        }
        else
            return false;
    }
    else if (state == MOVING_TO_CENTER){
        if (UpdateLocation() == true) {
            state = IN_CENTER;
            return true;
        }
        else
            return false;
    }

    
        else if (state == MOVING_TO_GYM){
            if (UpdateLocation() == true){
                state = IN_GYM;
                return true;
            }
            else
                return false;
        }
        else if (state == IN_CENTER){
            return false;
        }
        else if (state == IN_GYM){
            //current_gym -> AddOnePokemon();
            return false;
        }
        else if (state == TRAINING_IN_GYM) {
            stamina -= current_gym -> GetStaminaCost(training_units_to_buy);
            pokemon_dollars -= current_gym -> GetDollarCost(training_units_to_buy);
            experience_points += current_gym -> TrainPokemon(training_units_to_buy);
            cout << "** " << name << " completed " << training_units_to_buy << " training unit(s)!**" << endl;
            cout << "** " << name << " gained " << experience_points << " experience point(s)!**" << endl;
            state = IN_GYM;
            return true;
        }
    
        else if (state == RECOVERING_STAMINA){
            stamina += current_center -> DistributeStamina(stamina_points_to_buy);
            pokemon_dollars -= current_center -> GetDollarCost(stamina_points_to_buy);
            cout << "** " << name << " recovered " << current_center -> DistributeStamina(stamina_points_to_buy) << " stamina point(s)!**" << endl;
            state = IN_CENTER;
            return true;
        }
    //pa4
        else if (state == FAINTED){
            return false;
        }
    
        else if (state ==  MOVING_TO_ARENA){
            if (UpdateLocation() == true){
                state = IN_ARENA;
                return true;
            }
            else {
                return false;
            }
        }
    
        else if (state == BATTLE){
            //decrease stamina per arena cost
            //decrease dollars per arena cost
            stamina -= current_arena -> GetStaminaCost();
            pokemon_dollars -= current_arena -> GetDollarCost();
            StartBattle();
            if (target -> get_health() <= 0){
                health = store_health;
                state = IN_ARENA;
                target -> IsAlive();
                current_arena -> RemoveRival();
                return true;
            }
            else {
                state = FAINTED;
                health = 0;
                target -> IsAlive();
                return true;
            }
        }
        else if (state == IN_ARENA){
            return false;
        }
        else {
            cout << "error" << endl;
            return false;
        }
}


bool Pokemon::UpdateLocation(){
//equation provided on instruction
    if (((fabs(destination.x - location.x) <=fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y)) || (destination.x == location.x && destination.y == location.y))){
        location = destination;
        cout << "Arrived" << endl;
        cout << display_code << id_num << ": I'm there!" << endl;
        
        if( state == MOVING_TO_CENTER){//if pokemon arrive center, add 1
            current_center -> AddOnePokemon();
            is_in_center = true;
        }
        
        else if (state == MOVING_TO_ARENA){
            current_arena -> AddOnePokemon();
            is_in_arena = true;
        }
        
        else if (state == MOVING_TO_GYM){//if pokemon arrive gym, add 1
            current_gym -> AddOnePokemon();
            is_in_gym = true;
        }

        return true;
    }
    else {
        location = location + delta;
        cout << "moved" << endl;
        cout << display_code << id_num << ": step..." << endl;
        
        if (is_in_center == true){//if pokemon leaves center, remove 1
            current_center -> RemoveOnePokemon();
            is_in_center = false;
        }
        
        if (is_in_gym == true){//if pokemon leaves gym, remove 1
            current_gym -> RemoveOnePokemon();
            is_in_gym = false;
        }
        
        if (is_in_arena == true){//if pokemon leaves arena, remove 1
            current_arena -> RemoveOnePokemon();
            is_in_arena = false;
        }
        
        if (stamina > 0){
            stamina -= 1; // for each steps
        }
        else
            stamina = 0;//stamina cannot go below 0
        pokemon_dollars += GetRandomAmountOfPokemonDollars(); //for each steps get some money
        return false;
    }
}

void Pokemon::SetupDestination(Point2D dest) {
    destination = dest;
    delta = (destination - location) * (speed / GetDistanceBetween(destination, location));
}

string Pokemon::getName(){
    return name;
}

double GetRandomAmountOfPokemonDollars(){
    return rand() % 21 * 0.1; //generate random amount of money
}

//pa4
bool Pokemon::IsAlive(){
    if (health == 0){
        state = FAINTED;
        return false;
    }
    else {
        return true;
    }
}

void Pokemon::TakeHit(double physical_damage, double magical_damage, double defense){
    int val = rand() % 100 + 1; //generate random number between 1-100
    double damage = 0;
    if (val % 2 == 0){
        damage = (100.0 - defense) / 100 * physical_damage;
        cout << "Physical damage hurts, Master!" << endl;
    }
    else {
        damage = (100.0 - defense) / 100 * magical_damage;
        cout << "It is magic, Master!" << endl;
    }
    health -= damage;
    cout << "Damage: " << damage << endl;
    cout << "Health: " << health << endl;
    cout << "*******" << endl;
    if (health <= 0){
        health = 0; //health will not go below 0
    }
}

void Pokemon::ReadyBattle(Rival* in_target){
    if (is_in_arena == false){
        cout << display_code << id_num << ": I can only fight in a Battle Arena!" <<endl;
    }
    else if (current_arena -> IsAbleToFight(pokemon_dollars, stamina) == false){
        cout << display_code << id_num << ": Not enough money or stamina!" << endl;
        state = IN_ARENA;
    }
    else if (current_arena -> IsBeaten() == true){
        cout << "This Arena has been beaten!" << endl;
        state = IN_ARENA;
    }
    else if (IsAlive() == false){
        cout <<display_code << id_num << ": I am fainted ..." << endl;
    }
    else if (in_target -> IsAlive() == false){
        cout << display_code << id_num << ": This rival is already dead" << endl;
    }
    else {
        target = in_target;
        state = BATTLE;
        cout <<"Getting ready for the battle" << endl;
    }
}

bool Pokemon::StartBattle(){
    while (health > 0 && target -> get_health() > 0){ //loop until health is 0
        TakeHit(target -> get_phys_dmg(), target -> get_magic_dmg(), target -> get_defense());//rival hits first
        target -> TakeHit(physical_damage, magical_damage, defense);
        if (health <= 0){//if health is equal or below 0, return true
            health = 0;
            cout << "Master I'm dead... Please press F to pay respect(JK)" << endl;
            return true;
        }
        else if (target -> get_health() <= 0){//if rival is dead
            cout << "Congrats Master, you defeated one rival!" << endl;
            return true;
        }
    }
    return false;
}

