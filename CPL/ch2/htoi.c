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

	for (;;i++) {
		if (s[i] >= '0' && s[i] <= '9')
			real_value = s[i] - '0';
		else if (s[i] >= 'A' && s[i] <= 'Z')
			real_value = s[i] - 'A';
		else if (s[i] >= 'a' && s[i] <= 'z')
			real_value = s[i] - 'a';

		n = n * 16 + real_value;
	}

	return n;
}

main()
{
	char s[] = "0xa12e";
	printf("%s is %d.\n", s, htoi(s));
}
