//Listing 14.3 Using getchar function to input an entire line of text; page 331
//
// Other input functions are better-suited for this task however
//**************   original program from listing 14.3
#include <stdio.h>

#define MAX 80

int main(void)
{
    //MAX+1 so that you save space to put the null character \0
    char ch, buffer[MAX+1];
    int x = 0;

    printf("\nEnter a line of text to see how getchar() function works....\n\n");
    printf("\n\tEnter a line of text 80 characters or more to see");
    printf("\n\thow it prints more than one line. Try this with less");
    printf("\n\than 80 characters also. \n\n");


    //read from the screen and input the characters into the array buffer
    while((ch = getchar()) != '\n' && x< MAX)
        buffer[x++] = ch;

    //put null character at the end of the string
    buffer[x] = '\0';

    printf("\n%s\n", buffer);

    //the following is a test to see what happens if i enter over 80 characters
    //  on screen and then reset counter, unget the last character read, add more
    //  characters to the buffer, and reprint.
    //  This would seem to save it's place and print the next set of 80 characters.
    //  Interesting how getchar works - probably because it's a buffered input function,
    //  You could probably set this up inside another loop to just keep reading data
    //  Until there was no more input.  Maybe have inside loop going until 80 char
    //  reached and outside loop going until '\n' newline char? Try this below
    x = 0;
    //unread last char from input stream so you can reread and print again p335
    ungetc(ch, stdin);

    while((ch = getchar()) != '\n' && x< MAX)
        buffer[x++] = ch;

    //put null character at the end of the string
    buffer[x] = '\0';

    printf("\n%s\n", buffer);

    return 0;

}

//**************   enhanced program from listing 14.3 to loop through all input
//                 entered on screen no matter how many lines until the newline
//                 character ('\n') is encountered (ie. "enter" hit)
//
/*#include <stdio.h>

#define MAX 80

int main(void)
{
    char ch, buffer[MAX+1];
    // Be careful!!! I made a mistake using int x, y=0; and x was NOT initialized
    // It had random garbage in it and thus, my program never even entered the first
    // loop.  The only way I could see this was to use printf to see the values of
    // x and y because the debugger did not help. x had a value of 84756 for example,
    // and that's not a "bug". So, use printf to show variable values if you can't
    // figure something out.

    int x =0;

    printf("\nEnter a line of text to see how getchar() function works....\n\n");
    printf("\n\tEnter a line of text 80 characters or more to see");
    printf("\n\thow it prints more than one line. Try this with less");
    printf("\n\than 80 characters also. \n\n");

    //printf("\nx is %d, x);

    while(x<MAX && ch != '\n')
        {
        //printf("\nEntered loop1\n");
        while(x<MAX && (ch = getchar())!='\n')
            {
            //printf("\nEntered loop2");
            buffer[x++] = ch;
            }

        buffer[x] = '\0';
        printf("\n%s", buffer);

        x = 0;
        //ungets not necessary in loop situation
        //ungetc(ch, stdin);
        }
    puts("\n");
    return 0;

}
*/
