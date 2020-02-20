/*------------------------------------------------------------------------------------
FILE NAME:		   Stack.cpp

DESCRIPTION:	   Specification file for the Stack class

USAGE:			   

COMPILER:		   GNU g++ compiler on Linux

NOTES:              

MODIFICATION HISTORY:

Author				              Date			   Version
---------------                 ----------		-------------
Conner Fissell		            02-14-2020		1.0 - Started building basic outline
Conner Fissell                  02-17-2020      1.1 - Fixed Makefile and #include situation 
------------------------------------------------------------------------------------*/
#ifndef __STACK_H__
#define __STACK_H__
#include "Node.h"


template <class DT>
class Stack
{
    private:
        Node<DT> *topPtr;                                   // Pointer to the stack top
        Node<DT> *headPtr;                                  // Pointer to the first node
    public:
        Stack();                                            // Default Constructor, Creates an empty stack  
        Stack(const Stack<DT> &stack2);                     // Copy Constructor 
        Stack<DT>& operator = (const Stack<DT> &stack2);    
        ~Stack();                                           // Destructor Deallocates the memory used to store the stack
        void push(const DT &newDataItem);                   
        DT peek();                                          
        void pop();                                         
        void clear();                                       
        bool isEmpty() const;                               
        bool isFull() const;                                
                                                            
            
        

};


#include "Stack.cpp"

#endif


