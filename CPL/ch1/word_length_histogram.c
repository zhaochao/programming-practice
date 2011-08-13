#include <stdio.h>

/* print histogram of lengths of words in input. */
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MAX_LENGTH 10 /* max length of words */

main()
{
    int c, this_word_length, state, index, this_count, max_count;
    int word_length[MAX_LENGTH + 1];

    state = OUT;
    this_word_length = index = this_count = max_count = 0;
    for (index = 0; index <= MAX_LENGTH; index++)
        word_length[index] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if ((state == IN) && (this_word_length <= 10)) {
                this_count = ++word_length[this_word_length - 1];
                if (this_count > max_count)
                    max_count = this_count;
            }
            else if (( state == IN) && (this_word_length > 10)) {
                this_count = ++word_length[MAX_LENGTH];
                if (this_count > max_count)
                    max_count = this_count;
            }

            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            this_word_length = 1;
        }
        else
            ++this_word_length;
    }

    for (index = 0; index < MAX_LENGTH; index++)
        printf("%d-character words: %d.\n", (index + 1), word_length[index]);
    printf("10-above-charater words: %d.\n", word_length[MAX_LENGTH]);
    printf("\nMax count: %d.\n\n", max_count);

    printf("     |\n");
    for (this_count = max_count; this_count > 0; this_count--) {
        printf("%4d |", this_count);
        for (index = 0; index <= MAX_LENGTH; index++) {
            if (word_length[index] > this_count)
                printf(" * * ");
            else if (word_length[index] == this_count)
                printf(" *** ");
            else
                printf("     ");
        }

        printf("\n");
    }

    printf("     +");
    for (index = 0; index <= MAX_LENGTH; index++)
        printf("-----");
    printf("\n      ");
    for (index = 0; index < MAX_LENGTH; index++)
        printf(" %2d  ", (index + 1));
    printf(" >%d  \n", MAX_LENGTH);
}
