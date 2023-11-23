//
// Jogo da Forca
//
//
//Bibliotecas Externas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

//Bibliotecas Internas

//Definiçõesd e Suporte
#define MAX_TENTATIVAS 8
#define MAX_PALAVRA 50
#define tamanho_palavra 50 // Tamanho máximo para cada palavra.
#define tamanho_vetor 20 // Vetor para quantidade de palavras.
#define MAX_TAMANHO_PALAVRA 50
#define MAX_PALAVRAS 100

// Função para escolher uma palavra aleatória do arquivo
char *escolherPalavraAleatoria(const char *nomeArquivo) {
	setlocale(0, "portuguese");
	
    FILE *arquivo = fopen("BancoPalavras2.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char palavras[MAX_PALAVRAS][MAX_TAMANHO_PALAVRA];
    int numPalavras = 0;

    // Lê as palavras do arquivo
    while (fscanf(arquivo, "%s", palavras[numPalavras]) == 1 && numPalavras < MAX_PALAVRAS) {
        numPalavras++;
    }

    if (numPalavras == 0) {
        printf("Arquivo vazio. Saindo...\n");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }

    // Escolhe uma palavra aleatória
    int indice = rand() % numPalavras;

    fclose(arquivo);

    // Alocar uma nova string e copiar a palavra escolhida para ela
    char *palavraEscolhida = strdup(palavras[indice]);
    if (palavraEscolhida == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    return palavraEscolhida;
}

void armazenarRank(FILE *filer){
	setlocale(0, "portuguese");
	
	if (filer == NULL) {
        printf("Arquivo não encontrado.\n");
        system("pause");
        exit(1);
    }
	
	char nomeWin[50];
	printf("\nInforme seu nome para o Ranking: ");
	scanf("%s", nomeWin);
	fprintf(filer,"\n");
    fputs(nomeWin, filer);
}

// Função para inicializar a palavra oculta
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

// Função para exibir a palavra oculta
void exibirPalavraOculta(char *palavraOculta) {
	setlocale(0, "portuguese");
	
    printf("Palavra: %s\n", palavraOculta);
}

// Função para verificar se a letra está na palavra
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

// Função para verificar se a palavra completa foi adivinhada
int verificarPalavraCompleta(char *palavraEscolhida, char *tentativa) {
    return strcmp(palavraEscolhida, tentativa) == 0;
}

int Jogo(void) {
	setlocale(0, "portuguese");
	
    srand(time(NULL));
    char NomeWin[5];
    FILE *filer;
    filer = fopen("LeRanking.txt","a");
	
    int numJogadores;

    // Solicitar ao usuário o número de jogadores
    printf("Capacidade de Jogadores: \n");
    printf("[ 1 ] Solo\n");
    printf("[ 2 ] Dois\n");
    printf("[ 3 ] Três\n");
    printf("[ 4 ] Quatro\n");
    printf("[ 5++ ] 5 ou mais\n");
    printf("Digite o número de jogadores: ");
    scanf("%d", &numJogadores);

    if (numJogadores <= 0) {
        printf("Número de jogadores inválido. Saindo...\n");
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
    
    system("pause");
    system("cls");

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
                system("pause");
                system("cls");
            } else {
                printf("Letra correta!\n");
                system("pause");
                system("cls");
            }
        } else {
            // Tentativa da palavra completa
            if (verificarPalavraCompleta(palavra, tentativa)) {
                printf("Parabéns! Jogador %d acertou a palavra: %s\n", jogadorAtual + 1, palavra);
                armazenarRank(filer);
            	system("pause");
    			system("cls");
                return 0;  // Encerra o programa
            } else {
                printf("Tentativa da palavra completa incorreta! Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
                tentativas++;
            }
        }

        if (strcmp(palavra, palavraOculta) == 0) {
            printf("Parabéns! Jogador %d acertou a palavra: %s\n", jogadorAtual + 1, palavra);
            armazenarRank(filer);
            system("pause");
    		system("cls");
            return 0;  // Encerra o programa
        }

        jogadorAtual = (jogadorAtual + 1) % numJogadores; // Avança para o próximo jogador
    }

    if (tentativas == MAX_TENTATIVAS) {
        printf("Nenhum jogador acertou. A palavra correta era: %s\n", palavra);
        system("pause");
    	system("cls");
    }
    
    return 0;
}
