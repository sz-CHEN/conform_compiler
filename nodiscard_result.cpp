#include "uniform_compiler.h"
struct B {
    int b;
};

NODISCARD_RESULT() B nodiscard_b() { return B(); };

NODISCARD_RESULT(nodiscard_aa) int nodiscard_a() { return 0; }

int nodiscard_main(int argc, char const *argv[]) {
    nodiscard_b();
    nodiscard_a();
    return nodiscard_b().b;
}
