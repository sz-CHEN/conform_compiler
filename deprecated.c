#include "conform_compiler.h"

DEPRECATED() int depreacated_a() { return 0; }

DEPRECATED(deprecated_bb) int depreacated_b() { return 0; }

int deprecated_main() {
    depreacated_a();
    return depreacated_b();
}
