#include <stdio.h>
#include <stdlib.h>

// Função para calcular a soma das notas centrais (excluindo a maior e a menor)
float calcularNota(float notas[], int n) {
    float maior = notas[0], menor = notas[0], soma = 0;
    for (int i = 0; i < n; i++) {
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
        soma += notas[i];
    }
    // Soma das notas centrais excluindo maior e menor
    return soma - maior - menor;
}

int main() {
    int n, i;
    float notaFinal = 0;

    // Vetor para armazenar as notas
    float notas[100];

    // Vetor para armazenar os nomes das provas
    char* provas[] = {
        "Raciocinio logico", 
        "Conceitos de gerenciamento de projetos", 
        "Lingua inglesa", 
        "Conceitos de metodologia agil", 
        "Linguagem Javascript"
    };
	
    for (i = 0; i < 5; i++) {
        // Entrada do número de notas para a prova atual
        printf("Digite o numero de notas para a prova %s : ", provas[i]);
        scanf("%d", &n);

        // Validação para ter no mínimo 3 notas
        while (n < 3) {
            if (n == 0) {
                printf("Pulando para a proxima bateria!\n");
                break;
            }
            printf("Numero minimo de notas nao foi atingido!\n");
            printf("Digite o numero de notas para a prova %s : ", provas[i]);
            scanf("%d", &n);
        }

        // Processamento das notas, se houver pelo menos 3
        if (n >= 3) {	
            printf("Digite as notas separadas por espaco: ");
            for (int j = 0; j < n; j++) {
                scanf("%f", &notas[j]);
            }

            // Calcula a nota da prova atual
            float notaAtual = calcularNota(notas, n);
            notaFinal += notaAtual;

            // Exibe a nota da prova atual
            printf("Nota %s = %.2f\n", provas[i], notaAtual);
        }
    }

    // Exibe a nota final do candidato
    printf("Nota final do candidato = %.2f\n", notaFinal);

    return 0;
}