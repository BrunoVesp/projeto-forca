/*
Teste do Jogo
*/

//Bibliotecas Externas Usadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//Bibliotecas Internas Usadas


//Definições utilizadas
#define MAX_TENTATIVAS 6
#define TAMANHO_PALAVRA 20
#define MAX_JOGADORES 10

/*
Em resumo,temos a base do jogo original com algumas adições para ajustes
- Nota-se a capacidade de se ter Multijogadores ou solo
- O aramazenamento dos Jogadores para o Ranking
- A funcionaliade do jogo em si

Falta fazer:
- se acertar todas as letras ganhar direto;
- Permitir dizer a palavra e ganhar ou perder o jogo
- Calcular a pontuação

*/

//Responsável pelo buffer de entrada das letras dos jogadores
void limparBufferEntrada(){
	int ch;
	while((ch = getchar()) != '\n' && ch != EOF);
}

//Responsável pelo sistema de exibição de letras e palavras do banco de dados
void mostrarPalavra(char palavra[], char letrasCorretas[]){
	int i;
	for(i = 0; i <strlen(palavra); i++){
		if(strchr(letrasCorretas, palavra[i]) != NULL){
			printf("%c", palavra[i]);
		}
		else{
			printf("_ ");
		}
	}
	printf("\n");
}

/*
Parte do Menu de Jogo(Onde o jogador vai especificar o nome do usuário e os modos de jogo)
*/
/*void Jogo(){
	//Menu Inicial de Jogo
	int p_menu_option;
	int p_switch_1;
	do{
		printf("-----\nBem-vindo ao Jogo da Forca\n-----\n");
		printf("Menu de Jogo\n");
		printf("[ 1 ] Tutorial/Regras\n");
		printf("[ 2 ] Iniciar Jogo\n");
		scanf("%d",&p_menu_option);
		/*-->Switch de Cenários<--
		switch(p_menu_option){
			case 1:
				printf("O Objetivo do jogo:\n- Acertar a palavra de um determinado tema");
				printf("Regras:\n- Cada jogador tem 6 tentativas em caso de falha\n- Os jogadores irão refezar os chutes a cada tentativa\n");
				printf("[1] Voltar \n");
				scanf("%c",&p_switch_1);
				break;
			case 2:
				printf("Certo Iniciando o Jogo...");
				jogos();
				break;
			default:
				break;
		}
		system("cls");
		//<!--Fim do Menu Inicial de Jogo-->
	}while(p_menu_option != 2);
}*/


/*
Toda a lógica de jogo e o jogo em si
*/
//Inicío de Jogo
void Jogo(){
	//Configurações básicas de Jogo:
	char palavras[][TAMANHO_PALAVRA] = {"python", "programacao", "computador", "desenvolvimento", "inteligencia"};
	char palavraSecreta[TAMANHO_PALAVRA];
	char letrasCorretas[TAMANHO_PALAVRA] = "";
	
	/*-->Configurações de tentativas<--*/
	int p_attenpts[] = {MAX_TENTATIVAS,MAX_TENTATIVAS,MAX_TENTATIVAS,MAX_TENTATIVAS};
	int tentativas = MAX_TENTATIVAS;
	/*-->Seletor de palavras<--*/
	srand(time(NULL));
    strcpy(palavraSecreta, palavras[rand() % 5]);
	//<!--Fim das Configurações básicas de Jogo-->
	
	//Configuraçõe de Jogadores
	int Num_players;
	char NomePlayers[3][2];
	printf("Informe o número de jogadores: \n");
    printf("[ 1 ] Solo\n");
    printf("[ 2 ] Dois\n");
    printf("[ 3 ] Três\n");
    printf("[ 4 ] Quatro\n");
    printf("Informe o número de jogadores: ");
    scanf("%d", &Num_players);
    
    /*Informar Nome dos Jogadores*/
    int i,j;
    for(i = 0; i < Num_players; i++){
		printf("Informe o nome[3 Letras]: ");
    	scanf("%s", NomePlayers[i]);
	}
	//<!-- Fim das Configurações de Jogo-->
	
	//Jogo da Forca
	while(tentativas < 0){
		//Exibir os nomes da vez dos jogadores
		for(i = 0; i < Num_players; i++){
			//-->Bloco de Jogo
			printf("Vez do: %s",NomePlayers[i]);
					
			printf("\nPalavra: ");
			mostrarPalavra(palavraSecreta, letrasCorretas);
				
			printf("Tentativas restantes: %d\n", p_attenpts[i]);
        	printf("Digite uma letra: ");
        	
       		char letraUsuario;
			scanf(" %c", &letraUsuario);
        	limparBufferEntrada();
        	letraUsuario = tolower(letraUsuario);
        		
			//-->Condições de Jogo
			if (strchr(letrasCorretas, letraUsuario) != NULL) {
           		printf("Você já escolheu esta letra. Tente novamente.\n");
           		continue;
			}
			
			if (strchr(palavraSecreta, letraUsuario) != NULL) {
            	strncat(letrasCorretas, &letraUsuario, 1);
				printf("Letra correta!\n");
       		} else {
			   tentativas--;
			   p_attenpts[j]--;
			   printf("Letra incorreta.\n");
			}
					
			if (strspn(palavraSecreta, letrasCorretas) == strlen(palavraSecreta)) {
				printf("\nParabéns! Você venceu! A palavra é: %s\n", palavraSecreta);
				break;
			} 
		}
        system("cls");
	}	
	if (tentativas == 0) {
        printf("\nGame over! A palavra correta era: %s\n", palavraSecreta);
    }
	//<!--Fim do Jogo da Forca-->
}
