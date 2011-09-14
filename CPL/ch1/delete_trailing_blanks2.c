#include <stdio.h>
#include <stdlib.h>

/* delete trailing blanks or tabs of each line, 
 * and completely blank lines of input */

#define MAXQUEUE 1001       /* max sequence of blanks */

/* advance: increasing the index of the array storing blanks */
int advance(int pointer)
{
    if (pointer < (MAXQUEUE - 1))
        return (pointer + 1);
    else
        return 0;
}

int main(void)
{
    char blank[MAXQUEUE];
    int head, tail;     /* temp index of blank array */
    int nonspace;       /* trailing blanks or not */
    int retval;         /* returning value of this program */
    int c;              /* storing character just input */
    int spaceJustPrinted;       /* boolean: was the last character printed blank */

    retval = nonspace = head = tail = spaceJustPrinted = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            head = tail = 0;
            if (spaceJustPrinted == 1)  /* if some trailing whitespace was printed... */
                retval = EXIT_FAILURE;

            if (nonspace)
                putchar('\n');
            spaceJustPrinted = 0;
            nonspace = 0;
        }
        else if ((c == ' ') || (c == '\t')) {
            if (advance(head) == tail) {
                putchar(blank[tail]);
                spaceJustPrinted = 1;
                tail = advance(tail);
                nonspace = 1;
                retval = EXIT_FAILURE;
            }

            blank[head] = c;
            head = advance(head);
        }
        else {
            while (head != tail) {
                putchar(blank[tail]);
                tail = advance(tail);
            }
            putchar(c);
            spaceJustPrinted = 0;
            nonspace = 1;
        }
    }

    if (spaceJustPrinted == 1)
        retval = EXIT_FAILURE;

    return retval;
}
