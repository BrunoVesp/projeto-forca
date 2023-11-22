/* 
	BANCO DE PALAVRAS:

	10 palavras fixas 
	
	Cadastra novas palavras ao jogo.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define tamanho_palavra 50 // Tamanho m�ximo para cada palavra.
#define tamanho_vetor 20 // Vetor para quantidade de palavras.

void gerenciarPalavras() {
	/* Vari�vel char bancoPalavras que cont�m o n�mero m�ximo de caracteres de cada palavra
	e um vetor para a quantidade de palavras: */
	char bancoPalavras[tamanho_vetor][tamanho_palavra];
	// Contador de palavras j� iniciando em 10, que s�o as palavras ocultas ao usu�rio:
	int qtd_palavras = 10;
	int i;
	int opcao;
	
	/* Utilizando a fun��o strcpy, 
	copia o valor da string na segunda posi��o do argumento("palavra1"), para uma vari�vel
	string na primeira posi��o ("bancoPalavras[0]").
	Sendo poss�vel escolher qual palavra ser� e atribuindo ela a posi��o do vetor: */
	strcpy(bancoPalavras[0], "palavra1");
	strcpy(bancoPalavras[1], "palavra2");
	strcpy(bancoPalavras[2], "palavra3");
	strcpy(bancoPalavras[3], "palavra4");
	strcpy(bancoPalavras[4], "palavra5");
	strcpy(bancoPalavras[5], "palavra6");
	strcpy(bancoPalavras[6], "palavra7");
	strcpy(bancoPalavras[7], "palavra8");
	strcpy(bancoPalavras[8], "palavra9");
	strcpy(bancoPalavras[9], "palavra10");
	
	// While(1) para o programa estar sempre rodando:
	while(1) {
		// Menu para o usu�rio:
		printf("Quantidade m�xima de c�modos � 20.\n");
		printf("N�mero de palavras no banco: %d.\n", qtd_palavras);
		printf("\n-----MENU-----\n");
		printf("1. Cadastrar palavra.\n");
		printf("2. Sair.\n");
		scanf("%d", &opcao); // Lendo op��o desejada pelo usu�rio.
		
		switch(opcao) {
			// Caso o usu�rio escolha 1 (Adicionar palavra):
			case 1:
				// Se a quantidade de palavras for menor que 20 (M�ximo), executa normalmente.
				if (qtd_palavras < tamanho_vetor) {
					printf("Digite a palavra que deseja cadastrar: ");
					// Lendo palavra informada pelo usu�io:
					scanf("%s", &bancoPalavras[qtd_palavras]);
					qtd_palavras++; // Adiciona uma unidade a quantidade de palavras.
					system("cls");
					printf("-----Palavra cadastrada com sucesso!-----\n");
				}
				else {
					printf("Banco de palavras j� est� cheio.\n");
				}
				break;
			case 2:
				printf("Saindo.\n");
				return;
			default:
				printf("Op��o inv�lida. Tente novamente!\n");	
		}
	}
}
int Bancos() {
	gerenciarPalavras();
}
