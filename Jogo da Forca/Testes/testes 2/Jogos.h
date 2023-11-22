/*
Jogo da Forca
*/

//Bibliotecas Externas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//Bibliotecas Internas
#include "Banco.h"
#include "Rank.h"

//Defini��esd e Suporte
#define MAX_TENTATIVAS 6
#define MAX_PALAVRA 50
#define tamanho_palavra 50 // Tamanho m�ximo para cada palavra.
#define tamanho_vetor 20 // Vetor para quantidade de palavras.
#define MAX_TAMANHO_PALAVRA 50
#define MAX_PALAVRAS 100

// Fun��o para escolher uma palavra aleat�ria do arquivo
char *escolherPalavraAleatoria(const char *nomeArquivo) {
    FILE *arquivo = fopen("BancoPalavras2.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char palavras[MAX_PALAVRAS][MAX_TAMANHO_PALAVRA];
    int numPalavras = 0;

    // L� as palavras do arquivo
    while (fscanf(arquivo, "%s", palavras[numPalavras]) == 1 && numPalavras < MAX_PALAVRAS) {
        numPalavras++;
    }

    if (numPalavras == 0) {
        printf("Arquivo vazio. Saindo...\n");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }

    // Escolhe uma palavra aleat�ria
    int indice = rand() % numPalavras;

    fclose(arquivo);

    // Alocar uma nova string e copiar a palavra escolhida para ela
    char *palavraEscolhida = strdup(palavras[indice]);
    if (palavraEscolhida == NULL) {
        perror("Erro ao alocar mem�ria");
        exit(EXIT_FAILURE);
    }

    return palavraEscolhida;
}

void mostrarRanking(FILE *filer,char NomeWin[5]){
	filer = fopen("ranking.txt","a");
	
	fprintf(filer,"- %s : \n", NomeWin);
}

// Fun��o para inicializar a palavra oculta
void inicializarPalavraOculta(char *palavraEscolhida, char *palavraOculta) {
    int comprimento = strlen(palavraEscolhida);

    for (int i = 0; i < comprimento; i++) {
        if (isalpha(palavraEscolhida[i])) {
            palavraOculta[i] = '_';
        } else {
            palavraOculta[i] = palavraEscolhida[i];
        }
    }

    palavraOculta[comprimento] = '\0';
}

// Fun��o para exibir a palavra oculta
void exibirPalavraOculta(char *palavraOculta) {
    printf("Palavra: %s\n", palavraOculta);
}

// Fun��o para verificar se a letra est� na palavra
int verificarLetra(char *palavraEscolhida, char *palavraOculta, char letra) {
    int encontrou = 0;
    int comprimento = strlen(palavraEscolhida);

    for (int i = 0; i < comprimento; i++) {
        if (palavraEscolhida[i] == letra) {
            palavraOculta[i] = letra;
            encontrou = 1;
        }
    }

    return encontrou;
}

// Fun��o para verificar se a palavra completa foi adivinhada
int verificarPalavraCompleta(char *palavraEscolhida, char *tentativa) {
    return strcmp(palavraEscolhida, tentativa) == 0;
}

int Jogo() {
    srand(time(NULL));
    char NomeWin[5];
    FILE *filer;
    filer = fopen("Ranking.txt","a");

    int numJogadores;

    // Solicitar ao usu�rio o n�mero de jogadores
    printf("Capacidade de Jogadores: \n");
    printf("[ 1 ] Solo\n");
    printf("[ 2 ] Dois\n");
    printf("[ 3 ] Tr�s\n");
    printf("[ 4 ] Quatro\n");
    printf("[ 5++ ] 5 ou mais\n");
    printf("Digite o numero de jogadores: ");
    scanf("%d", &numJogadores);

    if (numJogadores <= 0) {
        printf("Numero de jogadores invalido. Saindo...\n");
        return 1;
    }

    char *palavra = escolherPalavraAleatoria("Bancopalavras2.txt");
    char palavraOculta[MAX_PALAVRA];
    int tentativas = 0;
    int jogadorAtual = 0;

    if (palavra == NULL) {
        printf("Erro ao escolher a palavra. Saindo...\n");
        return 1;
    }
    
    inicializarPalavraOculta(palavra, palavraOculta);

    while (tentativas < MAX_TENTATIVAS) {
        printf("Jogador %d\n", jogadorAtual + 1);
        exibirPalavraOculta(palavraOculta);

        char tentativa[MAX_PALAVRA];
        printf("Digite uma letra ou tente a palavra completa: ");
        scanf("%s", tentativa);

        if (strlen(tentativa) == 1) {
            // Verificar uma letra
            char letra = tentativa[0];
            if (!verificarLetra(palavra, palavraOculta, letra)) {
                tentativas++;
                printf("Letra incorreta! Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
            } else {
                printf("Letra correta!\n");
            }
        } else {
            // Tentativa da palavra completa
            if (verificarPalavraCompleta(palavra, tentativa)) {
                printf("Parab�ns! Jogador %d acertou a palavra: %s\n", jogadorAtual + 1, palavra);
                printf("Informe seu nome para o Ranking: ");
                scanf("%s",&NomeWin);
                mostrarRanking(filer,NomeWin);
                return 0;  // Encerra o programa
            } else {
                printf("Tentativa da palavra completa incorreta! Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
                tentativas++;
            }
        }

        if (strcmp(palavra, palavraOculta) == 0) {
            printf("Parab�ns! Jogador %d acertou a palavra: %s\n", jogadorAtual + 1, palavra);
            printf("Informe seu nome para o Ranking: ");
                scanf("%s",&NomeWin);
                mostrarRanking(filer,NomeWin);
            return 0;  // Encerra o programa
        }

        jogadorAtual = (jogadorAtual + 1) % numJogadores; // Avan�a para o pr�ximo jogador
    }

    if (tentativas == MAX_TENTATIVAS) {
        printf("Nenhum jogador acertou. A palavra correta era: %s\n", palavra);
    }

    return 0;
}
