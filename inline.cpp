#include "conform_compiler.h"

FOO_INLINE int inline_foo_a(){
    return 0;
}

int inline_main(){
    return inline_foo_a();
} 
