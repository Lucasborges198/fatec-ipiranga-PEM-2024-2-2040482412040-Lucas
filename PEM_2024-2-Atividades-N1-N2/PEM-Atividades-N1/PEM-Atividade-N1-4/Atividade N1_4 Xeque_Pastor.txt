/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                          *
*--------------------------------------------------------*
* Objetivo do Programa: Implementação da jogada "Xeque Pastor"      *
* Data - 05/09/2024                                        * 
* Autor:Lucas Borges Ribeiro;2040482412040*
*--------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

void inicializarTabuleiro(char tabuleiro[8][8][4]) {
    // Inicializar as peças pretas
    char* pecasPretas[] = {"PT1", "PC1", "PB1", "PD ", "PR ", "PB2", "PC2", "PT2"};
    char* peoesPretos[] = {"PP1", "PP2", "PP3", "PP4", "PP5", "PP6", "PP7", "PP8"};

    // Inicializar as peças brancas
    char* pecasBrancas[] = {"BT1", "BC1", "BB1", "BD ", "BR ", "BB2", "BC2", "BT2"};
    char* peoesBrancos[] = {"BP1", "BP2", "BP3", "BP4", "BP5", "BP6", "BP7", "BP8"};

    // Preencher peças pretas
    for (int i = 0; i < 8; i++) {
        snprintf(tabuleiro[0][i], 4, "%s", pecasPretas[i]);
        snprintf(tabuleiro[1][i], 4, "%s", peoesPretos[i]);
    }

    // Preencher espaços vazios
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            snprintf(tabuleiro[i][j], 4, "X  ");
        }
    }

    // Preencher peões brancos
    for (int i = 0; i < 8; i++) {
        snprintf(tabuleiro[6][i], 4, "%s", peoesBrancos[i]);
        snprintf(tabuleiro[7][i], 4, "%s", pecasBrancas[i]);
    }
}

void exibirTabuleiro(char tabuleiro[8][8][4]) {
    char letras[] = "abcdefgh";
    
    // Exibir letras das colunas
    printf("    ");
    for (int i = 0; i < 8; i++) {
        printf("  %c  ", letras[i]);
    }
    printf("\n");

    // Linha separadora superior
    printf("  +");
    for (int i = 0; i < 8; i++) {
        printf("-----+");
    }
    printf("\n");

    // Exibir cada linha do tabuleiro
    for (int i = 0; i < 8; i++) {
        printf(" %d |", 8 - i); // Exibir número da linha à esquerda
        for (int j = 0; j < 8; j++) {
            printf(" %-3s |", tabuleiro[i][j]); // Usar formato para alinhar à esquerda e garantir 3 caracteres
        }
        printf(" %d\n", 8 - i); // Exibir número da linha à direita

        // Linha separadora inferior
        printf("  +");
        for (int j = 0; j < 8; j++) {
            printf("-----+");
        }
        printf("\n");
    }

    // Exibir letras das colunas novamente
    printf("    ");
    for (int i = 0; i < 8; i++) {
        printf("  %c  ", letras[i]);
    }
    printf("\n");
}

void moverPeca(char tabuleiro[8][8][4], int origemLinha, int origemColuna, int destinoLinha, int destinoColuna) {
    // Salvar o valor da peça que será movida
    char peca[4];
    snprintf(peca, 4, "%s", tabuleiro[origemLinha][origemColuna]);

    // Marcar a origem com "..."
    snprintf(tabuleiro[origemLinha][origemColuna], 4, "...");

    // Mover a peça para o destino
    snprintf(tabuleiro[destinoLinha][destinoColuna], 4, "%s", peca);
}

int main() {
    // Definir o tabuleiro 8x8
    char tabuleiro[8][8][4];

    // Inicializar o tabuleiro com as peças
    inicializarTabuleiro(tabuleiro);

    // Exibir o tabuleiro inicial
    printf("Tabuleiro Inicial:\n");
    exibirTabuleiro(tabuleiro);

    // Jogada 1: Brancas jogam Peão do Rei (e2 para e4)
    moverPeca(tabuleiro, 6, 4, 4, 4);
    printf("\nApós jogada 1 (Brancas jogam Peão e2 -> e4):\n");
    exibirTabuleiro(tabuleiro);

    // Jogada 1: Pretas jogam Peão do Rei (e7 para e5)
    moverPeca(tabuleiro, 1, 4, 3, 4);
    printf("\nApós jogada 1 (Pretas jogam Peão e7 -> e5):\n");
    exibirTabuleiro(tabuleiro);

    // Jogada 2: Brancas jogam Bispo (f1 para c4)
    moverPeca(tabuleiro, 7, 5, 4, 2);
    printf("\nApós jogada 2 (Brancas jogam Bispo f1 -> c4):\n");
    exibirTabuleiro(tabuleiro);

    // Jogada 2: Pretas jogam Cavalo da Dama (b8 para c6)
    moverPeca(tabuleiro, 0, 1, 2, 2);
    printf("\nApós jogada 2 (Pretas jogam Cavalo b8 -> c6):\n");
    exibirTabuleiro(tabuleiro);

    // Jogada 3: Brancas jogam Dama (d1 para h5)
    moverPeca(tabuleiro, 7, 3, 3, 7);
    printf("\nApós jogada 3 (Brancas jogam Dama d1 -> h5):\n");
    exibirTabuleiro(tabuleiro);

    // Jogada 3: Pretas jogam Cavalo do Rei (g8 para f6)
    moverPeca(tabuleiro, 0, 6, 2, 5);
    printf("\nApós jogada 3 (Pretas jogam Cavalo g8 -> f6):\n");
    exibirTabuleiro(tabuleiro);

    // Jogada 4: Xeque Mate - Brancas capturam Peão do Rei (Dama em h5 captura Peão em f7)
    moverPeca(tabuleiro, 3, 7, 1, 5);
    printf("\nJogada Final (Brancas capturam Peão em f7 -> Xeque Mate):\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}