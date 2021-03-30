#include <stdio.h>
#include <stdlib.h>

int main()
{
    float v1;
    float v2;
    char op;
    float resultado;

    /*
    printf("Entre com o primeiro valor: ");
    scanf("%f", &v1);

    printf("Entre com a operação desejada: ");
    scanf(" %c", &op);

    printf("Entre com o segundo valor: ");
    scanf("%f", &v2);
    */

    printf("Entre com a equação: ");
    scanf("%f %c %f", &v1, &op, &v2);

    switch (op) {
        case '+':
            resultado = v1 + v2;
        break;

        case '-':
            resultado = v1 - v2;
        break;

        case '*':
            resultado = v1 * v2;
        break;

        case '/':
            resultado = v1 / v2;
        break;

        default:
            printf("Operação inválida.\n");
        return 1;
    }

    printf("O resultado foi: %f\n", resultado);

    return 0;
}
