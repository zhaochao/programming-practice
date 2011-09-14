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

    retval = nonspace = head = tail = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            head = tail = 0;
            if (nonspace)
                putchar('\n');
            nonspace = 0;
        }
        else if ((c == ' ') || (c == '\t')) {
            if (advance(head) == tail) {
                putchar(blank[tail]);
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
            nonspace = 1;
        }
    }

    return retval;
}
