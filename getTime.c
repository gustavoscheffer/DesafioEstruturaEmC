#include <stdio.h>
#include <time.h>
#include <stdlib.h>


typedef struct {
	
	time_t vencimento;

} ESTOQUE;


/* Prototipo: Pega data de hoje */
void get_data_hoje(time_t *hoje);
void get_vencimento(ESTOQUE *estoque);


/* Main */
int main(void){

	time_t hoje;
	ESTOQUE estoque;

	get_data_hoje(&hoje);
	get_vencimento(&estoque);

	printf("\n HOJE em dias => %d\n", hoje);
	printf("\n VENCIMENTO em dias => %d\n", estoque.vencimento);

return 0;
}

void get_data_hoje(time_t *hoje){

	/* Variaveis e objetos */

	struct tm data_hoje; // -> estrutura de calendário (dia,mes,ano,hora,minutos,segundos...).
	time_t now; 		 // -> variavel que recebe a data em segundos.

	now = time(NULL); //-> variavel recebeu a data completa do sistema

	// -> usando a estrutura, alterei os campos h:m:s para 0:0:0 (gmtime_s no windows)
	data_hoje.tm_hour = 0;
	data_hoje.tm_min = 0;
	data_hoje.tm_sec = 0;
	data_hoje.tm_mday= localtime(&now)->tm_mday;
	data_hoje.tm_mon = localtime(&now)->tm_mon;
	data_hoje.tm_year= localtime(&now)->tm_year;
	
	*hoje = mktime(&data_hoje)/86400; //-> retorna a hora em dias.

}

void get_vencimento(ESTOQUE *estoque){

	/* Variaveis e objetos */

	struct tm vencimento; // -> estrutura de calendário (dia,mes,ano,hora,minutos,segundos...).

	// -> usando a estrutura, alterei os campos h:m:s para 0:0:0 (gmtime_s no windows).
	vencimento.tm_hour = 0;
	vencimento.tm_min = 0;
	vencimento.tm_sec = 0;

	printf("\nDigite o dia: ");
	scanf("%d",&vencimento.tm_mday);
	
	printf("\nDigite o mes: ");
	scanf("%d",&vencimento.tm_mon);
	
	printf("\nDigite o ano: ");
	scanf("%d",&vencimento.tm_year);
	
	estoque->vencimento = mktime(&vencimento)/86400; //-> retorna a hora em dias.

}