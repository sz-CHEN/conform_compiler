#include "conform_compiler.h"

FOO_NORETURN int noreturn_foo() {
    while (1) {
        /* code */
    }
}

FOO_NORETURN void noreturn_fooa() {
    while (1) {
        /* code */
    }
}

int noreturn_main() {
    int a = 0;
    noreturn_fooa();
    noreturn_foo();
    a++;
    return 0;
}
