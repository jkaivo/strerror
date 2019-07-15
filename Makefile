strerror: strerror.c strerror.h
	$(CC) $(CFLAGS) -o $@ strerror.c

strerror.h: errlist Makefile
	printf '#ifndef STRERROR_H\n#define STRERROR_H 1\n\n' > $@
	printf 'struct { int number; char *name; } errlist[] = {\n' >> $@
	awk '{printf("#ifdef %s\n\t{ %s,\t\"%s\" },\n#endif\n", $$0, $$0, $$0);}' errlist >> $@
	printf '};\n\n#endif\n' >> $@
