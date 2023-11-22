#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TENTATIVAS 6
#define TAMANHO_PALAVRA 20
#define MAX_JOGADORES 10

enum Ranks{
	Perfeito = 6,
	Excelente = 5,
	Otimo = 4,
	Bom = 3,
	Mediano = 2,
	Ruim = 1,
	Pessimo = 0
};

typedef struct Ranking{
	enum Ranks ranking;
	char NomePlayers[3][2];
    int Points[3];
} RANKING;


void mostrarRank(RANKING rank[], int Num_players){
	printf("\n --- RANKING --- \n");
	int i,j;
	for(i = 0; i < Num_players; i++){
		for(j = 0; j < Num_players; j++){
			printf("%d. %s - Pontuação: %d",i+1,rank[j].NomePlayers[i][j],rank[j].Points[j]);
		}
	}
}

void salvarRank(RANKING rank[], int Num_players){
	FILE *arquivo = fopen("ranking.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de ranking.\n");
        return;
    }
    
    int i,j;
    /*for (i = 0; i < Num_players; i++) {
        fprintf(arquivo, "%s %d\n", ranking[i].nome, ranking[i].pontuacao);
    }*/
    for(i = 0; i < Num_players; i++){
    	for(j = 0; j < Num_players; j++){
    		fprintf(arquivo, "%s %d\n", rank[j].NomePlayers[i][j], rank[j].Points[j]);
		}
	}

    fclose(arquivo);
}

void carregarRank(RANKING rank[], int Num_players){
	FILE *arquivo = fopen("ranking.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo de ranking não encontrado. Criando um novo.\n");
        return;
    }
    
    Num_players = 0;

    while (Num_players < MAX_JOGADORES && fscanf(arquivo, "%s %d", rank[Num_players].NomePlayers[Num_players][Num_players], &rank[Num_players].Points[Num_players]) == 2) {
        (Num_players)++;
    }

    fclose(arquivo);
}

void adicionarPlayerRank(RANKING rank[], int Num_players, char nomeJogador[], int Pontuation){
	if (Num_players < MAX_JOGADORES) {
        strcpy(rank[Num_players].NomePlayers[Num_players][Num_players], nomeJogador);
        rank[Num_players].Points[Num_players] = Pontuation;
        (Num_players)++;
    } else {
        printf("O ranking está cheio. Não é possível adicionar mais jogadores.\n");
    }
}
