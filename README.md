# strerror
describe system errors based on their numeric values

# compilation
`make`

# use
`strerror errno...`

For example:

```
$ ./strerror 1
1: Operation not permitted [EPERM]
```

# hacking
The file `errlist` contains a list of symbolic constants (AKA C macros) that
can be expected to be found in `<errno.h>` on POSIX systems. Constants are
listed one per line. A one-line AWK command transforms this into the bulk
of `strerror.h`, along with some `printf` calls in `Makefile`.

To add more errors (for instance, GNU or Linux specific stuff that doesn't
exist in POSIX), just add them, one per line, to `errlist` and re-run `make`.
Every constant (and I mean every, even standard C constants like `ERANGE` and
`EDOM`) is only included in the list if it is defined, so there are no
portability concerns with adding macros that don't exist.

There is a problem with adding constants that expand to identical values,
though, so don't do that.
