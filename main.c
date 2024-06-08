#include <stdio.h>

void print_binary(int n) {
    if (n > 1) {
        print_binary(n/2);
    }
    printf("%d", n % 2);
}

int main(void){
    // initialize a decimal number
    int dec = 100;

    // 打印十进制和二进制
    printf("Decimal: %d\n", dec);
    printf("Binary: ");
    print_binary(dec);
    printf("\n");

    // decimal to octal, hex
    printf("Octal: %o\n", dec);
    printf("Hex: %x\n", dec);

    return 0;
}