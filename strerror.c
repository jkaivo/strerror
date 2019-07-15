#define _XOPEN_SOURCE 700
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "strerror.h"

const char *errname(int err)
{
	if (err < sizeof(errlist) / sizeof(errlist[0]) && errlist[err]) {
		return errlist[err];
	}
	return "-";
}

int main(int argc, char *argv[])
{
	int n = 1;

	if (argc < 2) {
		printf("Usage: %s errno...\n", argv[0]);
		return 1;
	}

	do {
		int err = atoi(argv[n]);
		printf("%d: %s [%s]\n", err, strerror(err), errname(err));
	} while (argv[++n]);

	return 0;
}
