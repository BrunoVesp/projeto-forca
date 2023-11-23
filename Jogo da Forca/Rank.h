/*
Sistema de Rank
*/

//Bibliotecas externas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void copiarRank(FILE *rfile1, FILE *rfile2){
	char nomeRank[500];
	
	while (fgets(nomeRank, 500, rfile1)) {
        fprintf(rfile2, "%s", nomeRank);
    }
}

void armazenaRank(FILE *rfile2){
	setlocale(0, "portuguese");
	
	if (rfile2 == NULL) {
        printf("Arquivo não encontrado.\n");
        system("pause");
        exit(1);
    }
	
	char nomeWin[5];
	printf("Informe seu nome para o Ranking");
	scanf("%s", nomeWin);
	fprintf(rfile2,"\n");
    fputs(nomeWin, rfile2);
}

void mostrarRank(FILE *rfile1){
	setlocale(0, "portuguese");
	
	if (rfile1 == NULL) {
        printf("Arquivo não encontrado.\n");
        system("pause");
        exit(1);
    }
    
    char mRank[100];
    while(fgets(mRank,100,rfile1) != NULL){
    	printf("%s",mRank);
	}
	printf("\n");
    system("pause");
}

void Rank(){
	setlocale(0, "portuguese");
	
	FILE *rfile1 = fopen("LeRanking.txt","r");
	if (rfile1 == NULL) {
        printf("Arquivo não encontrado.\n");
        system("pause");
        exit(1);
    }
	FILE *rfile2 = fopen("Ranking.txt","r+");
		 
    if (rfile2 == NULL) {
        printf("Arquivo não encontrado.\n");
        system("pause");
        exit(1);
    }
    
    //copiarRank(rfile1,rfile2);
    
    int gameOp3;
    printf("---\n Bem Vindo ao Ranking do Jogo \n---\n");
	printf("[ 1 ] Mostrar Ranking\n");
	printf("[ 2 ] Menu Principal\n");
	scanf("%d", &gameOp3);
	
	copiarRank(rfile2,rfile1);
	
	switch(gameOp3){
		case 1:
			copiarRank(rfile2,rfile1);
			mostrarRank(rfile1);
			break;
		case 2:
			copiarRank(rfile2,rfile1);
			break;
		default:
			break;
	}
}
