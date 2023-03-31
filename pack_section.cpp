#include "uniform_compiler.h"
 
PACK_SECTION(
    8, struct pack_a { int a; };)

PACK_SECTION(
    2, struct pack_b { int a; };)

PACKED_SECTION(struct pack_c { int a; };)
