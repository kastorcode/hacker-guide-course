#include <stdio.h>
#include <stdlib.h>


void fibonacci(int qtd) {
    int atual = 1;
    int anterior = 0;
    int novoNumero;

    printf("1 ");

    for(int i = 1; i < qtd; i++) {
        novoNumero = atual + anterior;
        printf("%d ", novoNumero);
        anterior = atual;
        atual = novoNumero;
    }

    printf("\n");
}


int main()
{
    printf("Executando função de Fibonacci\n\n");

    int qtd = 1;

    while (qtd > 0) {
        printf("Quantos números quer ver? ");
        scanf("%d", &qtd);

        if (qtd > 0) {
            fibonacci(qtd);
        }
    }

    return 0;
}
