/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular           *
*          Prof. Carlos Veríssimo                         *
*--------------------------------------------------------*
* Objetivo do Programa: Refatorando para modularizar código *
* Data - 12/09/2024                                       * 
* Autor: Lucas Borges Ribeiro; 2040482412040              *
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

// Função para inicializar o tabuleiro com as peças
void inicializarTabuleiro(char tabuleiro[8][8][4]) {
    // Definir as peças pretas e brancas
    char* pecasPretas[] = {"PT1", "PC1", "PB1", "PD ", "PR ", "PB2", "PC2", "PT2"};
    char* peoesPretos[] = {"PP1", "PP2", "PP3", "PP4", "PP5", "PP6", "PP7", "PP8"};
    char* pecasBrancas[] = {"BT1", "BC1", "BB1", "BD ", "BR ", "BB2", "BC2", "BT2"};
    char* peoesBrancos[] = {"BP1", "BP2", "BP3", "BP4", "BP5", "BP6", "BP7", "BP8"};

    // Preencher o tabuleiro com as peças
    for (int i = 0; i < 8; i++) {
        snprintf(tabuleiro[0][i], 4, "%s", pecasPretas[i]);  // Peças principais pretas
        snprintf(tabuleiro[1][i], 4, "%s", peoesPretos[i]);  // Peões pretos
        snprintf(tabuleiro[6][i], 4, "%s", peoesBrancos[i]); // Peões brancos
        snprintf(tabuleiro[7][i], 4, "%s", pecasBrancas[i]); // Peças principais brancas
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[8][8][4]) {
    char colunas[] = "abcdefgh"; // Letras das colunas

    // Exibir letras das colunas
    printf("    ");
    for (int i = 0; i < 8; i++) {
        printf("  %c  ", colunas[i]);
    }
    printf("\n");

    // Linha separadora
    printf("  +");
    for (int i = 0; i < 8; i++) {
        printf("-----+");
    }
    printf("\n");

    // Exibir o tabuleiro linha por linha
    for (int linha = 0; linha < 8; linha++) {
        printf(" %d |", 8 - linha); // Exibe o número da linha
        for (int coluna = 0; coluna < 8; coluna++) {
            printf(" %-3s |", tabuleiro[linha][coluna]); // Peças alinhadas à esquerda
        }
        printf(" %d\n", 8 - linha); // Exibe o número da linha novamente

        // Linha separadora entre linhas
        printf("  +");
        for (int i = 0; i < 8; i++) {
            printf("-----+");
        }
        printf("\n");
    }

    // Exibir letras das colunas novamente
    printf("    ");
    for (int i = 0; i < 8; i++) {
        printf("  %c  ", colunas[i]);
    }
    printf("\n");
}

// Função para mover uma peça no tabuleiro
void moverPeca(char tabuleiro[8][8][4], int origemLinha, int origemColuna, int destinoLinha, int destinoColuna) {
    char peca[4]; // Variável para armazenar a peça que será movida
    snprintf(peca, 4, "%s", tabuleiro[origemLinha][origemColuna]);

    // Atualizar as posições no tabuleiro
    snprintf(tabuleiro[origemLinha][origemColuna], 4, "..."); // Marca o local original como vazio
    snprintf(tabuleiro[destinoLinha][destinoColuna], 4, "%s", peca); // Coloca a peça no destino
}

// Função principal para executar o jogo
void executarJogo() {
    char tabuleiro[8][8][4]; // Definir o tabuleiro 8x8
    inicializarTabuleiro(tabuleiro); // Inicializar as peças

    // Exibir o tabuleiro inicial
    printf("Tabuleiro Inicial:\n");
    exibirTabuleiro(tabuleiro);

    // Executar as jogadas da sequência "Xeque Pastor"
    moverPeca(tabuleiro, 6, 4, 4, 4); // Brancas jogam Peão e2 -> e4
    printf("\nApós jogada 1 (Brancas jogam Peão e2 -> e4):\n");
    exibirTabuleiro(tabuleiro);

    moverPeca(tabuleiro, 1, 4, 3, 4); // Pretas jogam Peão e7 -> e5
    printf("\nApós jogada 1 (Pretas jogam Peão e7 -> e5):\n");
    exibirTabuleiro(tabuleiro);

    moverPeca(tabuleiro, 7, 5, 4, 2); // Brancas jogam Bispo f1 -> c4
    printf("\nApós jogada 2 (Brancas jogam Bispo f1 -> c4):\n");
    exibirTabuleiro(tabuleiro);

    moverPeca(tabuleiro, 0, 1, 2, 2); // Pretas jogam Cavalo b8 -> c6
    printf("\nApós jogada 2 (Pretas jogam Cavalo b8 -> c6):\n");
    exibirTabuleiro(tabuleiro);

    moverPeca(tabuleiro, 7, 3, 3, 7); // Brancas jogam Dama d1 -> h5
    printf("\nApós jogada 3 (Brancas jogam Dama d1 -> h5):\n");
    exibirTabuleiro(tabuleiro);

    moverPeca(tabuleiro, 0, 6, 2, 5); // Pretas jogam Cavalo g8 -> f6
    printf("\nApós jogada 3 (Pretas jogam Cavalo g8 -> f6):\n");
    exibirTabuleiro(tabuleiro);

    moverPeca(tabuleiro, 3, 7, 1, 5); // Xeque Mate - Brancas capturam Peão f7
    printf("\nJogada Final (Brancas capturam Peão em f7 -> Xeque Mate):\n");
    exibirTabuleiro(tabuleiro);
}

int main() {
    executarJogo(); // Chamar função para iniciar o jogo
    return 0;
}
