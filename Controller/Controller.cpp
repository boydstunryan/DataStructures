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
    
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/cody.henrichson/Documents/Spring 2018 2420/DataStructures/DataStructure/Data/crime.csv");
    
    for (int index = 234; index < 400; index+= 30)
    {
        cout << index << " is " << myData[index] << endl;
    }
    codeTimer.stopTimer();
    codeTimer.displayInformation();
}

void Controller :: findMaxAndMin()
{
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/cody.henrichson/Documents/Spring 2018 2420/DataStructures/DataStructure/Data/crime.csv");
    
    int minIndex = 0;
    int maxIndex = 0;
    
    for (int index = 1; index < myData.size(); index++)
    {
        if (myData [minIndex] < myData [index])
        {
            minIndex = index;
        }
        
        if (myData [maxIndex] > myData[index])
        {
            maxIndex = index;
        }
    }
    searchTimer.stopTimer();
    cout << "The smallest Crime stat is at " << minIndex << " and it is: " << myData[minIndex] << endl;
    cout << "The largest Crime stat is at " << maxIndex << " and it is: " << myData[maxIndex] << endl;
    searchTimer.displayInformation();
}
