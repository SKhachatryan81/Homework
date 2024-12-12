#include <stdio.h>


int main() {
	int i, c, j, newc, neww;
	int s[100];

	for (i = 0; i < 100; i++)
	{
		s[i] = 0;
	}

	neww = newc = 0;

	while ((c = getchar()) != EOF) {
			++newc;
		if (c == ' ' || c == '\n' || c == '\t') {
			s[neww] = newc - 1;

			++neww;
			newc = 0;

		}

	}

	// horizonal
	for (i = 0; i < neww; i++)
	{
		for (j = 0; j < s[i]; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//vertical
	// for (i = 1; i <= 100; ++i) {
	// 	for (j = 0; j <= neww; ++j) {
	// 		if (i <= s[j])
	// 			putchar('*');
	// 		else
	// 			putchar(' ');
	// 	}
	// 	putchar('\n');
	// }

	return 0;

}