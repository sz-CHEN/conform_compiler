#include "uniform_compiler.h"

ALIGNAS(8) char alignas_buf[10];

ALIGNAS(32) int alignas_int;
struct alignas_struct_a {
    ALIGNAS(4) char a;
} alignasA;

struct alignas_struct_b {
    char a;
    ALIGNAS(8) int b;
} alignasB;
