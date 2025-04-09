#include <stdio.h>

unsigned long long int fibonacci_iterativo(int n) {
    if (n <= 1) {
        return n;
    } else {
        unsigned long long int fib_prev = 0, fib = 1;
        for (int i = 2; i <= n; i++) {
            unsigned long long int temp = fib;
            fib = fib_prev + fib;
            fib_prev = temp;
        }
        return fib;
    }
}

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    unsigned long long int resultado = fibonacci_iterativo(n);
    printf("O %d-ésimo termo da sequência de Fibonacci é: %llu\n", n, resultado);

    return 0;
}
