/*------------------------------------------------------------------------------------
FILE NAME:		   Stack.cpp

DESCRIPTION:	   Implementation file for the Stack class

USAGE:  	        		   

COMPILER:		   GNU g++ compiler on Linux

NOTES:             

MODIFICATION HISTORY:

Author				               Date			    Version
---------------                 ----------		 -------------
Conner Fissell		            02-14-2020		 1.0 - Set up class and Makefile.
Conner Fissell                  02-17-2020       1.1 - Fixed Makefile and #include situation 
------------------------------------------------------------------------------------*/
#ifndef __STACK_CPP__
#define __STACK_CPP__
#include "Stack.h"

/* -----------------------------------------------------------------------------
FUNCTION:           Stack<DT>::Stack()
DESCRIPTION:        Default Constructor       
RETURNS:           
NOTES:              Creates an empty stack             
------------------------------------------------------------------------------- */
template <class DT>
Stack<DT>::Stack()
{
    topPtr = nullptr;
}

/* -----------------------------------------------------------------------------
FUNCTION:           Stack<DT>::Stack(const Stack<DT> &stack2)          
DESCRIPTION:        Copy Constructor
RETURNS:           
NOTES:              initializes the stack to be equivalent to the other stack 
                    object parameter              
------------------------------------------------------------------------------- */
template <class DT>
Stack<DT>::Stack(const Stack<DT> &stackToCopy)
{
    Node<DT> *origChainPtr = stackToCopy.topPtr;                // Point to nodes in original chain
    
    if (origChainPtr == nullptr)
        topPtr = nullptr;

    else
    {
        topPtr = new Node<DT>;                                  // Copy first node
        topPtr->setItem(origChainPtr->getItem());
        Node<DT> *newChainPtr = topPtr;                         // Point to first node in new chain
        origChainPtr = origChainPtr->getNextItem();             // Adavance original chain pointer

        while (origChainPtr != nullptr)
        {
            DT nextItem = origChainPtr->getItem();              // Get next item from original chain
            Node<DT> *newNodePtr = new Node<DT> (nextItem);     // Create a new node containing next item (???)
            newChainPtr->setNextItem(newNodePtr);               // Link new node to end of new chain
            newChainPtr = newChainPtr->getNextItem();           // Advance pointer to new last node
            origChainPtr = origChainPtr->getNextItem();         // Advance original chain pointer
        }
    }
    


}

/* -----------------------------------------------------------------------------
FUNCTION:           Stack<DT>& Stack<DT>::operator = (const Stack<DT> &stack2)          
DESCRIPTION:        Overloaded Assignment Operator
RETURNS:           
NOTES:              Sets the stack to be eq to the other stack object parameter 
                    and returns a reference to the modified stack             
------------------------------------------------------------------------------- */
template <class DT>
Stack<DT>& Stack<DT>::operator = (const Stack<DT> &stack2)
{
    
}

/* -----------------------------------------------------------------------------
FUNCTION:           Stack<DT>::~Stack()          
DESCRIPTION:        Destructor
RETURNS:           
NOTES:              Deallocates the memory used to store the stack             
------------------------------------------------------------------------------- */
template <class DT> 
Stack<DT>::~Stack()
{
    Node<DT> *nodePtr;
    Node<DT> *nextNode;

    nodePtr = topPtr;                  // Position nodePtr at the top of the stack

    while (nodePtr != nullptr)         // Traverse the list, deleting each node 
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }


}

/* -----------------------------------------------------------------------------
FUNCTION:           void Stack<DT>::push(const DT &newDataItem)          
DESCRIPTION:        
RETURNS:           
NOTES:              Requirements: Stack is not full. Results: Inserts newDataItem 
                    onto the top of stack             
------------------------------------------------------------------------------- */
template <class DT> 
void Stack<DT>::push(const DT &newDataItem)
{
    Node<DT> *newNode = nullptr;                // Pointer to a new node
    newNode = new Node<DT>;                     // Alocate a new node an store newDataItem there
    newNode->item = newDataItem;

    if (isEmpty())                              // If there are no nodes in the Stack
    {
        topPtr = newNode;
        newNode->next = nullptr;
    }

    else                                        // Otherwise, insert newNode before top 
    {
        newNode->next = topPtr;
        topPtr = newNode;
    }
}

/* -----------------------------------------------------------------------------
FUNCTION:           DT Stack<DT>::peek()          
DESCRIPTION:       
RETURNS:           
NOTES:              Requirements: Stack is not empty. Results: Returns a copy of 
                    the value of the most recently added (top) data item from the stack
------------------------------------------------------------------------------- */
template <class DT>
DT Stack<DT>::peek()
{
    if (isEmpty())
        cout << "\nStack is Empty!\n\n";
    
        
    return topPtr->getItem();
    
}

/* -----------------------------------------------------------------------------
FUNCTION:           void Stack<DT>::pop()          
DESCRIPTION:       
RETURNS:           
NOTES:              Requirements: Stack is not empty Results: Removes the most 
                    recently added (top) data item from the stack
------------------------------------------------------------------------------- */
template <class DT>
void Stack<DT>::pop()
{   
    
    if (isEmpty())
        cout << "\nStack is Empty!\n\n";

    else
    {
        Node<DT> *nodeToDeletePtr = topPtr;
        topPtr = topPtr->getNextItem();
        nodeToDeletePtr->setNextItem(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

    }
    
}

/* -----------------------------------------------------------------------------
FUNCTION:           void Stack<DT>::clear()          
DESCRIPTION:       
RETURNS:           
NOTES:              Requirements: None. Results: Removes all the data 
                    items in the stack              
------------------------------------------------------------------------------- */
template <class DT> 
void Stack<DT>::clear()
{

}

/* -----------------------------------------------------------------------------
FUNCTION:           bool Stack<DT>::isEmpty() const          
DESCRIPTION:       
RETURNS:           
NOTES:              Requirements: None. Results: Returns true if the stack 
                    is empty, otherwise returns false              
------------------------------------------------------------------------------- */
template <class DT>
bool Stack<DT>::isEmpty() const
{
    return topPtr == nullptr;
}

/* -----------------------------------------------------------------------------
FUNCTION:           bool Stack<DT>::isFull() const          
DESCRIPTION:       
RETURNS:           
NOTES:              Requirements: None. Results: Returns true if the stack 
                    is full, otherwise returns false              
------------------------------------------------------------------------------- */
template <class DT>
bool Stack<DT>::isFull() const
{
    bool temp = false;
    
    return temp;
}



#endif