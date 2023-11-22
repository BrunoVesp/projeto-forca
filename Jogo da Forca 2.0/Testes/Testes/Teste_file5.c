#include <stdio.h>
#include <stdlib.h>

int main(void){
	void copiarConteudo(FILE *file1, FILE *file2);
	
	FILE *file1 = fopen("Arquivo1.txt","r");
	if(file1 == NULL){
		printf("Não foi possível abrir o arquivo\n");
		system("pause");
		return 1;
	}
	
	FILE *file2 = fopen("Arquivo2.txt","w");
	
	copiarConteudo(file1,file2);
	
	fclose(file1);
	fclose(file2);
	return 0;
}

void copiarConteudo(FILE *file1, FILE *file2){
	char leitor[10000];
	
	while(fgets(leitor,10000,file1)){
		fputs(leitor,file2);
	}
}
