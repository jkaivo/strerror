.POSIX:

strerror: strerror.c strerror.h
	$(CC) $(CFLAGS) -o $@ strerror.c

strerror.h: errlist Makefile
	printf '#ifndef STRERROR_H\n#define STRERROR_H 1\n\n' > $@
	printf '#include <errno.h>\n\n' >> $@
	printf 'const char *errlist[] = {\n' >> $@
	awk '{printf("#ifdef %s\n\t[%s] = \"%s\",\n#endif\n", $$0, $$0, $$0);}' errlist >> $@
	printf '};\n\n#endif\n' >> $@

clean:
	rm -f strerror *.o
