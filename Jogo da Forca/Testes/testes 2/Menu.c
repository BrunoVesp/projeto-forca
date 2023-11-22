/*
Menu - Jogo da Forca
*/

//Bibliotecas Externas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Biblioteca Interna
#include "Jogos.h"
#include "Banco.h"
#include "Rank.h"

//Funções de Menus
//->Menu de jogo
void menuJogo(){
	int op_menu_jogo;
	do{
		printf("---\n Bem Vindo ao Jogo da Forca \n---\n");
		printf("[ 1 ] Iniciar Jogo\n");
		printf("[ 2 ] Tutorial/Regras\n");
		printf("[ 3 ] Menu Principal\n");
		scanf("%d", &op_menu_jogo);
		system("cls");
		
		switch(op_menu_jogo){
			case 1:
				Jogo();
				break;
			case 2:
				printf("Objetivos do jogo\nRegras:\n");
				printf("- Cada jogador tem 6 tentativas em caso de falha\n");
				printf("- Os jogadores irão refezar os chutes a cada tentativa\n");
				printf("[ 1 ] Voltar");
				scanf("%d",&p1_switch);
				system("cls");
				break;
			case 3:
				break;
			default:
				break;
		}
	}while(1);
}

//->Menu de Ranking
void menuRank(){
	int op_menu_rank;
	int p2_switch;
	do{
		printf("---\n Bem Vindo ao Ranking do Jogo \n---");
		printf("[ 1 ] Mostrar Ranking\n");
		printf("[ 2 ] Menu Principal\n");
		scanf("%d", &op_menu_rank);
	
		switch(op_menu_rank){
			case 1:
				exibirRank();
				break;
			case 2:
				break;
			default:
				break;
		}
	}while(op_menu_rank);
}

//->Menu Banco
void menuBanco(gameOp3){
	do{
		printf("---\n Banco de Palavras \n---");
		printf("[ 1 ] Cadastrar Palavras");
		printf("[ 2 ] Menu Principal");
		scanf("%d", &gameOp3);

		switch(gameOp3){
			case 1:
				BancoPalavra();
				break;
			case 2:
				main();
				break;
			default:
				break;
		}
	}while(gameOp != 2);
	
}

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
				menuJogo();
				break;
			case 2:
				menuRank();
				break;
			case 3:
				Bancos();
				break;
			case 4:
				//menuCreditos();
				break;
			case 5:
				printf("Certeza de que deseja fechar o Jogo ?\n");
				printf("      [ 1 ]Fechar      [2]Voltar\n");
				scanf("%d", &gameOp5);
				system("cls");
				if(gameOp5 == 1){
					printf("Certo,fechando jogo...");
					continue;
				}
				else if(gameOp5 == 2){
					printf("Certo,voltando ao jogo...");
					continue;
				}
				system("cls");
				break;
			default:
				break;
		}
	}while(gameOp5 != 1);
}
