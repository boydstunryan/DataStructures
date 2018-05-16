//
//  N_AryTreeNode.hpp
//  DataStructures
//
//  Created by Boydstun, Ryan on 4/23/18.
//  Copyright © 2018 Boydstun, Ryan. All rights reserved.
//

#ifndef N_AryTreeNode_h
#define N_AryTreeNode_h

#include <set>
#include "Node.hpp"
using namespace std;

template <class Type>
class N_AryTreeNode : public Node<Type>
{
private:
    set<N_AryTreeNode<Type>*> nodes;
    N_AryTreeNode<Type> * root;
    
public:
    N_AryTreeNode<Type>();
    ~N_AryTreeNode<Type>();
    N_AryTreeNode<Type>(Type data);
    
    set<N_AryTreeNode<Type>*> getNodes();
    N_AryTreeNode<Type> * getRoot();
    int getChildCount();
    
    void setRoot(N_AryTreeNode<Type> * root);
    void addChild(N_AryTreeNode<Type> * node);
};

template <class Type>
N_AryTreeNode<Type> :: N_AryTreeNode()
{ //Unused
}

template <class Type>
N_AryTreeNode<Type> :: N_AryTreeNode(Type data) : Node<Type>(data)
{
}

template <class Type>
N_AryTreeNode<Type> :: ~N_AryTreeNode()
{
    for (std::set<N_AryTreeNode<Type> *> iter = nodes.begin(); iter != nodes.end(); iter++)
    {
        nodes.erase(iter);
    }
}

template <class Type>
N_AryTreeNode<Type> * N_AryTreeNode<Type> :: getRoot()
{
    return root;
}

template <class Type>
set<N_AryTreeNode<Type>*> N_AryTreeNode<Type> :: getNodes()
{
    return nodes;
}

template <class Type>
int N_AryTreeNode<Type> :: setRoot(N_AryTreeNode<Type> * root)
{
    this->root = root;
}

template <class Type>
void N_AryTreeNode<Type> :: addChild(Type data)
{
    N_AryTreeNode<Type> * node = new N_AryTreeNode<Type>(data);
    nodes.insert(node);
}0
#endif /* N_AryTreeNode_h */
