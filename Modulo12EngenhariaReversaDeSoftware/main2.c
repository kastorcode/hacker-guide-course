#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char msgOK[] = "Senha Correta";
char msgError[] = "Senha Incorreta";


void geradorSenha(char *str, char *senha) {
    int i;
    int length = strlen(str) - 1;

    for (i = 0; i < length; i++) {
        senha[i] = ((str[i] + str[i + 1]) % 'A') + 'A';

        if (senha[i] > 'z') {
            senha[i] -= 'z' - 'A';
        }

        if (senha[i] >= 91 && senha[i] <= 96) {
            senha[i] += 91 - 96;
        }
    }

    senha[i] = '\0';
}


int validar(char p1[55], char p2[55]) {
    if (p1[0] == '\0' && p2[0] == '\0') {
        return -357;
    }
    else if (p1[0] == p2[0]) {
        return validar(&p1[1], &p2[1]);
    }
    else {
        return 78;
    }
}


void sucesso(int a) {
    if (a > 0) {
        printf("Senha correta\n");
    }
}


void erro(int a) {
    if (a < 0) {
        printf("Senha incorreta\n");
    }
}


void chamador(void (*f)(int), int a) {
    (*f)(a);
}


int main() {
    char login[55], senha[55], senhaGerada[55];
    int r;

    while (1) {
        printf("Entre com o usuario: ");
        scanf(" %s", login);

        printf("Usuario %s entre com a senha: ", login);
        scanf(" %s", senha);

        geradorSenha(login, senhaGerada);
        printf("%s\n", senhaGerada);

        r = validar(senha, senhaGerada);
        r += 1;
        r *= -2;

        chamador(&erro, r);
        chamador(&sucesso, r);

        printf("\n--\n\n");
    }

    return 0;
}
