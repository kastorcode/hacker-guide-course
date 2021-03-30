#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho = 51;
    char frase[tamanho];

    printf("Entre com uma frase de até %d caracteres:\n", tamanho - 1);
    scanf(" %s", frase);

    for(int i = 0; i < tamanho; i++) {
        if (frase[i] == 'a') {
            frase[i] = 'y';
        }
        else if (frase[i] == 'A') {
            frase[i] = 'Y';
        }
    }

    printf("\n%s\n", frase);

    return 0;
}
