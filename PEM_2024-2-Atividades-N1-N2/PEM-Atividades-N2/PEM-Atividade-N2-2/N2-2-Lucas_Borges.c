
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*-----------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular              *
*          Prof. Carlos Veríssimo                            *                                
*------------------------------------------------------------*
* Objetivo do Programa: Comparação insertion com bubble sort *
* Data : 11/10/2024                                          * 
* Autor: Lucas Borges                                       *
*------------------------------------------------------------*/

/*---------------------------------------------------------*
| Declaração antecipada das funções                        |
*---------------------------------------------------------*/
void printArray(int array[], int size);
void bubbleSort(int array[], int n, int *trocas, int *ciclos);
void change(int *xp, int *yp);

/*---------------------------------------------------------*
| Módulo - Printar o array                                 |
*---------------------------------------------------------*/
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/*---------------------------------------------------------*
| Módulo - Realizar o BubbleSort com contagem de trocas e ciclos  |
*---------------------------------------------------------*/
void bubbleSort(int array[], int n, int *trocas, int *ciclos) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*ciclos)++; // Conta ciclos (comparações)
            if (array[j] > array[j + 1]) {
                change(&array[j], &array[j + 1]);
                (*trocas)++; // Conta trocas
            }
        }
    }
}

/*---------------------------------------------------------*
| Módulo - Mudar posições                                  |
*---------------------------------------------------------*/
void change(int *xp, int *yp) {
    int temporary = *xp;
    *xp = *yp;
    *yp = temporary;
}

/*---------------------------------------------------------*
| Módulo - Modulo principal                                |
*---------------------------------------------------------*/
int main() {

    // CLOCK INICIO
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Inicializa array
    int array[] = {5, 3, 8, 4, 2,
                   115, 113, 118, 114, 112,
                   125, 123, 128, 124, 122,
                   35, 33, 38, 34, 32,
                   45, 43, 48, 44, 42,
                   55, 53, 58, 54, 52,
                   65, 63, 68, 64, 62,
                   75, 73, 78, 74, 72,
                   85, 83, 88, 84, 82,
                   95, 93, 98, 94, 92,
                   15, 13, 18, 14, 12,
                   25, 23, 28, 24, 22
    };

    // Calcula o número de elementos no array
    int n = sizeof(array) / sizeof(array[0]);

    // Variáveis para contar trocas e ciclos
    int trocas = 0, ciclos = 0;

    printf("Array original: ");
    // Chama modulo para printar array
    printArray(array, n);

    // Chama modulo para realizar o bubbleSort com contagem
    bubbleSort(array, n, &trocas, &ciclos);

    printf("Array ordenado: ");
    // Chama modulo para printar array
    printArray(array, n);

    // Exibe contagem de trocas e ciclos
    printf("Numero de trocas: %d\n", trocas);
    printf("Numero de ciclos (comparacoes): %d\n", ciclos);

    // CLOCK FIM
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", cpu_time_used);

    return 0;
}
