#include <stdio.h>
#include <stdlib.h>

int main()
{
    char mensagem[15] = "Olá, tudo bem?";
    int chave = 4;

    printf("%s\n", mensagem);

    for (int i = 0; i < 14; i++) {
        if (mensagem[i] != ' ' && mensagem[i] != '?') {
            mensagem[i] += 4;
        }
    }

    printf("%s\n", mensagem);

    return 0;
}
