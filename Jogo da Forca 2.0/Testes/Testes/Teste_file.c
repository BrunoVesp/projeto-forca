#include <stdio.h>

int main(void){
	FILE *file;
	file = fopen("ranking.txt","a");
	/*
	Os tipos de letrar no sistema de escrita e leitura
	r = Read(ler)
	w = write(Escreva)
	a = append(Altere)
	*/
	
	//fprintf() - File printf()
	//exemplo: fprintf(file{variavel de ponteiro do arquivo},"{texto a ser escrito no arquivo}")
	fprintf(file,"\n \n \n Max Payne");
	
	//fclose(); - File close()
	//Exemplo: fclose(file{nome do arquivo a ser fechado})
	fclose(file);
	
	return 0;
}
