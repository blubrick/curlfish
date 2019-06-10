# Curlfish - The CRLF shell

This is **curlfish**, a program just about as simple as they come.  The name comes from an expansion of an abreviation of "CR/LF shell" (CRLF shell -> crlfsh - > curlfish)

What is a "CR/LF shell"? And why did I bother doing this?  Well, years ago as a sysadmin, a user came to me with a puzzling error: his shell script was doing nothing but printing this error message `: File not found /bin/ksh`

This was decidedly odd, because `/bin/ksh` certainly did exist!  After a little investigation, I discovered that he had transferred the file up to the unix server (running HP- UX 10.20, IIRC) via FTP from his windows desktop PC, and had done so in binary mode.  Consequently, his script was full of CR/LF line endings, and when it ran, the shell found the shebang line `"#!/bin/ksh^M"`  Naturally, when the shell could find no file of that name, it ceased executing the script, and printed this 4-part error message:

```
ksh: ./myscript: /bin/ksh^M: File not found
 ^        ^          ^             ^
 1        2          3             4
 ```

Needless to say, the `^M` character was interpreted by the terminal as a carriage return, and the error message began overwriting itself from the start of the line. By a weird quirk of coincidence, part 4 of the error message was just long enough to completely overwrite parts 1 and 2 while leaving part 3 (mostly) intact, resulting in the slightly cryptic message shown earlier.

So I hit upon the idea of installing a program called `/bin/ksh^M` that merely printed a newline and an error message explaining exactly what must have happened and then exited. The result was **curlfish**

In fact, curlfish is little more than "Hello World!". The real hack is in the naming of files (filenames of symbolic links, actually). The actual binary is installed wherever you like (e.g. `/usr/local/bin`) and you make multiple symlinks to it, named exactly the same as real shells and script interpreters, except followed by a carriage return character. Thus, when a script file is created under an OS which uses CRLF line terminations by default, the script has a valid interpreter to call via its `#!` line.

For example:
```
/bin/ksh^M -> /usr/local/bin/curlfish
/bin/csh^M -> /usr/local/bin/curlfish
/usr/bin/perl^M -> /usr/local/bin/curlfish
/usr/local/bin/python^M -> /usr/local/bin/curlfish
(etc.)
```

Actually creating filenames with those characters is left as an exercise for the reader. There are several ways of doing so, and they all require some form of root access to create the symlinks that match the system-installed shells (at least, they _should_. Your system is pretty well b0rked if you can do this without root access).

I have also added a fairly distinctive return code (29), so that if scripts that call curlfish are called by methods other than a direct shell invocation, that fact can be tested for and the error handled gracefully. This might perhaps be useful in build systems.

So there it is at last, a somewhat practical use for a "Hello World!" program!


--

blubrick, 05/10/16 (code actually written _circa_ 2001)
