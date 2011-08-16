#include <stdio.h>

/* print a histogram of frequencies of different characters in input */
#define CHAR_CAT 4 /* only calculate low, capital, digit, other characters */
#define CHAR_LOW 0 /* low character */
#define CHAR_CAP 1 /* capital character */
#define CHAR_DIGIT 2 /* digit character */
#define CHAR_OTHER 3 /* other character */
main()
{
    int c, n_char[CHAR_CAT], n_total;
    int index;
    int freq[CHAR_CAT], max_freq, this_freq;

    c = n_total = index = max_freq = this_freq = 0;
    for (index = 0; index < CHAR_CAT; index++) {
        n_char[index] = 0;
        freq[index] = 0;
    }
    
    while ((c = getchar()) != EOF) {
        ++n_total;
        if ((c >= 'a') && (c <= 'z'))
            ++n_char[CHAR_LOW];
        else if ((c >= 'A') && (c <= 'Z'))
            ++n_char[CHAR_CAP];
        else if ((c >= '0') && (c <= '9'))
            ++n_char[CHAR_DIGIT];
        else
            ++n_char[CHAR_OTHER];
    }

    for (index = 0; index < CHAR_CAT; index++) {
        freq[index] = (n_char[index] * 100) / n_total;
        if (max_freq < freq[index])
            max_freq = freq[index];
    }

    printf("Total character: %d.\n", n_total);
    printf("low character: %d. freq: %%%2d.\n", n_char[CHAR_LOW], freq[CHAR_LOW]);
    printf("captital character: %d. freq: %%%2d.\n", n_char[CHAR_CAP], freq[CHAR_CAP]);
    printf("digit character: %d. freq: %%%2d.\n", n_char[CHAR_DIGIT], freq[CHAR_DIGIT]);
    printf("other character: %d. freq: %%%2d.\n", n_char[CHAR_OTHER], freq[CHAR_OTHER]);

    printf("     |\n");
    /*
    for (this_freq = max_freq; this_freq > 0; this_freq--) {
        printf("%3d%% |", this_freq );
        for (index = 0; index < CHAR_CAT; index++) {
            if (freq[index] > this_freq)
                printf(" * * ");
            else if (freq[index] == this_freq)
                printf(" *** ");
            else
                printf("     ");
        }

        printf("\n");
    }
    */
    for (index = 0; index < CHAR_CAT; index++) {
        printf("     |");
        for (this_freq = 0; this_freq < freq[index]; this_freq++)
            printf("**");
        if (index == 0)
            printf("\n LOW |");
        else if (index == 1)
            printf("\n CAP |");
        else if (index == 2)
            printf("\nDIGIT|");
        else if (index == 3)
            printf("\nOTHER|");
        for ( this_freq = 0; this_freq < (freq[index] - 1); this_freq++)
            printf("  ");
        if (freq[index] > 0)
            printf(" *");
        printf("\n     |");
        for (this_freq = 0; this_freq < freq[index]; this_freq++)
            printf("**");
        printf("\n");
    }

    /*
    printf("     +");
    for (index = 0; index <= CHAR_CAT; index++)
        printf("-----");
    printf("\n       LOW  CAP DIGIT OTHER\n");
    */
    printf("     +");
    for (this_freq = 0; this_freq <= max_freq; this_freq++)
        printf("--");
    printf("\n      ");
    for (this_freq = 0; this_freq < max_freq; this_freq++)
        printf("%2d", (this_freq+1));
    printf("\n");
}
