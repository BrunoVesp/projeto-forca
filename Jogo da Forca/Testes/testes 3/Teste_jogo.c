#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TENTATIVAS 6
#define TAMANHO_PALAVRA 20

#define NUMBER_OF_STRINGS 3
#define STRING_LENGTH 2

void limparBufferEntrada() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void mostrarPalavra(char palavra[], char letrasCorretas[]) {
    for (int i = 0; i < strlen(palavra); i++) {
        if (strchr(letrasCorretas, palavra[i]) != NULL) {
            printf("%c ", palavra[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main(){
	//Configurações de jogo
    char palavras[][TAMANHO_PALAVRA] = {"python", "programacao", "computador", "desenvolvimento", "inteligencia"};
    char palavraSecreta[TAMANHO_PALAVRA];
    char letrasCorretas[TAMANHO_PALAVRA] = "";
    int tentativas = MAX_TENTATIVAS;
    
    //Variáveis de cadastro
    int i,j;
    char nameUser[NUMBER_OF_STRINGS][STRING_LENGTH + 1];
    strcpy(nameUser[0], "");
    strcpy(nameUser[0], "");

	//srand(time(NULL));
    strcpy(palavraSecreta, palavras[rand() % 5]);
    
    //Número de Jogadores
    int playerN;
    printf("-----\nBem-vindo ao Jogo da Forca\n-----\n");
    while(1){
    	printf("Forma de Jogo \n");
    	printf("[ 1 ] Solo\n");
    	printf("[ 2 ] Dois\n");
    	printf("[ 3 ] Três\n");
    	printf("[ 4 ] Quatro\n");
    	printf("Informe o número de jogadores: ");
    	scanf("%d", &playerN);
    	system("cls");
    	if(playerN == 1 || playerN == 2 || playerN == 3 || playerN == 4){
    		//Nome dos Players
    		for(i = 0; i < playerN ; i++){
    			for(j = 0; j < playerN; j++){
    				printf("Nome do %d ° Usuário[Apenas 3 letras]: ",j++);
    				scanf("%s", &nameUser[i][j]);
				}
			}
    		printf("Certo,o jogo já vai começar...\n");
    		break;
		}
		system("cls");
	}
    //Condição de vitória
    bool gameWin;
    bool gameEnd;
    int f,b,a,r;
    while (gameWin != true || gameEnd != true) {
    	for(b = 0; b < playerN; b++){
    		for(f = 0; f < playerN; f++){
    			char letraUsuario;
    			printf("Vez do %s\n", nameUser[b][f]);
				printf("\nPalavra: ");
        			mostrarPalavra(palavraSecreta, letrasCorretas);
        	
			      	
        		printf("Tentativas restantes: %d\n", tentativas);
				printf("Digite uma letra: ");

        		scanf(" %c", &letraUsuario);
        		limparBufferEntrada();
        		letraUsuario = tolower(letraUsuario);
        	
        		if (strchr(letrasCorretas, letraUsuario) != NULL) {
            		printf("Você já escolheu esta letra. Tente novamente.\n");
            		continue;
				}

        		if (strchr(palavraSecreta, letraUsuario) != NULL) {
            		strncat(letrasCorretas, &letraUsuario, 1);
            		printf("Letra correta!\n");
        		} else {
            		tentativas--;
            		printf("Letra incorreta.\n");
        		}

        		if (strspn(palavraSecreta, letrasCorretas) == strlen(palavraSecreta)) {
            		printf("\nParabéns! Você venceu! A palavra é: %s\n", palavraSecreta);
            		gameWin = true;
            		break;
        		}
        	
        		if (tentativas == 0) {
        		printf("\nGame over! A palavra correta era: %s\n", palavraSecreta);
        		gameEnd = true;
    			}
    		} 
		}	
	}
        /*printf("\nPalavra: ");
        mostrarPalavra(palavraSecreta, letrasCorretas);

        printf("Tentativas restantes: %d\n", tentativas);
        printf("Digite uma letra: ");

        char letraUsuario;
        scanf(" %c", &letraUsuario);
        limparBufferEntrada();
        letraUsuario = tolower(letraUsuario);*/

        /*if (strchr(letrasCorretas, letraUsuario) != NULL) {
            printf("Você já escolheu esta letra. Tente novamente.\n");
            continue;
        }

        if (strchr(palavraSecreta, letraUsuario) != NULL) {
            strncat(letrasCorretas, &letraUsuario, 1);
            printf("Letra correta!\n");
        } else {
            tentativas--;
            printf("Letra incorreta.\n");
        }

        if (strspn(palavraSecreta, letrasCorretas) == strlen(palavraSecreta)) {
            printf("\nParabéns! Você venceu! A palavra é: %s\n", palavraSecreta);
            break;
        }
    }

    if (tentativas == 0) {
        printf("\nGame over! A palavra correta era: %s\n", palavraSecreta);
    }
    */
    
}
