#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular           *
*          Prof. Carlos Veríssimo                         *                                
*---------------------------------------------------------*
* Objetivo do Programa: Bubble Sort em C                  *
* Data : 04/10/2024                                       * 
* Autor: Kauan Torres e Lucas Borges                      *
*--------------------------------------------------------*/

/*---------------------------------------------------------*
| 					MELHORIAS                              |
*---------------------------------------------------------*/

//1. Modularização do código
//2. Pedir entrada de n numeros em vez de um array já feito
//3. Criação da função de change (troca das posições)
//4. Definição de um nome de mais fácil entendimento das variavéis 
//5. Utilização de ponteiros

/*----------------------------------------------------------------------------------------------------*
| Declaração antecipada das funções (estava dando erro se não declarasse antes                       |
*----------------------------------------------------------------------------------------------------*/
void printArray(int array[], int size);
void bubbleSort(int array[], int n);
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
| Módulo - Realizar o BubbleSort                           |
*---------------------------------------------------------*/
void bubbleSort(int array[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                change(&array[j], &array[j + 1]);
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
    int n, i;

    printf("Quantos numeros deseja inserir? ");
    scanf("%d", &n);

    int array[n];

    printf("Insira %d numeros:\n", n);
    for (i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Array original: ");
    // Chama modulo para printar array
    printArray(array, n);

    // Chama modulo para realizar o bubbleSort
    bubbleSort(array, n);

    printf("Array ordenado: ");
    // Chama modulo para printar array
    printArray(array, n);

    return 0;
}

