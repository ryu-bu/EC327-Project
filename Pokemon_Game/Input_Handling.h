//
//  Input_Handling.h
//  PA3
//
//  Created by Ryuichi Ohhata on 12/11/19.
//  Copyright © 2019 Ryu. All rights reserved.
//

#ifndef Input_Handling_h
#define Input_Handling_h
#include <iostream>
#include <string>

class Invalid_Input {
public:
    Invalid_Input(string in_ptr) : msg_ptr (in_ptr) { }
    const string msg_ptr;
    
private:
    Invalid_Input();
};

#endif /* Input_Handling_h */
