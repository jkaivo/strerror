# strerror

translate error numbers to strings or identifiers

## Synopsis
`strerror errno...`

## Description

The `strerror` utility translates error numbers to strings (via the C
function `strerror()`. If the number matches a symbolic constant defined in
the header `<errno.h>`, `strerror` will also provide that name.

## Operands

The `strerror` utility supports the following operands:

`errno`	A numeric error number, typically obtained from the value of the C
	identifier `errno`.

## STDIN

Not used.

## Input Files

None.

## STDOUT

The `strerror` utility writes the translation of each operand, one per line,
in the following format:

`"%d: %s [%s]\n", /errno/, /error_string/, /ERROR_DEFINE/`

In this, `/errno/` is the value provided as an operand, `/error_string/` is
the string returned by the C function `strerror()`, and `/ERROR_DEFINE/` is
the name of the symbolic constant defined to `/errno/` in `<errno.h>`. If
`/errno/` does not match a known symbolic constant, `/ERROR_DEFINE/` will
be `-`.

## STDERR

Not used.

## Output Files

None.

## Exit Status

 0	Successful completion.
 >0	An error occurred.
