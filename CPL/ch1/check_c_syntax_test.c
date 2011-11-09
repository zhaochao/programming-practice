#include <stdio.h>

/* check a c program for rudimentary
   syntax error */

main()
{
	int c,c_next;			/* current and the next character input */
	int in_s_quote, in_d_quote;		/* flags for single and double quote */
	int n_bracket, n_brace, n_parenthese;	/* trace brackets, braces and parentheses */
	int in_comment;			/* flags for comments */
	/*int is_escape;*/			/* flags for escape */

	in_s_quote = in_d_quote = 0;
	n_bracket = n_brace = n_parenthese = 0;
	in_comment /*= is_escape*/ = 0;

	while ((c = getchar()) != EOF) {
		if ((in_s_quote || in_d_quote) && (c == '\\')) {
			/*
			if (is_escape)
				is_escape = 0;
			else
				is_escape = 1;
			*/
			c_next = getchar();
		}
		
		if ((!in_comment) && (!in_d_quote) && (c == '\'')/* && (!is_escape)*/) {
			if(in_s_quote)
				in_s_quote = 0;
			else
				in_s_quote = 1;
		}
		else if ((!in_comment) && (!in_s_quote) && (c == '"')/* && (!is_escape)*/) {
			if(in_d_quote)
				in_d_quote = 0;
			else
				in_d_quote = 1;
		}
		else if ((!in_comment) && (!in_s_quote) && (!in_d_quote)) {
			if(c == '[')
				n_bracket++;
			else if (c == ']')
				n_bracket--;
			else if (c == '{')
				n_brace++;
			else if (c == '}')
				n_brace--;
			else if (c == '(')
				n_parenthese++;
			else if (c == ')')
				n_parenthese--;
			else if (c == '/') {
				if ((c_next = getchar()) == '*')
					in_comment = 1;
			}
		}
		else if (in_comment) {
			if(c == '*') {
				if ((c_next = getchar()) == '/')
					in_comment = 0;
			}
		}
	}

	if (n_bracket > 0)
		printf("There are more \"[\" than \"]\".\n");
	else if (n_bracket < 0)
		printf("There are more \"]\" than \"[\".\n");

	if (n_brace > 0)
		printf("There are more \"{\" than \"}\".\n");
	else if (n_bracket < 0)
		printf("There are more \"}\" than \"{\".\n");

	if (n_parenthese > 0)
		printf("There are more \"(\" than \")\".\n");
	else if (n_bracket < 0)
		printf("There are more \")\" than \"(\".\n");

	if (in_s_quote)
		printf("single quotes are not closed.\n");
	
	if (in_d_quote)
		printf("double quotes are not closed.\n");
	
	if (in_comment)
		printf("comments are not closed.\n");
}
