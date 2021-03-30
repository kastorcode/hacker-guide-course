#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>


/*
    File = 8
    Folder = 4
*/


void decifraArquivo(char *path) {
    printf("Decifrando arquivo: %s\n", path);

    // LEITURA DO ARQUIVO
    FILE *input = fopen(path, "rb");
    fseek(input, 0, SEEK_END);
    long length = ftell(input);
    rewind(input);

    void *buffer = malloc(length);

    fread(buffer, length, 1, input);
    fclose(input);
    // FIM DA LEITURA

    // DECRIPTOGRAFIA

    for (int i = 0; i < length; i++) {
        *(char*)(buffer + i) -= 1;
    }

    // FIM DA DECRIPTOGRAFIA

    // ESCRITA NO DISCO, DECRIPTOGRAFIA

    FILE *output = fopen(path, "wb");
    fwrite(buffer, length, 1, output);
    fclose(output);

    // FIM DA ESCRITA, DECRIPTOGRAFIA
}


void cifraArquivo(char *path) {
    printf("Cifrando arquivo: %s\n", path);

    // LEITURA DO ARQUIVO
    FILE *input = fopen(path, "rb");
    fseek(input, 0, SEEK_END);
    long length = ftell(input);
    rewind(input);

    void *buffer = malloc(length);

    fread(buffer, length, 1, input);
    fclose(input);
    // FIM DA LEITURA

    // CRIPTOGRAFIA

    for (int i = 0; i < length; i++) {
        *(char*)(buffer + i) += 1;
    }

    // FIM DA CRIPTOGRAFIA

    // ESCRITA NO DISCO

    FILE *output = fopen(path, "wb");
    fwrite(buffer, length, 1, output);
    fclose(output);

    // FIM DA ESCRITA
}


void buscaArquivos(char *raiz) {
    DIR *d = opendir(raiz);
    struct dirent *dir = readdir(d);

    while (dir != NULL) {
        if (dir->d_type == 8) {
            char path[strlen(raiz) + strlen(dir->d_name)];
            snprintf(path, sizeof(path), "%s/%s", raiz + 2, dir->d_name);

            cifraArquivo(path);
            //decifraArquivo(path);
        }
        else if (dir->d_name[0] != '.') {
            char caminho[strlen(raiz) + strlen(dir->d_name) + 2];
            snprintf(caminho, sizeof(caminho), "%s/%s", raiz, dir->d_name);

            buscaArquivos(caminho);
        }

        dir = readdir(d);
    }

    closedir(d);
}


int main()
{
    buscaArquivos("./arquivos");

    return 0;
}
