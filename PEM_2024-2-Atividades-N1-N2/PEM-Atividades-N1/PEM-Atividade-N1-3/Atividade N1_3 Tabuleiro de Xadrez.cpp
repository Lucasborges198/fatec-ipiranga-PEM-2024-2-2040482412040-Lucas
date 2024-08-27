/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                          *
*--------------------------------------------------------*
* Objetivo do Programa: Fazer um esquema de tabuleiro      *
* Data - 27/08/2024                                        * 
* Autor:Lucas Borges Ribeiro;2040482412040*
*--------------------------------------------------------*/
#include <stdio.h>
#define TAMANHO_TABULEIRO 8

int main(void) {
    char peca[] = "TCBDRBP"; // Representação das peças pelas letras
    char cor[] = "PPPPPPPP"; // Representação com as cores pretas
    
    printf("\n");
    
    for(int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        int n = 0;   // Inserção de numeração nas letras
        
        for(int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("|"); // Inicia cada célula do tabuleiro com um |
            
            // Impressão de peças e também de espaços vazios
            if (linha == 0) {
                // Linha de peças brancas (linha 1)
                printf("B%c%d", peca[coluna], coluna + 1);
            } 
            else if (linha == 1) {
                // Linha de peões brancos
                printf("BP%d", coluna + 1);
            }
            else if (linha == 6) {
                // Linha de peões pretos
                printf("PP%d", coluna + 1);
            }
            else if (linha == 7) {
                // Linha de peças pretas (linha 8)
                printf("P%c%d", peca[coluna], coluna + 1);
            }
            else {
                // Espaços vazios
                printf(" X "); // Espaço em branco melhor formatado
            }
            
            if (coluna == TAMANHO_TABULEIRO - 1) {
                printf("|"); 
            }
        }
        printf("\n");
    }
    return 0;
}