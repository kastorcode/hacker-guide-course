#include <stdio.h>
#include <stdlib.h>

int main()
{
    int entrada;

    printf("Digite um valor de entrada: ");
    scanf("%d", &entrada);

    if (entrada == 12) {
        printf("O valor é doze.\n");
    }
    else if (entrada > 10) {
        printf("Maior.\n");
    }
    else {
        printf("Menor.\n");
    }

    printf("\nValor: %d\n", entrada);

    return 0;
}
