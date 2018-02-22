//
//  LinkedList.h
//  DataStructures
//
//  Created by Boydstun, Ryan on 2/20/18.
//  Copyright © 2018 Boydstun, Ryan. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include "LinkedList.hpp"

using namespace std; //USed for keyword access. Use this to make sure your pointers are pointing to the right things

template <class Type>
class Stack : public LinkedList<Type>
{
public:
    Stack();
    ~Stack();
    
    //Stack specific methods
    void push(Type data);
    Type pop();
    Type peek();
    
    //Overriden LinkedList methods
    void add(Type data);
    void addAtIndex(int index, Type data);
    Type getFromIndex(int index);
    Type remove(int index);
    
    template <class Type>
    Stack<Type> :: Stack() : LinkedList<Type>()
    {
        //Empty
    }
    
    template <class Type>
    Stack<Type> :: ~Stack()
    {
        while(this->size > 0)
        {
            pop();
        }
    }
    
    template <class Type>
    void Stack<Type> * add = new LinearNode<Type>(data);
    {
        LinearNode<Type> * add = new LinearNode<Type>(data);
        
        if(this->size == 0)
        {
            this->end = add;
        }
        else
        {
            add->setNextNode(this->front);
        }
        
        this->front = add;
        this->size++;
    }
    
    template <class Type>
    void Stack<Type> :: add(Type data)
    {
        push(data);
    }
    
    template <class Type>
    void Stack<Type> :: addAtIndex(int index, Type data)
    {
        assert(index == 0);
        push(data);
    }
    
    template <class Type>
    Type Stack<Type> :: pop()
    {
        assert (this->size > 0);
        Type removed = this->front->getData();
        
        LinearNode<Type> * removedNode = this->getFront();
        this->front = removedNode->getNextNode();
        delete removedNode;
        
        this->size--;
        
        return removed;
    }
    
    template <class Type>
    Type Stack<Type> :: remove(int index)
    {
        assert(index == 0)
        return pop();
    }
    
    template <class Type>
    Type Stack<Type> :: peek()
    {
        assert(this->size > 0);
        return this->getFront()->getData();
    }
    
    template <class Type>
    Type Stack<Type> :: getFromIndex(int index)
    {
        assert(index == 0);
        return peek();
    }
    
protected:

LinearNode<Type> * front;
LinearNode<Type> * end;

public:
//Constructors
LinkedList();
//Destructor
virtual ~LinkedList(); //Virtual so it can be overriden.
//Helper methods
int getSize() const;
LinearNode<Type> * getFront();
LinearNode<Type> * getEnd();

//Structure Methods
virtual void add(Type item);
virtual void addAtIndex(int index, Type item);
virtual Type getFromIndex(int index);
virtual Type remove(int index);
//Type setAtIndex(int index, Type item);
// bool contains(Type item);

LinkedList<Type> :: LinkedList()
{
    this->front = nullptr;
    this->end = nullptr;
    this->size = 0;
}

LinkedList<Type> :: ~LinkedList()
{
    LinearNode<Type> * destroyStructure = front;
    while (front != nullptr)
    {
        front = destroyStructure->getNextNode();
        delete destroyStructure;
        destroyStructure = front;
    }
}

void LinkedList<Type> :: add(Type item)
{
    LinearNode<Type> * newData = new LinearNode<Type>(item);
    
    if(this->size == 0)
    {
        this->front = newData;
    }
    else
    {
        this->end->setNextNode(newData);
    }
    
    this->end = newData;
    
    this->size += 1;
}

void LinkedList<Type> :: addAtIndex(int index, Type item)
{
    assert(index >= 0 && index <= this->size);
    if(index == this->size)
    {
        add(item);
    }
    else
    {
        LinearNode<Type> * toBeAdded = new LinearNode<Type>(item);
        if (index == 0)
        {
            toBeAdded->setNextNode(front);
            front = toBeAdded;
        }
        else
        {
            LinearNode<Type> * previous = nullptr;
            LinearNode<Type> * current = front;
            for (int position = 0; position < ex; position++ )
            {
                previous = current;
                current = current->getNextNode();
            }
            previous->setNextNode(toBeAdded);
            toBeAdded->setNextNode(current);
        }
        this->size++;
    }
}

Type LinkedList<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < this->size);
    Type data;
    
    LinearNode<Type> * current = front;
    
    for (int position = 0; position <index ; position++)
    {
        current = current-getNextNode();
    }
    
    data = current->getData();
    
    return data;
    }
}

Type LinkedList<type> :: remove(int index)
{
    assert(index >= 0 && index < this->size);
    
    LinearNode<Type> * current = front;
    LinearNode<Type> * toBeRemoved = nullptr;
    LinearNode<Type> * previous = nullptr;
    
    Type removedData;
    
    if (index == 0)
    {
        toBeRemoved = front;
        this->front = this->front->getNextNode();
    }
    else
    {
        for (int position = 0; position < index; position++)
        {
            previous = current;
            current = current->getNextNode();
        }
        
        toBeRemoved = current;
        
        if (index == this-> size - 1)
        {
            previous->setNextNode(nullptr);
            end = previous;
        }
        else
        {
            current = toBeRemoved->getNextNode();
            previous->setNextNode(current);
        }
    }
    this->size -= 1;
    
    removedData = toBeRemoved->getData();
    delete toBeRemoved;
    return removedData;
}

LinearNode<Type> * LinkedList<Type> :: getEnd()
{
    return this->end;
}

LinearNode<Type> * LinkedList<Type> :: getFront()
{
    return this->front;
}

int LinkedList<Type> :: getSize() const
{
    return this->size;
}

#ifndef LinkedList_hpp
#define LinkedList_hpp


#endif /* LinkedList_h */
