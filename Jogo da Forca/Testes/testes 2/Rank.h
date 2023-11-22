/*
Sistema de Rank
*/

//Bibliotecas externas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//Definições de suporte
#define MAX_TENTATIVAS 6
#define TAMANHO_PALAVRA 20
#define MAX_JOGADORES 10

typedef struct Ranks{
    char nome[50];
    int pontuacao;
} Jogador;

void exibirRanking(Jogador ranking[], int numJogadores) {
    printf("\n--- RANKING ---\n");
    for (int i = 0; i < numJogadores; i++) {
        printf("%d. %s - Pontuação: %d\n", i + 1, ranking[i].nome, ranking[i].pontuacao);
    }
}

void salvarRanking(Jogador ranking[], int numJogadores) {
    FILE *arquivo = fopen("ranking.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de ranking.\n");
        return;
    }

    for (int i = 0; i < numJogadores; i++) {
        fprintf(arquivo, "%s %d\n", ranking[i].nome, ranking[i].pontuacao);
    }

    fclose(arquivo);
}

void carregarRanking(Jogador ranking[], int *numJogadores) {
    FILE *arquivo = fopen("ranking.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo de ranking não encontrado. Criando um novo.\n");
        return;
    }

    *numJogadores = 0;

    while (*numJogadores < MAX_JOGADORES && fscanf(arquivo, "%s %d", ranking[*numJogadores].nome, &ranking[*numJogadores].pontuacao) == 2) {
        (*numJogadores)++;
    }

    fclose(arquivo);
}

void adicionarJogadorRanking(Jogador ranking[], int *numJogadores, char nomeJogador[], int pontuacao) {
    if (*numJogadores < MAX_JOGADORES) {
        strcpy(ranking[*numJogadores].nome, nomeJogador);
        ranking[*numJogadores].pontuacao = pontuacao;
        (*numJogadores)++;
    } else {
        printf("O ranking está cheio. Não é possível adicionar mais jogadores.\n");
    }
}
