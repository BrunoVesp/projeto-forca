/*
Sistema de Rank
*/

//Bibliotecas externas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void armazenaRank(FILE *rfile){
	if (rfile == NULL) {
        printf("Arquivo não encontrado.\n");
        system("pause");
        exit(1);
    }
	
	char nomeWin[5];
	printf("Informe seu nome para o Ranking");
	scanf("%s", nomeWin);
	fprintf(rfile,"\n");
    fputs(nomeWin, rfile);
}

void mostrarRank(FILE *rfile){
	if (rfile == NULL) {
        printf("Arquivo não encontrado.\n");
        system("pause");
        exit(1);
    }
    
    char mRank[100];
    while(fgets(mRank,100,rfile) != NULL){
    	printf("%s",mRank);
	}
}

void Rank(){
	FILE *rfile;
	rfile = fopen("ranking.txt","a");
	if (rfile == NULL) {
        printf("Arquivo não encontrado.\n");
        system("pause");
        exit(1);
    }
    int gameOp3;
    printf("---\n Bem Vindo ao Ranking do Jogo \n---");
	printf("[ 1 ] Mostrar Ranking\n");
	printf("[ 2 ] Menu Principal\n");
	scanf("%d", &gameOp3);
	
	switch(gameOp3){
		case 1:
			mostrarRank(rfile);
			system("pause");
			break;
		case 2:
		default:
			break;
	}
}
