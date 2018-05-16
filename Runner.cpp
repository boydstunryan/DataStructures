//
//  Runner.cpp
//  DataStructures
//
//  Created by Boydstun, Ryan on 1/31/18.
//  Copyright © 2018 Boydstun, Ryan. All rights reserved.
//

#include "Controller/Controller.hpp"
using namespace std;
int main()
{
    int sample = 7;
    string word = "asda";
    string word2 = "asda";
    string word3 = "asdadadada";
    cout << &sample << endl;
    cout << &word << endl;
    cout << &word2 << endl;
    cout << &word3 << endl;
    unsigned long address = (unsigned long) &sample;
    
    unsigned long * storage ;
    storage = new unsigned long [0xffffffffff];
    storage[address] = 0;
    
    cout << address << endl;
    if (0x7fff5fbff618 == address)
    {
        cout << "the same" << endl;
    }
    
    //Controller app;
    //app.start()
    return 0;
}
