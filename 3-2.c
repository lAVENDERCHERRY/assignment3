#include <stdlib.h>
#include <stdio.h>
//x is in %rdi
//y is in %rsi
//z is in %rdx, and that %rax

//subq    %rsi, %rdx
//imulq   %rdx, %rdi
//salq    $63, %rdx
//sarq    $63, %rdx
//movq    %rdi, %rax
//orq     %rdx, %rax
//ret



int main(int argc, char *argv[]) {
    if (argc == 4) {
        long x = strtol(argv[1], NULL, 10);
        long y = strtol(argv[2], NULL, 10);
        long z = strtol(argv[3], NULL, 10);
        printf("f(%ld, %ld, %ld): %ld\n", x, y, z, f(x, y, z));
    } else {
        // TODO - your test cases go here!
        printf("f(1, 2, 4): %ld\n", f(1, 2, 4));
        printf("f(3, 5, 7): %ld\n", f(3, 5, 7));
        printf("f(10, 20, 40): %ld\n", f(10, 20, 40));
        printf("f(30, 50, 70): %ld\n", f(30, 50, 70));
        printf("f(30, 50, -70): %ld\n", f(30, 50, -70));
    }
    return 0;
}