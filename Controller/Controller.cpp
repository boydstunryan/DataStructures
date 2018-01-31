//
//  Controller.cpp
//  DataStructures
//
//  Created by Boydstun, Ryan on 1/31/18.
//  Copyright © 2018 Boydstun, Ryan. All rights reserved.
//

#include "Controller.hpp"

using namespace std;

void Controller :: start()
{
    cout << "Testing the timer class" << endl;
    Timer codeTimer;
    codeTimer.startTimer();
    cout << "Print to the screen some text" << endl;
    codeTimer.stopTimer();
    codeTimer.displayInformation();
    
    codeTimer.resetTimer();
    codeTimer.startTimer();
    for (int index = 0; index < 10000; index++)
    {
        cout < "The index  " << index << "\t";
    }
    codeTimer.stopTimer();
    codeTimer.displayInformation();
}
