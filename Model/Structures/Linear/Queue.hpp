//
//  Queue.hpp
//  DataStructures
//
//  Created by Boydstun, Ryan on 2/28/18.
//  Copyright © 2018 Boydstun, Ryan. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include "LinkedList.hpp"

#include <iostream>
using namespace std;

template <class Type>
class Queue : public LinkedList<Type>

public:
Queue();
~Queue();

//Queue methods
void enqeue(Type data);
Type dequeue();
Type peek();
void clear();

//Overridden LinkedList methods
void add(Type data);
void addAtIndex(int index, Type data);
Type getFromIndex(int index);
Type remove(int index);

template <class Type>
Queue<Type> :: Queuee() : LinkedList<Type>()
{
    //Empty since it is handled by the parent class constructor.
}

template <class Type>
Queue<Type> :: ~Queue()
{
    for(LinearNode<Type> * removed = this->front; removed != nullptr; removed = this->front)
    {
        this->front = removed->getNextNode();
        delete removed;
    }
}

template <class Type>
void Queue<Type> :: enqueue(Type item)
{
    LinearNode<Type> * added = new LinearNode<Type>(item);
    
    if(this->size == 0)
    {
        this->front = added;
    }
    else
    {
        this->end->setNextNode(added)
    }
    
    this->end = added;
    this->size++;
}

template <class Type>
void Queue<Type> :: addAtIndex(int index, Type item)
{
    assert(index == this->size);
    enqueue(item);
}

template <class Type>
void Queue<Type> :: add(Type item)
{
    enqueue(item);
}

template <class Type>
Type Qu

#endif /* Queue_h */
