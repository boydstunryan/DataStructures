//
//  SortingTester.h
//  DataStructures
//
//  Created by Boydstun, Ryan on 3/15/18.
//  Copyright © 2018 Boydstun, Ryan. All rights reserved.
//

#ifndef SortingTester_hpp
#define SortingTester_hpp

#include <iostream>
#include "../Controller/FileController.hpp"
#include "../Controller/Tools/Timer.hpp"

class SortingTester
{
private:
    void quickSort(vector<CrimeData> data, int low, int high);
    int partition(vector<CrimeData> data, int low, int high);
}

#endif /* SortingTester_h */
