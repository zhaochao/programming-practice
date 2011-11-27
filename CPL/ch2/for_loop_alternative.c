#include <stdio.h>

/* rewrite the loop in the getline()
   function without "&&" or "||". */

#define MAXLINE 1000
int my_getline(char line[], int maxline); 

main()
{
	int len;	/* current line length */
	char line[MAXLINE];		/* current input line */

	while ((len = my_getline(line, MAXLINE)) > 0)
		printf("%4d: %s", len - 1, line);

	return 0;
}

int my_getline(char s[], int lim)
{
	int c, i;
	/* original implement */
	/*
	for (i = 0; i < MAXLINE -1 && (c = getchar()) ! = EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	*/
	i = 0;
	while (i < lim -1) {
		c = getchar();

		if (c == EOF)
			break;
		else if (c == '\n') {
			s[i++] = c;
			break;
		}
		
		s[i++] = c;
	}

	s[i] = '\0';
	
	return i;
}
