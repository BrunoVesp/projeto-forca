/*
Menu de Jogo
*/

//Bibliotecas externas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Biblioteca Interna
#include "Jogo.h"
/*
int main(){
	int gameOp;
	int gameOp2;
	int gameOp3;
	int gameOp4;
	int gameOp5;
	do{
		//opções do jogador(MENU)
		printf("--- JOGO DA FORCA ---\n");
		printf("[ 1 ] JOGAR\n");
		printf("[ 2 ] RANKING\n");
		printf("[ 3 ] ADICIONAR PALAVRAS\n");
		printf("[ 4 ] CRÉDITOS\n");
		printf("[ 5 ] SAIR\n");
		
		//Escolha do usuário
		printf(" ");
		scanf("%d", &gameOp);
		system("cls");
		
		//Switch de Cenários
		switch(gameOp){
			case 1:
				Jogo();
				break;
			case 2:
			case 3:
			case 4:
				printf("--- Desenvolvedores ---\n");
				printf("Lider do projeto e Programador:\n - Caio Justino\n");
				printf("Programadores:\n - Paulo Fernandes\n - Caio Araújo\n - Bruno Hebert\n - Marllon Brenno\n");
				printf("Obrigado pelo Suporte\n");
				
				printf("[ 1 ] Voltar\n");
				scanf("%d", &gameOp4);
				system("cls");
				if(gameOp2 == 1){
					continue;
				}
				system("cls");
				break;
				
				break;
			case 5:
				printf("Certeza de que deseja fechar o Jogo ?\n");
				printf("      [ 1 ]Fechar      [2]Voltar\n");
				scanf("%d", &gameOp5);
				system("cls");
				if(gameOp2 == 1){
					printf("Certo,fechando jogo...");
					continue;
				}
				else if(gameOp2 == 2){
					printf("Certo,voltando ao jogo...");
					continue;
				}
				system("cls");
				break;
				
			default:
				break;
		}
	}while(gameOp5 != 1);
}*/

int main(){
	nomes[3][10];
	
}

