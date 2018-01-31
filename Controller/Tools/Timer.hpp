//
//  Timer.hpp
//  DataStructures
//
//  Created by Boydstun, Ryan on 1/31/18.
//  Copyright © 2018 Boydstun, Ryan. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include <time.h>
#include <assert.h>
#include <iostream>

#include <stdio.h>

#endif /* Timer_hpp */

class Timer
{
private:
    clock_t executionTime;
    
public:
    Timer();
    void startTimer();
    void stopTimer();
    void resetTimer();
    void displayInformation();
    long getTimeInMicroseconds();
};
