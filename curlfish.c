/*
** 
*******************************************************************************
** PROGRAM:   curlfish - a program just about as simple as they come.        ** 
** AUTHOR:    Matt Livingston (blubrick@gmail.com)                           **
** PURPOSE:   Notifies the user that their script has CRLF line endings      **
** DATE:      05 October, 2018  (Originally sometime in 2001, I think)       **
**                                                                           **
** The name comes from an abreviation of, then an expansion of, "CRLF shell" **
** (CRLF SHELL -> crlfsh - > curlfish)                                       **
*******************************************************************************
** 
*/
#include <stdio.h>
int main (void)
{
    printf ("\n\nYour script contains DOS-style line endings\nPlease remedy the situation and try again\n\n");
    return 29;
}
