#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	char Nomes[3][10];
	printf("String array Elements are:\n");
	int i,j;
	for(i = 0; i < 3; i++){
		printf("Informe o nome:");
		scanf("%s\n", Nomes[i]);
	}
	
	for(j = 0; j < 3; j++){
		printf("%s\n", Nomes[j]);
	}
	return 0;
}
