/*--------------------------------------------------------*
* Disciplina: Programacao Estruturada e Modular           *
*          Prof. Carlos Verissimo                         *                                
*---------------------------------------------------------*
* Objetivo do Programa: Calculadora HP12c                 *
* Data : 15/09/2024                                       * 
* Autor: Kauan Torres, Lucas Borges, Lucas Marum          *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*---------------------------------------------------------*
| Módulo Operação - Realizar as operações                  |
*---------------------------------------------------------*/

int operacao(int a, int b, char operador) {
    switch (operador) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}

/*---------------------------------------------------------*
| Módulo de Processamento - Processa a string              |
*---------------------------------------------------------*/

int processarString(char *string) {
    int i = 0;
    int pilha[3];  
    char *tok = strtok(string, " ");  // Divisão da string através do espaço " "

    while (tok != NULL) { //Verifica até acabar
        if (strcmp(tok, "+") == 0 || strcmp(tok, "-") == 0 || strcmp(tok, "*") == 0 || strcmp(tok, "/") == 0) { //Verificar operador
            int resultado = operacao(pilha[i-2], pilha[i-1], tok[0]);
            i -= 2; 
            pilha[i] = resultado;
            i++;  
        } else {
            pilha[i] = atoi(tok);
            i++;
        }
        // Obtém o próximo token
        tok = strtok(NULL, " ");
    }
    return pilha[i-1];  
}


/*---------------------------------------------------------*
| Módulo Entrada - Recebear a entrada                      |
*---------------------------------------------------------*/

void entrada(char *string){
    printf("Digite a entrada da formula no formato RPN com espacos. EXEMPLO: (4 3 +) \n");
    fgets(string, 1000, stdin);  
    string[strcspn(string, "\n")] = 0;  // Remoção da quebra de linha ao final
}

/*---------------------------------------------------------*
| Módulo de Saída - Exibe o resultado final                |
*---------------------------------------------------------*/

void saida(int resultado) {
    printf("Resultado final: %d\n", resultado);
}

/*---------------------------------------------------------*
| Módulo Continuar - Recebe resposta para continuar ou não |
*---------------------------------------------------------*/

int continuar(){
	int resp;
	printf("Deseja realizar uma nova entrada ? Digite o numero correspondente: \n 1 - (SIM) \n 2 - (NAO) \n");
    scanf("%i", &resp);
	getchar(); //Limpeza do buffer de entrada, pois estava bugando pois estava recebendo o \n do scanf.
	return resp;
}

/*---------------------------------------------------------*
| Módulo Principal - Controla o fluxo                      |
*---------------------------------------------------------*/

int main() {
    int i = 0;
    int pilha[3];  
    char string[1000];
	int resp; 
    
    do{
	    //Chama modulo para capturar entrada
		entrada(string);
	
		//Chama modulo para processar string
		int resultado = processarString(string);  
	    
	    //Chama modulo de saida
	    saida(resultado);
	    
	    //Chama modulo da resposta
	    resp = continuar();
	    
	} while (resp == 1);
	
    printf("Obrigado por usar nossa Calculador Fatec-HP12c");

    return 0;
}


