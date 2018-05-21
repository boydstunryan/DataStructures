//
//  BinarySearchTree.h
//  DataStructures
//
//  Created by Boydstun, Ryan on 3/29/18.
//  Copyright © 2018 Boydstun, Ryan. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

template <class Type>
bool BinarySearchTree<Type> :: contains(Type itemToFind)
{
    BinaryTreeNode<Type> * current = this->root;
    if(current == nullptr)
    {
        return false;
    }
    else
    {
        while(current != nullptr)
        {
            if(itemToFind == current->getData())
            {
                return true;
            }
            else if (itemToFind < current->getData())
            {
                current = current->getLeftNode();
            }
            else
            {
                current = current->getRightNode();
            }
        }
        return false;
    }
}

template <class Type>
void BinarySearchTree<Type> :: remove(Type getRidOfMe)
{
    if(this->root == nullptr)
    {
        cout << "Empty tree so removal is not possible" << endl;
    }
    else
    {
        BinaryTreeNode<Type> * current = this->root;
        BinaryTreeNode<Type> * previous = nullptr;
        bool hasBeenFound = false;
        
        while(current != nullptr && !hasBeenFound)
        {
            if(current->getData() == getRidOfMe)
            {
                hasBeenFound = true;
            }
            else
            {
                previous = current;
                if(getRidOfMe < current->getData())
                {
                    current = current->getLeftNode();
                }
                else
                {
                    current = current->getRightNode();
                }
            }
        }
        if(current == nullptr)
        {
            cerr << "item not found, removal unsuccessful" << endl;
        }
        else if(hasBeenFound)
        {
            if(current == this->root)
            {
                removeNode(this->root);
            }
            else if(getRidOfMe < previous->getData())
            {
                removeNode(previous->getLeftNode());
            }
            else
            {
                removeNode(previous->getRightNode());
            }
        }
    }
}

template <class Type>
void BinarySearchTree<Type> :: removeNode(BinaryTreeNode<Type> * removeMe)
{
    BinaryTreeNode<Type> * current;
    BinaryTreeNode<Type> * previous;
    BinaryTreeNode<Type> * temp;
    
    previous = removeMe->getRootNode();
    
    //Node is a leaf - has no kiddos
    else if(removeMe->getRightNode() == nullptr && removeMe->getLeftNode() == nullptr)
    {
        temp = removeMe;
        removeMe = nullptr;
        
        if(previous != nullptr && removeMe->getData() < previous->getData())
        {
            previous->setLeftNode(removeMe);
        }
        else if(previous != nullptr && removeMe->getData() > previous->getData())
        {
            previous->setRightNode(removeMe);
        }
        delete temp;
}
    //Node has only a left child
    else if(removeMe->getRightNode() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getLeftNode();
        
        if(previous != nullptr && temp->getData())
        {
            previous->setLeftNode(removeMe);
        }
        else if(previous != nullptr && temp->getData() > previous->getData())
        {
            previous->setRightNode(removeMe);
        }
        
        removeMe->setRootNode(previous);
        
        delete temp;
    }
    
    //Node has only a right child
    else if(removeMe->getRightNode() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getRightNode();
        if(previous != nullptr && removeMe->getData() < previous->getData())
        {
            previous->setLeftNode(removeMe);
        }
        else if(previous != nullptr && removeMe->getData() > previous->getData())
        {
            previous->setRightNode(removeMe);
        }
        removeMe->setRootNode(previous);
        delete temp;
    }
    
    //Node has both children
    else
    {
        current = getRightMostChild(removeMe->getLeftNode());
        
        previous = current->getRootNode();
        removeMe->setData(current->getData());
        
        if(previous == nullptr)//Removing from the root
        {
            removeMe->setLeftNode(current->getLeftNode());
        }
        else
        {
            previous->setRightNode(current->getLeftNode());
        }
        if(current->getLeftNode() != nullptr)
        {
            current->getLeftNode()->setRootNode(removeMe);
        }
        delete current;
    }
    if(removeMe == nullptr || removeMe->getRootNode() == nullptr)
    {
        this->root = removeMe;
    }

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getLeftMostChild(BinaryTreeNode<Type> * startingNode)
    {
        BinaryTreeNode<Type> * currentNode = startingNode;
        BinaryTreeNode<Type> * previous = nullptr;
        while (currentNode != nullptr)
        {
            previous = currentNode;
            currentNode = currentNode->getLeftNode();
        }
        
        return previous;
    }
    
    template <class Type>
    BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRightMostChild(BinaryTreeNode<Type> * startingNode)
    {
        BinaryTreeNode<Type> * currentNode = startingNode;
        BinaryTreeNode<Type> * previous = nullptr;
        while (currentNode != nullptr)
        {
            previous = currentNode;
            currentNode = currentNode->getRightNode();
        }
        
        return previous;
    }
    
    template <class Type>
    Type BinarySearchTree<Type> :: findMaximum()
    {
        assert(this->root != nullptr);
        return getRightMostChild(this->root)->getData();
    }
    
    
    template <class Type>
    Type BinarySearchTree<Type> :: findMinimum()
    {
        assert(this->root != nullptr);
        return getLefttMostChild(this->root)->getData();
    }
    
    void destroyTree(BinaryTreeNode<Type> * node)
    
    template <class Type>
    BinarySearchTree<Type> :: ~BinarySearchTree()
    {
        destroyTree(this->root);
    }
    
    template <class Type>
    void BinarySearchTree<Type> :: destroyTree(BinaryTreeNode<Type> * node)
    {
        if(node != nullptr)
        {
            destroyTree(node->getLeftNode());
            destroyTree(node->getRightNode());
            delete node;
        }
    }
#endif /* BinarySearchTree_h */
