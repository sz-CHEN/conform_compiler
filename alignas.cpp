#include "uniform_compiler.h"

ALIGNAS(8) char alignas_buf[10];

ALIGNAS(32) int alignas_int;
ALIGNAS(8) struct alignas_struct_a {
    ALIGNAS(4) char a;
} alignasA;

ALIGNAS(32) struct alignas_struct_b {
    char a;
    ALIGNAS(32) int b;
} alignasB;
