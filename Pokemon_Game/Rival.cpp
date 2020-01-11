//
//  Rival.cpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/30/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#include "Rival.h"
Rival::Rival(string in_name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc) : GameObject(in_loc, id, 'R'){
    name = in_name;
    health = hp;
    physical_damage = phys_dmg;
    magical_damage = magic_dmg;
    defense = def;
    cout << "Rival constructed" << endl;
}

void Rival::TakeHit(double physical_damage, double magical_damage, double defense){
    int val = rand() % 100 + 1; //generate random number between 1-100
    double damage = 0;
    if (val % 2 == 0){
        damage = (100.0 - defense) / 100 * physical_damage;
        cout << "Aaagh, no physical pain no gain!" << endl;
    }
    else {
        damage = (100.0 - defense) / 100 * magical_damage;
        cout << "Ouch, I don't believe magic!" << endl;
    }
    health -= damage;
    cout << "Damagae: " << damage << endl;
    cout << "Health: " << health << endl;
    cout <<"*******" << endl;
    if (health <= 0){
        health = 0;
    }
}

double Rival::get_phys_dmg(){
    return physical_damage;
}

double Rival::get_magic_dmg(){
    return magical_damage;
}

double Rival::get_defense(){
    return defense;
}

double Rival::get_health(){
    return health;
}

bool Rival::Update(){
    state = ALIVE_RIVAL;
    if (IsAlive() == false && state != FAINTED_RIVAL){
        state = FAINTED_RIVAL;
        return true;
    }
    return false;
}

void Rival::ShowStatus(){
    cout << name << " status: ";
    GameObject::ShowStatus();
    if(state == ALIVE_RIVAL){
        cout << "alive" << endl;
    }
    else {
        cout << "fainted" << endl;
    }
    cout << "\tHealth: " << health << endl;
    cout << "\tPhysical Damage: " << physical_damage << endl;
    cout << "\tMagical Damage: " << magical_damage << endl;
    cout << "\tDefense: " << defense << endl;
}

bool Rival::ShouldBeVisible(){
    if (IsAlive() == true){
        return true;
    }
    else {
        return false;
    }
}

bool Rival::IsAlive(){
    if (health <= 0){
        return false;
    }
    else {
        return true;
    }
}
