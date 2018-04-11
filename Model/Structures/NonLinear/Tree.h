//
//  Tree.h
//  DataStructures
//
//  Created by Boydstun, Ryan on 3/29/18.
//  Copyright © 2018 Boydstun, Ryan. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include "../../Nodes/BinaryTreeNode.hpp"
template <class Type>
class Tree
{
protected:
    BinaryTreeNode<Type> * root;
public:
    //informational methods
    virtual int getSize() = 0;
    virtual int getHeight() = 0;
    virtual bool isComplete() = 0;
    virtual bool isBalanced() = 0;
    //*data methods*
    virtual void insert (Type data) = 0;
    virtual bool contains(Type data) = 0;
    virtual void remove(Type data) = 0;
    //*Traversal*
    virtual void inOrderTraversal() = 0;
}

#endif /* Tree_h */
