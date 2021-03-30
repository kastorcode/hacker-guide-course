#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador = 0;

    printf("\nWhile:\n\n");

    while(contador < 10) {
        printf("Valor do contador: %d\n", contador);
        contador++;
    }

    printf("\nFor:\n\n");

    for(contador = 0; contador < 10; contador++) {
        printf("Valor do contador: %d\n", contador);
    }

    int v1, v2;

    printf("\nEntre com dois valores: ");
    scanf("%d %d", &v1, &v2);

    if (v1 > v2) {
        printf("O maior valor é: %d\n\n", v1);
    }
    else {
        printf("O maior valor é: %d\n\n", v2);
    }

    int tam = 3;
    int v[tam];

    for(int i = 0; i < tam; i++) {
        printf("Entre com o valor da posição %d: ", i);
        scanf("%d", &v[i]);
    }

    for(int  i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
