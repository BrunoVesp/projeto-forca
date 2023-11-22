#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *file;
	file = fopen("teste_file.txt","r");
	/*
	OBS 1:
	fscanf() - Usado para puxar as informações de um arquivo;
	exemplo:
	fScanf(file,"%d %d %d", &x ,&y ,&z);
	*/
	
	/*
	OBS 2:
	Se o arquivo não existir,utilizar o seguinte mecanismo
	if( file ==NULL){
	printf("Arquivo não encontrado\n");
	system("pause");
	return 0;
	}
	*/
	
	if(file == NULL){
		printf("Arquivo Não encontrado\n");
		system("pause");
		return 0;
	}
	
	int x,y,z;
	fscanf(file,"%d %d %d", &x ,&y ,&z);
	
	printf("%i %i %i\n", x ,y ,z);
	
	fclose(file);
	
	system("pause");
	return 0;
}
