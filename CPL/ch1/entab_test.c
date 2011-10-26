#include <stdio.h>

/* replace blanks in the input  with minimum number of tabs
 * and spaces to achieving same spacing */
#define MAXLINE 1000        /* max length of lines in input */
#define TAB_STOPS 4         /* fixed set of tab stops */

int my_getline(char line[], int maxline);

main()
{
    int i;                  /* tempary index for loops */
    int i_idx, o_idx;       /* index number of input line and out line */
    int spacecount;         /* how many continus spaces */ 
    int o_spaces, o_tabs;   /* how many spaces and tabs should be printed */
    char line[MAXLINE];     /* current input line */
    int len;                /* length of current input line */

    o_idx=spacecount = 0;

    while ((len = my_getline(line, MAXLINE)) > 0 ) {
        for (i_idx = 0; i_idx < len; i_idx++) {
            if (line[i_idx] == ' ')
                spacecount++;
            else if (spacecount == 0) {
                putchar(line[i_idx]);
				if (line[i_idx] != '\t')
					o_idx++;
				else
					/*o_idx = (o_idx / TAB_STOPS + 1) * TAB_STOPS;*/
					o_idx += TAB_STOPS - (o_idx % TAB_STOPS);
                spacecount = 0;
            }
            else if (spacecount == 1) {
                putchar(' ');
                putchar(line[i_idx]);
                o_idx += 2;
                spacecount = 0;
            }
            else {
                o_spaces = (o_idx + spacecount) % TAB_STOPS;
                o_tabs = (o_idx + spacecount) / TAB_STOPS - o_idx / TAB_STOPS;

                /*
                for(i = 1; i <= o_spaces; i++) {
                    putchar(' ');
                    o_idx++;
                }
                for(i = 1; i <= o_tabs; i++) {
                    putchar('\t');
                    o_idx++;
                }
                */
                /*while(o_spaces > 0 || o_tabs > 0) {*/
                /*while((o_spaces + o_tabs) > 0) {
                    if ((o_idx % TAB_STOPS) == 0) {
                        if (o_tabs > 0) {
                            putchar('\t');
                            o_tabs--;
							o_idx += TAB_STOPS - (o_idx % TAB_STOPS);
                        }
						else if (o_spaces > 0) {
							putchar(' ');
							o_spaces--;
							o_idx++;
						}
                    }
                    else {
                        if (o_spaces > 0) {
                            putchar(' ');
                            o_spaces--;
                            o_idx++;
                        }
						else if (o_tabs > 0) {
                            putchar('\t');
                            o_tabs--;
							o_idx += TAB_STOPS - (o_idx % TAB_STOPS);
                        }
                    }
                }*/

				for (i = 1; i <= o_tabs; i++) {
					putchar('\t');
					o_idx += TAB_STOPS - (o_idx % TAB_STOPS);
				}

				for (i = 1; i <= o_spaces; i++) {
					putchar(' ');
					o_idx++;
				}

                putchar(line[i_idx]);
				if (line[i_idx] != '\t')
					o_idx++;
				else
					o_idx += TAB_STOPS - (o_idx % TAB_STOPS);

                spacecount = 0;
            }
        }
    }

    return 0;
}


/* my_getline: read a line int s, return length */
int my_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
