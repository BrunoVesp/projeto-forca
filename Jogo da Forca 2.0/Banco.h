/* 
Banco de Palavras - Jogo da Forca
*/
//Bibliotecas Externas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void copiarConteudo(FILE *file1, FILE *file2) {
    char bancoPalavra[50];

    while (fgets(bancoPalavra, 50, file1)) {
        fprintf(file2, "%s", bancoPalavra);
    }
}

void alocarPalavra(FILE *file2) {
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

void lerBancoPalavra(FILE *file2) {
    char lerPalavras[100];

    if (file2 == NULL) {
        printf("Arquivo não encontrado.\n");
        system("pause");
        exit(1);
    }

    printf("\n--- Exibir Bando de Palavras \n---\n");
    
    while (fgets(lerPalavras, 100, file2) != NULL) {
        printf("%s", lerPalavras);
    }
}

int Banco(void) {
    FILE *file1 = fopen("bancoPalavras1.txt", "r");
    if (file1 == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        system("pause");
        exit(1);
    }

    FILE *file2 = fopen("BancoPalavras2.txt", "w");
    if (file2 == NULL) {
        printf("Não foi possível criar o arquivo.\n");
        fclose(file1);
        system("pause");
        exit(1);
    }
    copiarConteudo(file1, file2);
    
    int gameOp4;
	printf("---\n Banco de Palavras \n---\n");
	printf("[ 1 ] Cadastrar Palavras\n");
	printf("[ 2 ] Mostrar Palavras Cadastradas\n");
	printf("[ 3 ] Menu Principal\n");
	scanf("%d", &gameOp4);

	switch(gameOp4){
		case 1:
			alocarPalavra(file2);
			system("pause");
			break;
		case 2:
			lerBancoPalavra(file2);
			system("pause");
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
