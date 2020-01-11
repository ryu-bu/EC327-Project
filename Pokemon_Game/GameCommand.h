//
//  GameCommand.hpp
//  PA3
//
//  Created by Ryuichi Ohhata on 11/20/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#ifndef GameCommand_h
#define GameCommand_h

#include <stdio.h>
#include "Model.h"
#include "View.h"
#include "Input_Handling.h"
#include "Point2D.h"

void DoMoveCommand(Model&, int, Point2D);
void DoMoveToCenterCommand(Model&, int, int);
void DoMoveToGymCommand(Model&, int, int);
void DoMoveToArenaCommand(Model&, int, int);
void DoStopCommand(Model&, int);
void DoTrainInGymCommand(Model&, int, unsigned int);
void DoRecoverInCenterCommand(Model&, int, unsigned int);
void DoBattleInArenaCommand(Model&, int, int);
void DoGoCommand(Model&, View&);
void DoRunCommand(Model&, View&);
void DoMakeNewObject(Model&, char, int, Point2D);

#endif /* GameCommand_h */

