/* 
	BANCO DE PALAVRAS:

	10 palavras fixas 
	
	Cadastra novas palavras ao jogo.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define tamanho_palavra 50 // Tamanho máximo para cada palavra.
#define tamanho_vetor 20 // Vetor para quantidade de palavras.

void gerenciarPalavras() {
	/* Variável char bancoPalavras que contém o número máximo de caracteres de cada palavra
	e um vetor para a quantidade de palavras: */
	char bancoPalavras[tamanho_vetor][tamanho_palavra];
	// Contador de palavras já iniciando em 10, que são as palavras ocultas ao usuário:
	int qtd_palavras = 10;
	int i;
	int opcao;
	
	/* Utilizando a função strcpy, 
	copia o valor da string na segunda posição do argumento("palavra1"), para uma variável
	string na primeira posição ("bancoPalavras[0]").
	Sendo possível escolher qual palavra será e atribuindo ela a posição do vetor: */
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
		// Menu para o usuário:
		printf("Quantidade máxima de cômodos é 20.\n");
		printf("Número de palavras no banco: %d.\n", qtd_palavras);
		printf("\n-----MENU-----\n");
		printf("1. Cadastrar palavra.\n");
		printf("2. Sair.\n");
		scanf("%d", &opcao); // Lendo opção desejada pelo usuário.
		
		switch(opcao) {
			// Caso o usuário escolha 1 (Adicionar palavra):
			case 1:
				// Se a quantidade de palavras for menor que 20 (Máximo), executa normalmente.
				if (qtd_palavras < tamanho_vetor) {
					printf("Digite a palavra que deseja cadastrar: ");
					// Lendo palavra informada pelo usuáio:
					scanf("%s", &bancoPalavras[qtd_palavras]);
					qtd_palavras++; // Adiciona uma unidade a quantidade de palavras.
					system("cls");
					printf("-----Palavra cadastrada com sucesso!-----\n");
				}
				else {
					printf("Banco de palavras já está cheio.\n");
				}
				break;
			case 2:
				printf("Saindo.\n");
				return;
			default:
				printf("Opção inválida. Tente novamente!\n");	
		}
	}
}
int Bancos() {
	gerenciarPalavras();
}
