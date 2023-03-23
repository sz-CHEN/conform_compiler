#include "uniform_compiler.h"

FOO_INLINE int inline_foo_a() { return 0; }

FORCE_FOO_INLINE int inline_foo_b(int b) { return b + 1; }

int inline_main() { return inline_foo_a() + inline_foo_b(9); }
