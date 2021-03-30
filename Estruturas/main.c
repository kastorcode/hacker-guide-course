#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct pessoa {
    int idade;
    char nome[51];
} s_pessoa;


int main()
{
    s_pessoa p1, p2, p[5];

    p1.idade = 18;
    strcpy(p1.nome, "Matheus");

    p2.idade = 20;
    strcpy(p2.nome, "Naruto");

    printf("Nome: %s | Idade: %d\n", p1.nome, p1.idade);
    printf("Nome: %s | Idade: %d\n", p2.nome, p2.idade);

    for(int i = 0; i < 5; i++) {
        printf("\nDigite o nome e a idade da pessoa:\n");
        scanf("%s %d", &p[i].nome, &p[i].idade);
    }

    s_pessoa pAux = p[0];

    for(int i = 1; i < 5; i++) {
        if (pAux.idade < p[i].idade) {
            pAux = p[i];
        }
    }

    printf("\nA pessoa mais velha é %s com %d anos.\n", pAux.nome, pAux.idade);

    return 0;
}
