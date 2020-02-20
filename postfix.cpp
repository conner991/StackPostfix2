/*------------------------------------------------------------------------------------
FILE NAME:		   postfix.cpp

DESCRIPTION:	   Driver file for the Node and Stack classes

USAGE:  	        		   

COMPILER:		   GNU g++ compiler on Linux

NOTES:             

MODIFICATION HISTORY:

Author				               Date			       Version
---------------                 ----------		    -------------
Conner Fissell		            02-13-2020		    1.0 - Set up class and Makefile.
Conner Fissell                  02-18-2020          1.1 - Started building infix to postfix
                                                          converter.                                             
------------------------------------------------------------------------------------*/
#include "Stack.h"

// Macros
#define MAX_SIZE 25

//Prototypes
string inToPost(string &infix);

/* -----------------------------------------------------------------------------
FUNCTION:           int main()
DESCRIPTION:              
RETURNS:            0           
NOTES:                          
------------------------------------------------------------------------------- */
int main()
{   
    string infix, postfix;

    cout << "\nPlease enter infix expression:\n";
    getline(cin, infix);

    cout << "\nUser entered: " << infix << endl << endl;

    postfix = inToPost(infix);

    cout << "Postfix expression: " << postfix << endl;





    cout << "\n\nProgrammed by " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << "  " <<  __TIME__<< endl << endl;

    return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:              
RETURNS:                       
NOTES:                          
------------------------------------------------------------------------------- */
string inToPost(string &infixExp)
{
    Stack<char> opStack;
    string postFix;

    

    for (int i = 0; i < infixExp.length(); i++)     // 2+3*5/9
    {   
        if (isdigit(infixExp[i]))
        {
            postFix += infixExp[i];
        }

        else 
        {   
            if (!opStack.isEmpty())
            {
                if (infixExp[i] == '^')             // Compare between stack top value and operator use peek
                {
                    postFix += opStack.peek();
                    opStack.pop();
                }

                else if (infixExp[i] == ('/' || '*'))
                {
                    if (opStack.peek() == ('+' || '-'))
                    {
                        opStack.push(infixExp[i]);
                    }

                    else
                    {
                        postFix += opStack.peek();
                        opStack.pop();
                    }


                }

                else
                {
                    
                }
                

            }

            opStack.push(infixExp[i]);
        }
    }

    while (!opStack.isEmpty())
    {   
    
        postFix += opStack.peek();
        opStack.pop();
        
    }

    
    return postFix;
}

