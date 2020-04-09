#define _XOPEN_SOURCE 700
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#include "strerror.h"

const char *errname(int err)
{
	if (err < sizeof(errlist) / sizeof(errlist[0]) && errlist[err]) {
		return errlist[err];
	}
	return "-";
}

int errnum(const char *name)
{
	for (int i = 0; i < sizeof(errlist) / sizeof(errlist[0]); i++) {
		if (errlist[i] && !strcasecmp(name, errlist[i])) {
			return i;
		}
	}
	return -1;
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");

	int n = 1;

	if (argc < 2) {
		printf("Usage: %s errno...\n", argv[0]);
		return 1;
	}

	do {
		int err = -1;
		if (toupper(argv[n][0]) == 'E') {
			err = errnum(argv[n]);
		} else {
			err = atoi(argv[n]);
		}

		if (err == -1) {
			fprintf(stderr, "%s: %s: unknown error code\n", argv[0], argv[n]);
		} else {
			printf("%d: %s [%s]\n", err, strerror(err), errname(err));
		}
	} while (argv[++n]);

	return 0;
}
