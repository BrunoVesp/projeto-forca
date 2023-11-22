#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *file;
	file = fopen("ranking.txt","r");
	
	if(file == NULL){
		printf("Arquivo não encontrado");
		system("pause");
		return 0;
	}
	
	char nomes[100];
	
	/*
	fgets() - Vai pegar as strings presentes em um arquivo e aramazenar em uma variável
	(nome da variavel,tamanho/número  de caracteres, arquivo de ponteiro)
	*/
	while(fgets(nomes,100,file) != NULL){
		printf("%s", nomes);
	}
	
	printf("\n");
	system("pause");
	return 0;
}
