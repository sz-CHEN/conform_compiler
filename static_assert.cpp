#include "uniform_compiler.h"

// STATIC_ASSERT(0);
// STATIC_ASSERT(0);
// STATIC_ASSERT(0, ABC);
STATIC_ASSERT(1);
STATIC_ASSERT(1);
STATIC_ASSERT(1, ABCD);

int static_assert_main() {
    // STATIC_ASSERT(0);
    // STATIC_ASSERT(0);
    // STATIC_ASSERT(0, ABC);
    STATIC_ASSERT(1);
    STATIC_ASSERT(1);
    STATIC_ASSERT(1, ABCD);
    return 0;
}