//
//  Building.cpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/4/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#include "Building.h"

using namespace std;

Building::Building () : GameObject('B'){
    cout <<"Building default constructed" << endl;
}
Building::Building(char in_code, int in_Id, Point2D in_loc) : GameObject(in_loc, in_Id, in_code){
    cout << "Building constructed" << endl;

}

void Building::AddOnePokemon(){
    pokemon_count++;
}

void Building::RemoveOnePokemon(){
    pokemon_count--;
}

void Building::ShowStatus(){
    cout << display_code  << id_num << " located at " << location << endl;
    cout << "\t" << pokemon_count << " pokemon ";
    if (pokemon_count > 1){
        cout << "are in this building" << endl;
    }
    else {
        cout << "is in this building" << endl;
    }
}

bool Building::ShouldBeVisible(){//building should be always visible
    return true;
}
