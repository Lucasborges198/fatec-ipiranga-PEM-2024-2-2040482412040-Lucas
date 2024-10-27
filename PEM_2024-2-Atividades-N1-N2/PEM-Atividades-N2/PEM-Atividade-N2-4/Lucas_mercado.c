#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

// Definindo a estrutura do produto
typedef struct {
    int id;
    char nome[50];
    char descricao[100];
    float preco;
    int quantidade;
} Produto;

// Função para inserir produtos
void inserirProduto(Produto *produtos, int *contador) {
    if (*contador >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto novoProduto;

    printf("Informe o ID do produto: ");
    scanf("%d", &novoProduto.id);
    getchar(); // Limpa o buffer do teclado

    printf("Informe o nome do produto: ");
    fgets(novoProduto.nome, 50, stdin);
    novoProduto.nome[strcspn(novoProduto.nome, "\n")] = 0; // Remove a nova linha

    printf("Informe a descricao do produto: ");
    fgets(novoProduto.descricao, 100, stdin);
    novoProduto.descricao[strcspn(novoProduto.descricao, "\n")] = 0;

    printf("Informe o preco unitario: ");
    scanf("%f", &novoProduto.preco);

    printf("Informe a quantidade disponivel em estoque: ");
    scanf("%d", &novoProduto.quantidade);

    produtos[*contador] = novoProduto;
    (*contador)++;
    printf("Produto inserido com sucesso!\n");
}

// Função para listar produtos
void listarProdutos(Produto *produtos, int contador) {
    if (contador == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    // Bubble Sort para ordenar os produtos por nome
    for (int i = 0; i < contador - 1; i++) {
        for (int j = 0; j < contador - i - 1; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }

    printf("Lista de Produtos:\n");
    for (int i = 0; i < contador; i++) {
        printf("ID: %d, Nome: %s, Descricao: %s, Preco: %.2f, Quantidade: %d\n",
               produtos[i].id, produtos[i].nome, produtos[i].descricao,
               produtos[i].preco, produtos[i].quantidade);
    }
}

// Função para simular a compra
void comprarProduto(Produto *produtos, int contador) {
    int idProduto, quantidadeDesejada;
    printf("Informe o ID do produto que deseja comprar: ");
    scanf("%d", &idProduto);

    // Busca pelo produto
    for (int i = 0; i < contador; i++) {
        if (produtos[i].id == idProduto) {
            printf("Produto encontrado: %s, Preco: %.2f\n", produtos[i].nome, produtos[i].preco);
            printf("Informe a quantidade que deseja comprar: ");
            scanf("%d", &quantidadeDesejada);

            // Verifica estoque
            if (quantidadeDesejada > produtos[i].quantidade) {
                printf("Estoque insuficiente! Apenas %d disponíveis.\n", produtos[i].quantidade);
            } else {
                produtos[i].quantidade -= quantidadeDesejada;
                printf("Compra realizada com sucesso! Total: %.2f\n",
                       quantidadeDesejada * produtos[i].preco);
            }
            return;
        }
    }

    printf("Produto Inexistente.\n");
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int contador = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Comprar produto\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirProduto(produtos, &contador);
                break;
            case 2:
                listarProdutos(produtos, contador);
                break;
            case 3:
                comprarProduto(produtos, contador);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}