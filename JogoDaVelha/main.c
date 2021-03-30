#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char jogadores[2], tabuleiro[3][3];
    int vencedor, turno, x, y;
} s_jogo;


s_jogo reiniciarJogo(s_jogo jogo) {
    jogo.jogadores[0] = 'X';
    jogo.jogadores[1] = 'O';
    jogo.vencedor = 0;
    jogo.turno = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            jogo.tabuleiro[i][j] = ' ';
        }
    }

    return jogo;
}


void exibirTabuleiro(s_jogo jogo) {
    printf("\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0;j < 3; j++) {
            printf(" %c |", jogo.tabuleiro[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}


int validarJogada(s_jogo jogo) {
    if (jogo.x > -1 && jogo.x < 3 && jogo.y > -1 && jogo.y < 3 && jogo.tabuleiro[jogo.x][jogo.y] == ' ') {
        return 1;
    }
    else {
        return 0;
    }
}


s_jogo rodada(s_jogo jogo) {
    printf("Jogador %d, entre com as coordenadas:\n", jogo.turno + 1);
    scanf("%d %d", &jogo.x, &jogo.y);

    if (validarJogada(jogo)) {
        jogo.tabuleiro[jogo.x][jogo.y] = jogo.jogadores[jogo.turno];
    }
    else {
        printf("\n\nJogada inválida, perdeu a vez!\n\n");
    }

    if (jogo.turno) {
        jogo.turno--;
    }
    else {
        jogo.turno++;
    }

    return jogo;
}


s_jogo verificarVencedor(s_jogo jogo) {
    for (int i = 0; i < 3; i++) {
        if ((jogo.tabuleiro[i][0] != ' ' && jogo.tabuleiro[i][0] == jogo.tabuleiro[i][1] && jogo.tabuleiro[i][1] == jogo.tabuleiro[i][2]) ||
            (jogo.tabuleiro[0][i] != ' ' && jogo.tabuleiro[0][i] == jogo.tabuleiro[1][i] && jogo.tabuleiro[1][i] == jogo.tabuleiro[2][i])) {
            jogo.vencedor = jogo.turno ? 1 : 2;
            return jogo;
        }
    }

    if ((jogo.tabuleiro[0][0] != ' ' && jogo.tabuleiro[0][0] == jogo.tabuleiro[1][1] && jogo.tabuleiro[1][1] == jogo.tabuleiro[2][2]) ||
        (jogo.tabuleiro[0][2] != ' ' && jogo.tabuleiro[0][2] == jogo.tabuleiro[1][1] && jogo.tabuleiro[1][1] == jogo.tabuleiro[2][0])) {
        jogo.vencedor = jogo.turno ? 1 : 2;
        return jogo;
    }

    jogo.vencedor = 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (jogo.tabuleiro[i][j] == ' ') {
                jogo.vencedor = 0;
                return jogo;
            }
        }
    }

    return jogo;
}


void mensagemVencedor(s_jogo jogo) {
    switch (jogo.vencedor) {
        case 1:
            printf("\n\nO jogador 1 venceu!\n\n");
        break;

        case 2:
            printf("\n\nO jogador 2 é o vencedor!\n\n");
        break;

        case 3:
            printf("\n\nEmpate!\n\n");
        break;
    }
}


int main()
{
    char jogar;
    s_jogo jogo;

    while (1) {
        jogo = reiniciarJogo(jogo);
        exibirTabuleiro(jogo);

        while (!jogo.vencedor) {
            jogo = rodada(jogo);
            exibirTabuleiro(jogo);
            jogo = verificarVencedor(jogo);
        }

        mensagemVencedor(jogo);

        printf("\n\nJogar novamente? ");
        scanf(" %c", &jogar);

        if (jogar != 's' && jogar != 'y') {
            break;
        }
    }

    return 0;
}
