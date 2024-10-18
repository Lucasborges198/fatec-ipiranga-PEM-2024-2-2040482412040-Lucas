/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: QUICKSORT                              *
* RA: 2040482412040                                                             *
* Data: 18/10/2024                                             * 
* Autor: Lucas Borges Ribeiro               *
*--------------------------------------------------------------*/

#include <stdio.h>

// Função para trocar dois elementos
void troca(int *posicao1, int *posicao2) {
    int temp = *posicao1;
    *posicao1 = *posicao2;
    *posicao2 = temp;
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para realizar a partição do array
int particao(int arr[], int limInferior, int limSup) {
    int pivo = arr[limSup];
    int ind = limInferior - 1;

    for (int j = limInferior; j < limSup; j++) {
        if (arr[j] <= pivo) {
            ind++;
            troca(&arr[ind], &arr[j]);
        }
    }
    troca(&arr[ind + 1], &arr[limSup]);
    return (ind + 1);
}

// Função QuickSort recursiva
void quickSort(int arr[], int limInferior, int limSup) {
    if (limInferior < limSup) {
        int indParticao = particao(arr, limInferior, limSup);
        quickSort(arr, limInferior, indParticao - 1);
        quickSort(arr, indParticao + 1, limSup);
    }
}

// Função principal
int main() {
    int arr[] = {100, 70, 90, 90, 10, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}