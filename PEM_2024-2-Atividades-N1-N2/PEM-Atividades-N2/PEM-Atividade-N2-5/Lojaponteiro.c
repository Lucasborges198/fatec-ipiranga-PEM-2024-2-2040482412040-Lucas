/*Disciplina: Programação Estruturada e Modular*/
/*Prof. Carlos Veríssimo*/
/*06/11/2024*/
/*Lucas Borges Ribeiro*/
/* Disciplina: Programação Estruturada e Modular */
/* Prof. Carlos Veríssimo */
/* 06/11/2024 */
/* Lucas Borges Ribeiro */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANHO_NOME 100
#define MAX_PRODUTOS 500
#define INICIO 0

int caracter;
struct Item {
    int id;
    char nome[TAMANHO_NOME];
    int estoque;
    float preco;
};

int exibirMenu();
void adicionarItem(struct Item *itens, int *qtdItens, int *itensRemovidos);
void modificarItem(struct Item *itens, int *qtdItens);
void removerItem(struct Item *itens, int *qtdItens, int *itensRemovidos);
void realizarCompra(struct Item *itens, int *qtdItens);
void consultarItem(struct Item *itens, int *qtdItens);
void listarItens(struct Item *itens, int *qtdItens, int inicio);
void ajustarOrdemItens(struct Item *itens, int indice);
int validarCodigo(struct Item *itens, int *qtdItens, int codigoItem);
int confirmarAcao();

int main() {
    int continuar = 1, qtdItens = 0, itensRemovidos = 0;
    struct Item itens[MAX_PRODUTOS];
    
    while (continuar) {
        switch (exibirMenu()) {
            case 0:
                printf("Obrigado por usar o sistema!\n");
                return 0;
            case 1:
                if (qtdItens == MAX_PRODUTOS) {
                    printf("Capacidade máxima atingida. Remova um item antes de adicionar novos.\n");
                    break;
                }
                adicionarItem(itens, &qtdItens, &itensRemovidos);
                break;
            case 2:
                modificarItem(itens, &qtdItens);
                break;
            case 3:
                removerItem(itens, &qtdItens, &itensRemovidos);
                break;
            case 4:
                realizarCompra(itens, &qtdItens);
                break;
            case 5:
                consultarItem(itens, &qtdItens);
                break;
            case 6:
                listarItens(itens, &qtdItens, INICIO);
                break;
            default:
                printf("Opção inválida.\n");
        }
    }
    return 0;
}

int exibirMenu() {
    int opcao;
    printf("\nEscolha uma opção:\n");
    printf("0 - Sair\n");
    printf("1 - Adicionar item\n");
    printf("2 - Modificar item\n");
    printf("3 - Remover item\n");
    printf("4 - Realizar compra\n");
    printf("5 - Consultar item\n");
    printf("6 - Listar todos os itens\n");
    scanf("%d", &opcao);
    while ((caracter = getchar()) != '\n' && caracter != EOF);
    return opcao;
}

void adicionarItem(struct Item *itens, int *qtdItens, int *itensRemovidos) {
    struct Item *novoItem = &itens[*qtdItens];
    novoItem->id = *qtdItens + *itensRemovidos + 1;
    
    printf("Informe o nome do item: ");
    fgets(novoItem->nome, TAMANHO_NOME, stdin);
    printf("Informe o preço do item: ");
    scanf("%f", &novoItem->preco);
    printf("Informe a quantidade em estoque: ");
    scanf("%d", &novoItem->estoque);
    while ((caracter = getchar()) != '\n' && caracter != EOF);
    
    (*qtdItens)++;
}

void modificarItem(struct Item *itens, int *qtdItens) {
    int codigo, opcao, indice;
    
    printf("Digite o código do item para modificar: ");
    scanf("%d", &codigo);
    
    if ((indice = validarCodigo(itens, qtdItens, codigo)) < 0) return;
    
    while (1) {
        printf("O que deseja modificar em '%s'?\n", itens[indice].nome);
        printf("0 - Sair\n1 - Nome\n2 - Preço\n3 - Quantidade\n");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 0: return;
            case 1: {
                printf("Novo nome: ");
                scanf("%s", itens[indice].nome);
                break;
            }
            case 2: {
                printf("Novo preço: ");
                scanf("%f", &itens[indice].preco);
                break;
            }
            case 3: {
                printf("Nova quantidade: ");
                scanf("%d", &itens[indice].estoque);
                break;
            }
            default: printf("Opção inválida.\n");
        }
        
        printf("Deseja fazer mais alterações neste item?\n");
        if (!confirmarAcao()) break;
    }
}

void removerItem(struct Item *itens, int *qtdItens, int *itensRemovidos) {
    int codigo, indice;
    
    printf("Digite o código do item para remover: ");
    scanf("%d", &codigo);
    
    if ((indice = validarCodigo(itens, qtdItens, codigo)) < 0) return;
    
    printf("Confirmar remoção de '%s'?\n", itens[indice].nome);
    if (!confirmarAcao()) return;
    
    for (int i = indice; i < *qtdItens - 1; i++) {
        ajustarOrdemItens(itens, i);
    }
    
    (*qtdItens)--;
    (*itensRemovidos)++;
    printf("Item removido com sucesso.\n");
}

void realizarCompra(struct Item *itens, int *qtdItens) {
    int codigo, quantidade, indice;
    
    printf("Digite o código do item para comprar: ");
    scanf("%d", &codigo);
    
    if ((indice = validarCodigo(itens, qtdItens, codigo)) < 0) return;
    
    printf("Quantidade a comprar (em estoque: %d): ", itens[indice].estoque);
    scanf("%d", &quantidade);
    
    if (quantidade > itens[indice].estoque) {
        printf("Estoque insuficiente.\n");
        return;
    }
    
    float total = quantidade * itens[indice].preco;
    printf("Valor total: R$%.2f\nConfirmar compra?\n", total);
    if (confirmarAcao()) {
        itens[indice].estoque -= quantidade;
        printf("Compra realizada com sucesso!\n");
    }
}

void consultarItem(struct Item *itens, int *qtdItens) {
    int codigo, indice;
    
    printf("Digite o código do item para consultar: ");
    scanf("%d", &codigo);
    
    if ((indice = validarCodigo(itens, qtdItens, codigo)) < 0) return;
    
    listarItens(itens, &indice, indice);
}

void listarItens(struct Item *itens, int *qtdItens, int inicio) {
    printf("\n---------------------------------------------\n");
    printf("| ID   | Nome   | Preço   | Estoque |\n");
    for (int i = inicio; i < *qtdItens; i++) {
        printf("| %-4d | %-18s | %-7.2f | %-7d |\n", itens[i].id, itens[i].nome, itens[i].preco, itens[i].estoque);
    }
    printf("---------------------------------------------\n");
}

void ajustarOrdemItens(struct Item *itens, int indice) {
    itens[indice] = itens[indice + 1];
}

int validarCodigo(struct Item *itens, int *qtdItens, int codigo) {
    for (int i = 0; i < *qtdItens; i++) {
        if (itens[i].id == codigo) return i;
    }
    printf("Item não encontrado.\n");
    return -1;
}

int confirmarAcao() {
    int opcao;
    printf("0 - Não / 1 - Sim\n");
    scanf("%d", &opcao);
    return opcao == 1;
}
