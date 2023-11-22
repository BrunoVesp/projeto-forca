/*
Jogo Da Forca
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TENTATIVAS 6
#define TAMANHO_PALAVRA 20

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

void Jogo() {
    char palavras[][TAMANHO_PALAVRA] = {"python", "programacao", "computador", "desenvolvimento", "inteligencia"};
    char palavraSecreta[TAMANHO_PALAVRA];
    char letrasCorretas[TAMANHO_PALAVRA] = "";
    int tentativas = MAX_TENTATIVAS;

	srand(time(NULL));
    strcpy(palavraSecreta, palavras[rand() % 5]);

    printf("Bem-vindo ao Jogo da Forca!\n");

    while (tentativas > 0) {
        printf("\nPalavra: ");
        mostrarPalavra(palavraSecreta, letrasCorretas);

        printf("Tentativas restantes: %d\n", tentativas);
        printf("Digite uma letra: ");

        char letraUsuario;
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
            break;
        }
    }

    if (tentativas == 0) {
        printf("\nGame over! A palavra correta era: %s\n", palavraSecreta);
    }
}
