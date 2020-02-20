/*------------------------------------------------------------------------------------
FILE NAME:		   Node.h

DESCRIPTION:	   Specification file for the Node class

USAGE:  	        		   

COMPILER:		   GNU g++ compiler on Linux

NOTES:             

MODIFICATION HISTORY:

Author				               Date			    Version
---------------                 ----------		 -------------
Conner Fissell		            02-13-2020		 1.0 - Set up class and Makefile.
Conner Fissell                  02-17-2020       1.1 - Fixed Makefile and #include situation 
------------------------------------------------------------------------------------*/
#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <string>
using namespace std;


template <class DT>
class Node
{
    public: 
        DT item;                // Data item in node
        Node<DT> *next;         // Pointer to the next node
    
    
        Node();                                                         // Default Constructor
        Node(const DT &anItem);
        Node(const DT &anItem, Node<DT> *nextNodePtr);
        void setItem(const DT &anItem);
        void setNextItem(Node<DT> *nextNodePtr);
        DT getItem() const;
        Node<DT> *getNextItem() const;

};


const char PROGRAMMER_NAME[] = "Conner Fissell";


#include "Node.cpp"

#endif