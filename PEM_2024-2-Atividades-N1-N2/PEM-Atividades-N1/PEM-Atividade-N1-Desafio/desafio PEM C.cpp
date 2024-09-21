/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular           *
*          Prof. Carlos Veríssimo                         *
*--------------------------------------------------------*
* Objetivo do Programa: Refatorando para modularizar código *
* Data - 12/09/2024                                       * 
* Autor: Lucas Borges Ribeiro, Kauan Torres              *
*--------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAMANHO_PILHA 4
// Funcao para exibir a pilha
void exibirPilha(int pilha[])
{
	printf("Pilha: [T: %d] [Z: %d] [Y: %d] [X: %d]\n",
	       pilha[3], pilha[2], pilha[1], pilha[0]);
}
// Funcao para empurrar valores na pilha
void empurrar(int pilha[], int valor)
{
	for (int i = TAMANHO_PILHA - 1; i > 0; i--)
	{
		pilha[i] = pilha[i - 1];
	}
	pilha[0] = valor;
}
// Funcao para executar a operacao entre os dois primeiros operandos da pilha
void executarOperacao(int pilha[], char operador)
{
	int resultado;
	// Operacao entre o penultimo (pilha[1]) e o ultimo
	if (operador == '+')
	{
		resultado = pilha[1] + pilha[0];
	}
	else if (operador == '-')
	{
		resultado = pilha[1] - pilha[0];
	}
	else if (operador == '*')
	{
		resultado = pilha[1] * pilha[0];
	}
	else if (operador == '/')
	{
		if (pilha[0] == 0)
		{
			printf("Erro: Divisao por zero nao permitida.\n");
			return;
		}
		resultado = pilha[1] / pilha[0];
	}
	else
	{
		printf("Operador invalido!\n");
		return;
	}
	// Atualizar a pilha com o resultado da operacao
	pilha[0] = resultado;
	for (int i = 1; i < TAMANHO_PILHA - 1; i++)
	{
		pilha[i] = pilha[i + 1]; // Shift nos valores para liberar espaco
	}
	pilha[TAMANHO_PILHA - 1] = 0; // Limpa o topo da pilha
}
int main()
{
	int pilha[TAMANHO_PILHA] = {0, 0, 0, 0}; // Inicializando a pilha com zeros
	char entrada[100];
	// Para armazenar a entrada do usuario
	char continuar;
	printf("Bem-vindo a Calculadora Fatec-HP12c!\n");
	do
	{
		printf("\nDigite a expressao em formato RPN (ex: 5 1 2 + 4 * +3) ou 'sair' para encerrar : ");
		fgets(entrada, sizeof(entrada), stdin); // Le a entrada do usuario
		// Verificar se o usuario deseja sair
		if (strncmp(entrada, "sair", 4) == 0)
		{
			break;
		}
		// Dividir a entrada em tokens (numeros e operadores)
		char *token = strtok(entrada, " ");
		while (token != NULL)
		{
			// Verifica se o token e um numero (operando)
			if (isdigit(token[0]) || (token[0] == '-' &&
			                          isdigit(token[1])))
			{
				int valor = atoi(token); // Converte o token para numero inteiro
				empurrar(pilha, valor); // Empurra o numero para a pilha
				exibirPilha(pilha); // Exibe o estado da pilha
			}
			// Caso contrario, trata-se de um operador
			else
			{
				executarOperacao(pilha, token[0]); // Executa a operacao
				exibirPilha(pilha); // Exibe o estado da pilha
			}
			token = strtok(NULL, " "); // Avanca para o	proximo token
		}
		printf("\nResultado final: %d\n", pilha[0]); // Exibe o resultado final
		// Pergunta ao usuario se deseja realizar outra operacao
		printf("\nDeseja realizar outra operacao? (s/n): ");
		scanf(" %c", &continuar);
		getchar(); // Limpa o buffer
	} while (continuar == 's' || continuar == 'S');
	// Mensagem de encerramento
	printf("Obrigado por usar nossa Calculadora FatecHP12c!\n");
	return 0;
}