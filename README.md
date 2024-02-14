# README #

This allows suppressing specific warnings for certain (third-party) includes,
in a manner that is compiler-independent.
It should work with Clang, GCC, and MSVC (MSVC is untested).

Usage example:
#include "warning_suppressor.h"
ELK_PUSH_WARNING
ELK_DISABLE_SHADOW_FIELD
#include <JuceHeader.h>
ELK_POP_WARNING

It's made combining some tips found online.

From here:
https://stackoverflow.com/questions/45762357/how-to-concatenate-strings-in-the-arguments-of-pragma/45783809#45783809

Combining this:
https://software.codidact.com/posts/280528

With this:
https://stackoverflow.com/questions/28166565/detect-gcc-as-opposed-to-msvc-clang-with-macro

And this:
https://gcc.gnu.org/onlinedocs/gcc/Diagnostic-Pragmas.html
