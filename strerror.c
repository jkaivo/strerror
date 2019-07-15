#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n = 1;

	if (argc < 2) {
		printf("Usage: %s errno...\n", argv[0]);
		return 1;
	}

	do {
		int err = atoi(argv[n]);
		printf("%d: %s\n", err, strerror(err));
	} while (argv[++n]);

	return 0;
}
