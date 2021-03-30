#include <stdio.h>
#include <stdlib.h>


typedef struct s_node {
    char data;
    struct s_node* next;
} s_node;


void printLista(s_node* lista) {
    while (lista->next != NULL) {
        printf("%c\n", lista->data);
        lista = lista->next;
    }

    printf("%c\n", lista->data);
}


void initLista(s_node* lista) {
    lista->data = NULL;
    lista->next = NULL;
}


void addLista(s_node* lista, char data) {
    while (lista->next != NULL) {
        lista = lista->next;
    }

    s_node* node = malloc(sizeof(s_node));
    node->data = data;
    node->next = NULL;

    lista->next = node;
}


int main()
{
    s_node A;
    A.data = 'A';
    A.next = NULL;

    s_node B;
    B.data = 'B';
    B.next = NULL;
    A.next = &B;

    s_node C;
    C.data = 'C';
    C.next = NULL;
    B.next = &C;

    s_node D;
    D.data = 'D';
    D.next = NULL;
    C.next = &D;

    printLista(&A);


    s_node lista;
    initLista(&lista);

    addLista(&lista, 'x');
    addLista(&lista, 'y');
    addLista(&lista, 'z');

    printLista(&lista);


    return 0;
}
