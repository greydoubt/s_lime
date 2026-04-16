.Dd May 01, 2022
.Dt ECHO 0
.Os
.Sh NAME
.Nm echo
.Nd write arguments to the standard output
.Sh SYNOPSIS
.Nm
.Op Fl n
.Op Ar string ...
.Sh DESCRIPTION
The
.Nm
utility writes any specified operands, separated by single blank (`` '')
characters and followed by a newline (``\en'') character, to the standard
output.
.Pp
The following option is available:
.Bl -tag -width flag
.It Fl n
Do not print the trailing newline character.
.El
.Pp
Note that many shells (e.g.,
.Xr csh 1
and
.Xr ksh 1 )
provide a built-in
.Nm
command which tends to differ from this utility in the treatment of options
and backslashes.
Where portability is paramount, use
.Xr printf 1 .
.Sh EXIT STATUS
.Ex -std echo
.Sh SEE ALSO
.Xr csh 1 ,
.Xr ksh 1 ,
.Xr printf 1
.Sh STANDARDS
The
.Nm
utility is expected to be
.St -p1003.2
compatible.
.Sh HISTORY
An
.Nm
utility appeared in
.At v2 .
