//
//  LinearNode.h
//  DataStructures
//
//  Created by Boydstun, Ryan on 5/31/18.
//  Copyright © 2018 Boydstun, Ryan. All rights reserved.
//

#include <assert.h>
#include "../../Nodes/LinearNode.hpp"

#ifndef LinearNode_h
#define LinearNode_h

protected:
int size;

//Structure
virtual void add(Type item) = 0;
virtual void addAtIndex(int index, Type item) = 0;
virtual Type remove(int index, Type item) = 0;
virtual Type getFromIndex(int index) = 0;
//Helper
virtual int getSize() const = 0;
virtual LinearNode<Type> * getFront() = 0;
virtual LinearNode<Type> * getEnd() = 0;

#endif /* LinearNode_h */
