#include "uniform_compiler.h"

THREAD_LOCAL int thread_local_value = 0;

int thread_local_foo(){
    static THREAD_LOCAL int v = 0;
    v++;
    thread_local_value ++;
    return thread_local_value;
}

int thread_local_main(){
    return thread_local_foo();
}
