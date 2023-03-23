#include "uniform_compiler.h"

ALIGNAS(8) char alignas_buf[10];

ALIGNAS(1) int alignas_int;
ALIGNAS(1) struct alignas_struct_a {
    ALIGNAS(4) char a;
} alignasA;

ALIGNAS(1) struct alignas_struct_b {
    char a;
    ALIGNAS(1) int b;
} alignasB;
