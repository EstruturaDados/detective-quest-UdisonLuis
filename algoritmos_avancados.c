#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.

typedef struct Sala {
    char nome [50];
    struct Sala *esquerda;
    struct Sala *direita;
}Sala;

// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.
Sala* criarSala(char nome[]) {
    Sala *novaSala = (Sala*)malloc(sizeof(Sala));

    if(novaSala ==NULL) {
        printf("Erro de alocação de memoria\n");
        exit(1);
    }

    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;

    return novaSala;
}

void explorarSalas(Sala *atual) {
    char opcao;

    while (atual != NULL) {

        printf("\n===============================");
        printf("\nVoce esta em: %s\n", atual->nome);

        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Este comodo não possui mais caminhos.\n");
            printf("Fim da exploracao!\n");
            break;    
        }

        printf("\nCaminhos disponiveis:\n");

        if (atual->esquerda != NULL)
            printf("E - Ir Para a esquerda\n");

        if (atual->direita != NULL)
            printf("D - Ir para a direita\n");

        printf("S - Ssair da exploração\n");

        printf("\nEscolha: ");
        scanf(" %c", &opcao);

        if (opcao == 'e' || opcao == 'E') {

            if (atual->esquerda != NULL) {
                atual = atual->esquerda;
            } else {
                printf("Nao existe caminho para a esquerda!\n");
            }

        } else if(opcao == 'd' || opcao == 'D') {

            if (atual->direita != NULL) {
                atual = atual->direita;
            } else {
                printf("Nao existe caminho para a direita!\n");
            }

        } else if (opcao =='s' || opcao == 'S') {

            printf("\nExploracao encerradapelo jogador.\n");
            break;

        } else {

            printf("Opcao invalida!\n");
        }
    }
}

void liberarMemoria(Sala *raiz) {
    if (raiz == NULL)
    return;

    liberarMemoria(raiz->esquerda);
    liberarMemoria(raiz->direita);

    free(raiz);
}

int main() {

    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
    // - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
    // - Use funções como criarSala(), conectarSalas() e explorarSalas().
    // - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
    // - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
   
    Sala *hall = criarSala("Hall de Entrada");

    hall->esquerda = criarSala("Sala de Estar");
    hall->direita = criarSala("Biblioteca");

    hall->esquerda->esquerda = criarSala("Cozinha");
    hall->esquerda->direita = criarSala("Jardim");

    hall->direita->esquerda = criarSala("Escritorio");
    hall->direita->direita = criarSala("sala Secreta");

    printf("==============================\n");
    printf("      EXPLORANDO A MANSAO     \n");
    printf("==============================\n");

    explorarSalas(hall);

    liberarMemoria(hall);


     // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
    // - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().

    return 0;
}

