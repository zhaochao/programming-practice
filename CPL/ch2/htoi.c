#include <stdio.h>
#include <ctype.h>

/* htoi: convert s to integer */
int htoi(char s[])
{
	int i, n, real_value;
	n = 0;

	i = 0;
	if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
		i = 2;

	for (;s[i] != '\0' ;i++) {
		if (s[i] >= '0' && s[i] <= '9')
			n = n * 16 + s[i] - '0';
		else if (s[i] >= 'A' && s[i] <= 'F')
			n = n * 16 +  s[i] - 'A' + 10;
		else if (s[i] >= 'a' && s[i] <= 'f')
			n = n * 16 + s[i] - 'a' + 10;
	}

	return n;
}

main()
{
	char s[] = "0xa12e";
	printf("%s is %d.\n", s, htoi(s));
}
