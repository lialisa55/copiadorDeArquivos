#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){
	FILE *fp;
	char *arquivo, *conteudo;
	int tamanho;

	arquivo = (char*)malloc(15*sizeof(char));
	fgets(arquivo, 15, stdin);
	if(arquivo[strlen(arquivo) - 1] == '\n'){
		arquivo [strlen(arquivo) -1] = '\0';
	}

	arquivo = realloc(arquivo, (strlen(arquivo)+1) * sizeof(char));

	fp = fopen(arquivo, "r");
	free(arquivo);

	fseek(fp, 0, SEEK_END);
	tamanho = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	conteudo = (char*)malloc((tamanho+1)*sizeof(char));
	fread(conteudo, sizeof(char), tamanho, fp);
	conteudo[tamanho] = '\0';

	fclose(fp);

	printf("%s\n", conteudo);

	free(conteudo);
	return 0;
}
