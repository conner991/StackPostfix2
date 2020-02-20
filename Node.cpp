/*------------------------------------------------------------------------------------
FILE NAME:		   Node.cpp

DESCRIPTION:	   Implementation file for the Node class

USAGE:			   

COMPILER:		   GNU g++ compiler on Linux

NOTES:              

MODIFICATION HISTORY:

Author				              Date			   Version
---------------                 ----------		-------------
Conner Fissell		            02-08-2020		1.0 - Started building basic outline 
Conner Fissell                  02-09-2020      1.1 - Added member functions 
Conner Fissell                  02-10-2020      1.2 - Cont. adding member functions
Conner Fissell                  02-14-2020      1.3 - Updated template/class names
Conner Fissell                  02-17-2020      1.4 - Fixed Makefile and #include situation
------------------------------------------------------------------------------------*/
#ifndef __NODE_CPP__
#define __NODE_CPP__

#include "Node.h"

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Constructor for ListNode class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
Node<DT>::Node()
{
    next = nullptr;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Constructor for ListNode class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
Node<DT>::Node(const DT &anItem)
{
    item = anItem;
    next = nullptr;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Constructor for LinkList class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
Node<DT>::Node(const DT &anItem, Node<DT> *nextNodePtr)
{
    item = anItem;
    next = nextNodePtr;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Constructor for LinkList class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
void Node<DT>::setItem(const DT &anItem)
{
    item = anItem;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Constructor for LinkList class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
void Node<DT>::setNextItem(Node<DT> *nextNodePtr)
{
    next = nextNodePtr;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Constructor for LinkList class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
DT Node<DT>::getItem() const
{
    return item;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       Constructor for LinkList class
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
template <class DT>
Node<DT> *Node<DT>::getNextItem() const
{
    return next;
}


#endif