#include <stdio.h>
#include <stdlib.h>


void addOne(int* valor) {
    (*valor)++;
    printf("Valor dentro da função addOne: %d\n", *valor);
}


int main() {
    int valor = 5;

    addOne(&valor);

    printf("Valor na função main: %d\n", valor);

    return 0;
}
