//
//  main.cpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/1/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#include <iostream>
/*#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"*/
#include "View.h"
#include "GameCommand.h"
#include "Input_Handling.h"
using namespace std;

int main(){
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019" << endl;
    cout << "Programming Assignment 4" << endl;

    cout << "             _                             " << endl;
    cout << " _ __   ___ | | _____ _ __ ___   ___  _ __ " << endl;
    cout << "| '_ \\ / _ \\| |/ / _ \\ '_ ` _ \\ / _ \\| '_  \\" << endl;
    cout << "| |_) | (_) |   <  __/ | | | | | (_) | | | |" << endl;
    cout << "| .__/ \\___/|_|\\_\\___|_| |_| |_|\\___/|_| |_|" << endl;
    cout << "|_|                                         " << endl;
    cout << endl;

    Model m;
    View v;
    char command;
    int a, b, c;
    char in_char;
    m.ShowStatus();
    v.Clear();
    m.Display(v);
    
    cout << "Enter Command: ";
   
    cin >> command;
    while (command != 'q'){ // if user enters q, program exits
        
        try{
        switch (command) {
            case 'm':
                cin >> a >> b >> c;
                DoMoveCommand(m, a, Point2D(b, c));
                break;
                
            case 'g':
                cin >> a >> b;
                DoMoveToGymCommand(m, a, b);
                break;
                
            case 'c':
                cin >> a >> b;
                DoMoveToCenterCommand(m, a, b);
                break;
                
            case 'a':
                cin >> a >> b;
                DoMoveToArenaCommand(m, a, b);
                break;
                
            case 's':
                cin >> a;
                DoStopCommand(m, a);
                break;
                
            case 'r':
                cin >> a >> b;
                DoRecoverInCenterCommand(m, a, b);
                break;
                
            case 't':
                cin >> a >> b;
                DoTrainInGymCommand(m, a, b);
                break;
                
            case 'b':
                cin >> a >> b;
                DoBattleInArenaCommand(m, a, b);
                break;
                
            case 'v':
                DoGoCommand(m, v);
              
                break;
                
            case 'x':
                DoRunCommand(m, v);
            
                break;
                
            case 'n':
                cin >> in_char >> a >> b >> c;
                DoMakeNewObject(m, in_char, a, Point2D(b, c));
                
                break;
                
            default:
                break;
        }
        }
        catch(Invalid_Input& except){
            cout << "Invalid input - " << except.msg_ptr;
        }
        //m.ShowStatus();
        v.Clear();
        m.Display(v);
        cout << "Enter command: ";
        cin >> command;
    }
    
    return 0;
}
