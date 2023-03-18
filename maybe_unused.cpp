#include "conform_compiler.h"

MAYBE_UNUSED int maybe_unused_fooa() { return 0; }
int maybe_unused_foob() { return 0; }

int maybe_unused_main() {
    MAYBE_UNUSED int a;
    int b;
    int c = 0;
    c++;
    return c;
}
