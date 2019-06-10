/*
** 
********************************************************************************
** PROGRAM:   curlfish - a program just about as simple as they come.         ** 
** AUTHOR:    Matt Livingston (blubrick@gmail.com)                            **
** PURPOSE:   Notifies the user that their script has CRLF line endings       **
** DATE:      05 October, 2018  (Originally sometime in 2001, I think)        **
**                                                                            **
** The name comes from an abbreviation of, then an expansion of, "CRLF shell" **
** (CRLF SHELL -> crlfsh - > curlfish)                                        **
********************************************************************************
** 
*/
#include <stdio.h>
int main (int argc, char *argv[])
{
    /********************************/
    /* Try to work out if we are    */
    /* being invoked via a script's */
    /* "shebang" (#!) line.  If so, */
    /* then we print a message to   */
    /* state the script is b0rked.  */
    /********************************/

    if (argc > 1) {  
        printf ("\n\nYour script \"%s\" contains DOS-style line endings\n", argv[1]);
        printf("Please remedy the situation and try again\n\n");
        return 29;
    } 
    /**********************************/
    /* Otherwise, we have been called */
    /* directly. That is almost NEVER */
    /* what the user wants!           */
    /**********************************/
    printf ("\n%s is not the shell you are looking for. See the manpage for curlfish(1) for more details.\n", argv[0]);
    return 1;
}
