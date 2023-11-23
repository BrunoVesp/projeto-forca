//
// Banco de Palavras - Jogo da Forca
//
//Bibliotecas Externas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void copiarConteudo(FILE *file1, FILE *file2) {
    char bancoPalavra[50];

    while (fgets(bancoPalavra, 50, file2)) {
        fprintf(file1, "%s", bancoPalavra);
    }
}

void alocarPalavra(FILE *file2) {
	setlocale(0, "portuguese");
	
    if (file2 == NULL) {
        printf("Arquivo não encontrado.\n");
        system("pause");
        exit(1);
    }

    char palavraNova[50];
    printf("\n--- Alocador de Palavras \n---\n");
    printf("\nInforme a palavra: ");
    scanf("%s", palavraNova);
    fprintf(file2,"\n");
    fputs(palavraNova, file2);
}

void lerBancoPalavra(FILE *file1) {
	setlocale(0, "portuguese");
	
    char lerPalavras[100];

    if (file1 == NULL) {
        printf("Arquivo não encontrado.\n");
        system("pause");
        exit(1);
    }

    printf("\n--- Exibir Banco de Palavras \n---\n");
    
    while(fgets(lerPalavras, 100, file1) != NULL) {
        printf("%s", lerPalavras);
    }
    printf("\n");
    system("pause");
}

int Banco(void) {
	setlocale(0, "portuguese");
	
    FILE *file1 = fopen("bancoPalavras1.txt", "r");
    if (file1 == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        system("pause");
        exit(1);
    }

    FILE *file2 = fopen("BancoPalavras2.txt", "a");
    if (file2 == NULL) {
        printf("Não foi possível criar o arquivo.\n");
        fclose(file1);
        system("pause");
        exit(1);
    }
    //copiarConteudo(file1, file2);
    
    int gameOp4;
	printf("---\n Banco de Palavras \n---\n");
	printf("[ 1 ] Cadastrar Palavras\n");
	printf("[ 2 ] Mostrar Palavras Cadastradas\n");
	printf("[ 3 ] Menu Principal\n");
	scanf("%d", &gameOp4);
	
	copiarConteudo(file1,file2);

	switch(gameOp4){
		case 1:
			alocarPalavra(file2);
			copiarConteudo(file1,file2);
			system("pause");
			break;
		case 2:
			copiarConteudo(file1,file2);
			lerBancoPalavra(file1);
			break;
		case 3:
			//main();
			system("pause");
			break;
		default:
			break;
	}
	
    fclose(file1);
    fclose(file2);

    return 0;
}
