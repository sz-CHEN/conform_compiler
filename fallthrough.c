#include "uniform_compiler.h"

int fallthrough_main(int arg) {
    int a = 0;
    switch (arg) {
    case 0:
        a++;
        FALLTHROUGH;
    case 1:
        a++;
        break;
    case 2:
        a++;
    case 3:
        a++;
        break;
    case 4:
        a++;
        break;

    default:
        a++;
        break;
    }
    return a;
}
