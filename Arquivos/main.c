#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int idade;
    char nome[55];
} s_pessoa;


void append(void) {
    FILE* fp;
    fp = fopen("primeiro.txt", "a+");
    fprintf(fp, "Olá, tudo bem?\nComigo tudo!\n");
    fclose(fp);
}


void appendBin(void) {
    s_pessoa p;
    p.idade = 20;
    strcpy(p.nome, "Matheus");

    FILE* fp = fopen("data.bin", "ab+");
    fwrite(&p, sizeof(s_pessoa), 1, fp);
    fclose(fp);
}


void readBin(void) {
    s_pessoa p;
    FILE* fp = fopen("data.bin", "ab+");
    fread(&p, sizeof(s_pessoa), 1, fp);
    fclose(fp);

    printf("%d %s\n", p.idade, p.nome);
}


int main()
{
    // append();
    // appendBin();
    // readBin();

    return 0;
}
