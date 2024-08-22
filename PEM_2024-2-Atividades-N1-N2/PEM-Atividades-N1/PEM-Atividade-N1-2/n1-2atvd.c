
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
    int n, i, totalNotas = 0;
    float notaFinal = 0;

    // Vetor para armazenar as notas
    float notas[100];

    // Vetor para armazenar os nomes das provas
    char* provas[] = {
        "Raciocínio lógico", 
        "Conceitos de gerenciamento de projetos", 
        "Língua inglesa", 
        "Conceitos de metodologia ágil", 
        "Linguagem Javascript"
    };

    for (i = 0; i < 5; i++) {  // Supondo que o candidato faz exatamente 5 provas
        // Entrada do número de notas
        scanf("%d", &n);
        if (n == 0) break;  // Termina a entrada se N for 0
        
        // Entrada das notas
        for (int j = 0; j < n; j++) {
            scanf("%f", &notas[j]);
        }

        // Calcula a nota da prova atual
        float notaAtual = calcularNota(notas, n);
        notaFinal += notaAtual;

        // Exibe a nota da prova atual
        printf("Nota %s = %.0f\n", provas[i], notaAtual);
    }

    // Exibe a nota final do candidato
    printf("Nota final do candidato = %.0f\n", notaFinal);

    return 0;
}