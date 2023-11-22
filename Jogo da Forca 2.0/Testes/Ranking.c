#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TENTATIVAS 6
#define TAMANHO_PALAVRA 20
#define MAX_JOGADORES 10

typedef struct {
    char nome[50];
    int pontuacao;
} Jogador;

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

void exibirRanking(Jogador ranking[], int numJogadores) {
    printf("\n--- RANKING ---\n");
    for (int i = 0; i < numJogadores; i++) {
        printf("%d. %s - Pontuação: %d\n", i + 1, ranking[i].nome, ranking[i].pontuacao);
    }
}

void salvarRanking(Jogador ranking[], int numJogadores) {
    FILE *arquivo = fopen("ranking.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de ranking.\n");
        return;
    }

    for (int i = 0; i < numJogadores; i++) {
        fprintf(arquivo, "%s %d\n", ranking[i].nome, ranking[i].pontuacao);
    }

    fclose(arquivo);
}

void carregarRanking(Jogador ranking[], int *numJogadores) {
    FILE *arquivo = fopen("ranking.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo de ranking não encontrado. Criando um novo.\n");
        return;
    }

    *numJogadores = 0;

    while (*numJogadores < MAX_JOGADORES && fscanf(arquivo, "%s %d", ranking[*numJogadores].nome, &ranking[*numJogadores].pontuacao) == 2) {
        (*numJogadores)++;
    }

    fclose(arquivo);
}

void adicionarJogadorRanking(Jogador ranking[], int *numJogadores, char nomeJogador[], int pontuacao) {
    if (*numJogadores < MAX_JOGADORES) {
        strcpy(ranking[*numJogadores].nome, nomeJogador);
        ranking[*numJogadores].pontuacao = pontuacao;
        (*numJogadores)++;
    } else {
        printf("O ranking está cheio. Não é possível adicionar mais jogadores.\n");
    }
}

int main() {
    char palavras[][TAMANHO_PALAVRA] = {"python", "programacao", "computador", "desenvolvimento", "inteligencia"};
    char palavraSecreta[TAMANHO_PALAVRA];
    char letrasCorretas[TAMANHO_PALAVRA] = "";
    int tentativas = MAX_TENTATIVAS;

    Jogador ranking[MAX_JOGADORES];
    int numJogadores = 0;

    carregarRanking(ranking, &numJogadores);

    srand(time(NULL));
    strcpy(palavraSecreta, palavras[rand() % 5]);

    printf("Bem-vindo ao Jogo da Forca!\n");

    char nomeJogador[50];
    printf("Digite seu nome: ");
    scanf("%s", nomeJogador);

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

        if (strspn(letrasCorretas, palavraSecreta) == strlen(palavraSecreta)) {
            printf("\nParabéns! Você venceu! A palavra é: %s\n", palavraSecreta);

            // Adiciona jogador ao ranking
            adicionarJogadorRanking(ranking, &numJogadores, nomeJogador, tentativas);
            // Exibe e salva o ranking
            exibirRanking(ranking, numJogadores);
            salvarRanking(ranking, numJogadores);

            break;
        }
    }

    if (tentativas == 0) {
        printf("\nGame over! A palavra correta era: %s\n", palavraSecreta);
    }

    return 0;
}

