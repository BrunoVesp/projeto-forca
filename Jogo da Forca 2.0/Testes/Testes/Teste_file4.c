#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *file;
	file = fopen("ranking.txt","a");
	
	if(file == NULL){
		printf("Arquivo não encontrado\n");
		system("pause");
		return 0;
	}
	
	/*
	fputs() - Adicionar uma string
	(variaveal que adiciona, arquivo criado)
	*/
	char nome[] = "Chris Mannix\n";
	fputs(nome, file);
	
	char letra = '3';
	fputc(letra, file);
	
	fclose(file);
	printf("\n");
	system("pause");
	return 0;
}
