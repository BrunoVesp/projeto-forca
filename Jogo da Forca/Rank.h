/*
Sistema de Rank
*/

//Bibliotecas externas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copiarRank(FILE *rfile1_2, FILE *rfile2){
	char nomeRank[500];
	
	while (fgets(nomeRank, 500, rfile2)) {
        fprintf(rfile1_2, "%s", nomeRank);
    }
}

void armazenaRank(FILE *rfile2){
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
	FILE *rfile1 = fopen("LeRanking.txt","r");
	if (rfile1 == NULL) {
        printf("Arquivo não encontrado.\n");
        system("pause");
        exit(1);
    }
    FILE *rfile1_2 = fopen("LeRanking.txt","a");
    
    
	FILE *rfile2 = fopen("Ranking.txt","a");	 
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
	
	copiarRank(rfile1_2,rfile2);
	
	switch(gameOp3){
		case 1:
			copiarRank(rfile1_2,rfile2);
			mostrarRank(rfile1);
			break;
		case 2:
			copiarRank(rfile1_2,rfile2);
			break;
		default:
			break;
	}
}
