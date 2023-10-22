#include <stdio.h>


 
//subq    %rsi, %rdx  == %rdx = %rdx - %rdi
//imulq   %rdx, %rdi == %rdi = %rdi * %rdx
//salq    $63, %rdx == %rdx = %rdx << 63
//sarq    $63, %rdx == %rdx = %rdx >> 63
//movq    %rdi, %rax == swap values
//orq     %rdx, %rax == %rax = %rax | %rdx
//ret

// x = rdi, y = rsi, z = rdx
long f(long x, long y, long z) {
    long result;
    
    z -= y;       // subq %rsi, %rdx
    x *= z;       // imulq %rdx, %rdi
    z <<= 63;     // salq $63, %rdx
    z >>= 63;     // sarq $63, %rdx

    // Swap values of x and z
    long temp = x;
    x = z;
    z = temp;

    result = x;    // movq %rdi, %rax
    result |= z;   // orq %rdx, %rax

    return result;
}


int main(int argc, char *argv[]) {
    if (argc == 4) {
        long x = strtol(argv[1], NULL, 10);
        long y = strtol(argv[2], NULL, 10);
        long z = strtol(argv[3], NULL, 10);
        printf("f(%ld, %ld, %ld): Result is %ld\n", x, y, z, f(x, y, z));
    } else {
        // Test cases calling the custom function f
        printf("f(1, 2, 4): Result is %ld\n", f(1, 2, 4));
        printf("f(3, 5, 7): Result is %ld\n", f(3, 5, 7));
        printf("f(10, 20, 40): Result is %ld\n", f(10, 20, 40));
        printf("f(30, 50, 70): Result is %ld\n", f(30, 50, 70));
        printf("f(30, 50, -70): Result is %ld\n", f(30, 50, -70));
    }
    return 0;
}
