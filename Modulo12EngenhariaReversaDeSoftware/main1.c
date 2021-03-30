#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char pass[] = "senha_123";
    char inputPass[55];

    while (1) {
        printf("Digite a senha: ");
        scanf(" %s", inputPass);

        if (strcmp(pass, inputPass) == 0) {
            printf("Senha correta.\n\n");
        }
        else {
            printf("Senha incorreta.\n\n");
        }
    }

    return 0;
}
