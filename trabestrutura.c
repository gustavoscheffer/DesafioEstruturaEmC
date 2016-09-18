/***********************************************/
/* Desafio de Programa��o Listas               */
/* Listas Sequenciais                          */
/* Nomes: Gustavo Bittencourt                  */
/*        Gustavo Scheffer                     */
/*        Maicon Magano                        */
/*        Victor Santos                        */
/***********************************************/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#define TAM 500  //TAMANHO DO VETOR

/***********************************************/
/* Defini��o dos Registros                     */
/***********************************************/

typedef struct{
	char nome[100];
	int validade;
	int codigo;
	int quantidade;
	float valorUnitario;
}PRODUTOS;

typedef struct{
	int contador;
	int contadorCodigo;
	int somaValidade;
	PRODUTOS produtos[TAM];
}ESTOQUE;

/***********************************************/
/* Defini��o das Fun��es                       */
/***********************************************/

int getData();
void novoCadastro(ESTOQUE *estoque);
void relatorio(ESTOQUE *estoque);
void ordenaValidade(ESTOQUE *estoque);
void ordenaCodigo(ESTOQUE *estoque);
void excluirCodigo(ESTOQUE *estoque);
void excluirVencidos( ESTOQUE *estoque);
void excluirVencidoPos(ESTOQUE *estoque, int);

/***********************************************/
/* Programa Principal                          */
/***********************************************/

int main(void){

    char op;
    int escolha;
    setlocale(LC_ALL, "Portuguese");
    ESTOQUE estoque;

    printf("Digite a data de hoje.");
	estoque.somaValidade = getData();
	printf("\n");

    while(1){
        escolha = 1;
        system("cls");
        printf (" ----------------Loja--------------- ");
		printf ("\n| [1] - Venda                       |");
		printf ("\n| [2] - Caixa                       |");
		printf ("\n --------------Estoque--------------");
		printf ("\n| [3] - Cadastrar Produto 	    |");
		printf ("\n| [4] - Exibir Produtos             |");
		printf ("\n| [5] - Ordenar                     |");
		printf ("\n| [6] - Excluir                     |");
		printf ("\n| [s] - Sair                        |");
		printf ("\n -----------------------------------");
		printf ("\n\nDigite a sua escolha agora: ");
        fflush(stdin);
        op = toupper(getche());

        switch(op) {

            case '1':
                //venda
                break;
            case '2':
                //caixa
                break;
            case '3':
                novoCadastro(&estoque);
                break;
            case '4':
                relatorio(&estoque);
                break;
            case '5':
                while(escolha == 1){
                    system("cls");
                    printf (" --------------Estoque--------------");
                    printf ("\n| [1] - Ordenar por Validade        |");
                    printf ("\n| [2] - Ordenar por C�digo          |");
                    printf ("\n| [3] - Voltar                      |");
                    printf ("\n -----------------------------------");
                    printf ("\n\nDigite a sua escolha agora: ");
                    fflush(stdin);
                    op = toupper(getche());

                    switch(op) {
                        case '1':
                            ordenaValidade(&estoque);
                            break;
                        case '2':
                            ordenaCodigo(&estoque);
                            break;
                        case '3':
                            escolha = 0;
                            break;
                        default:
                            printf( "\n Op��o inv�lida, digite novamente." );
                            break;
                    }
                }
                break;
            case '6':
                while(escolha == 1){
                    system("cls");
                    printf (" --------------Estoque--------------");
                    printf ("\n| [1] - Excluir por Validade        |");
                    printf ("\n| [2] - Excluir por C�digo          |");
                    printf ("\n| [3] - Voltar                      |");
                    printf ("\n -----------------------------------");
                    printf ("\n\nDigite a sua escolha agora: ");
                    fflush(stdin);
                    op = toupper(getche());

                    switch(op) {
                        case '1':
                            excluirCodigo(&estoque);
                            break;
                        case '2':
                            excluirVencidos(&estoque);
                            break;
                        case '3':
                            escolha = 0;
                            break;
                        default:
                            printf( "\n Op��o inv�lida, digite novamente." );
                            break;
                    }
                }
                break;
            case 'S':
                exit(1);
                break;
            default :
                printf( "\n Op��o inv�lida, digite novamente." );
                break;
        }
        printf( "\n" );
     }

 return 0;
}


/***********************************************/
/* Fun��es                                     */
/***********************************************/

/***********************************************/
/* Nome: getData                               */
/* Fun��o: retorna a soma de dias da data      */
/* inserida para utilizar como compara��o na   */
/* hora de ordenar e excluir                   */
/* Retorno: soma do resultado do c�lculo       */
/***********************************************/
int getData(){
    int diaAtual, mesAtual, anoAtual, somaDia;
	fflush(stdin);
	printf("\nDia: ");
	scanf("%d",&diaAtual);
	printf("M�s: ");
	scanf("%d",&mesAtual);
	printf("Ano: ");
	scanf("%d",&anoAtual);

	somaDia = diaAtual + mesAtual*30 + ((anoAtual-1970)*365);
	return somaDia;
}

/***********************************************/
/* Nome: novoCadastro                          */
/* Fun��o: insere um novo produto na estrutura */
/* produtos dentro do vetor de estruturas do   */
/* estoque.                                    */
/* Retorno: cadastra um novo produto na �ltima */
/* posi��o.                                    */
/***********************************************/
void novoCadastro(ESTOQUE *estoque){
    system("cls");
	int dia, mes, ano, somaValidade;

    if( estoque->contador < TAM ){

        estoque->produtos[estoque->contador].codigo = estoque->contadorCodigo+1001; //atribui o codigo

        printf("Digite o nome: ");
        fflush(stdin);
        gets(estoque->produtos[estoque->contador].nome); //atribui nome

        printf ("\nDigite a data de vencimento.");

        estoque->produtos[estoque->contador].validade = getData(); //atribui a soma da data em dias pela funcao getData

        printf("\nDigite a quantidade: ");
        fflush(stdin);
        scanf( "%d", &estoque->produtos[estoque->contador].quantidade);

        printf("\nDigite o valor unit�rio: ");
        fflush(stdin);
        scanf("%f", &estoque->produtos[estoque->contador].valorUnitario);
        estoque->contadorCodigo++; //incrementa codigo e contador para insercoes futuras
        estoque->contador++;
        printf("\n\nRegistro incluido com sucesso!");

    }
	else{
        printf("\nLista cheia!");
	}
	printf("\n");
	system("pause");
}

/**************************************************/
/* Nome: relatorio                                */
/* Fun��o: listar todos produtos cadastrados nas  */
/* posi��es atuais do vetor, suas ordena��es v�o  */
/* depender da �ltima fun��o de ordenar utilizada */
/* Retorno: todos produtos cadastrados presentes  */
/**************************************************/
void relatorio(ESTOQUE *estoque){
	system("cls");
	int i, resultado;

	if( estoque->contador == 0 ){ // verifica se lista esta vazia
	    printf("\nLista vazia!");
	}
	else {

		for( i = 0; i < estoque->contador; i++ ){ // percorre a lista

			 printf("Produto: %s", estoque->produtos[i].nome);
			 printf("\nC�digo: %d", estoque->produtos[i].codigo);
			 resultado = estoque->produtos[i].validade - estoque->somaValidade; //calculo para verificar quantos dias o produto falta pra vencer ou ja esta vencido

			 if (resultado > 0){ //produto esta dentro do prazo
                printf("\nValidade: %d dias at� o vencimento.", resultado);
			 }
			 else if(resultado < 0){ //produto esta vencido
                resultado = resultado * -1; // converte para valor positivo para ser exibido
                printf ("\nValidade: Est� vencido a %d dias.", resultado);
			 }
			 else{ //produto esta no dia do vencimento
                printf ("\nValidade: Vence hoje!");
			 }

			 printf("\nQuantidade: %i",estoque->produtos[i].quantidade);
			 printf("\nValor Unit�rio: R$ %.2f",estoque->produtos[i].valorUnitario);
			 printf("\nValor Total do produto: R$ %.2f\n",estoque->produtos[i].valorUnitario*estoque->produtos[i].quantidade);

			 if (estoque->produtos[i].validade < estoque->somaValidade){
                printf("\nProduto est� vencido!");
			 }
			 else{
                printf("\nProduto est� no prazo!");
			 }
		}
	}
	printf("\n\n\nFim da lista!\n");
	system("pause");
}
/*****************************************************/
/* Nome: ordenaValidade                              */
/* Fun��o: Remaneja a estrutura mantendo os produtos */
/* que est�o mais vencidos primeiro e o com maior    */
/* validade por �ltimo.                              */
/* Retorno: lista sem produtos vencidos              */
/*****************************************************/
void ordenaValidade(ESTOQUE *estoque) {
  int i, j;
  PRODUTOS aux;

//utiliza o metodo bubble sort, pega o menor e passa pra esquerda, faz isso percorrendo o vetor inteiro
//utiliza como valor de referencia a comparacao do valor da data do dia de hoje com a data de cada produto
for(j=0;j<estoque->contador;j++){
        for(i=j+1;i<estoque->contador;i++){
            if(estoque->produtos[j].validade>estoque->produtos[i].validade){
                aux=estoque->produtos[j];
                estoque->produtos[j]=estoque->produtos[i];
                estoque->produtos[i]=aux;
            }
        }
    }
    printf("\n\nProdutos ordenado por ordem de validade!\n");
    system("pause");
}
/********************************************************/
/* Nome: ordenaValidade                                 */
/* Fun��o: Remaneja a estrutura mantendo os produtos    */
/* que tem c�digo menor primeiro e o com maior c�digo   */
/* por �ltimo.                                          */
/* Retorno: ordena a lista em ordem crescente de codigo */
/********************************************************/
void ordenaCodigo(ESTOQUE *estoque) {
  int i, j;
  PRODUTOS aux;

for(j=0;j<estoque->contador;j++){
        for(i=j+1;i<estoque->contador;i++){
            if(estoque->produtos[j].codigo>estoque->produtos[i].codigo){
                aux=estoque->produtos[j];
                estoque->produtos[j]=estoque->produtos[i];
                estoque->produtos[i]=aux;
            }
        }
    }
    printf("\n\nProdutos ordenado por ordem de c�digo!\n");
    system("pause");
}
/**************************************************/
/* Nome: excluirCodigo                            */
/* Fun��o: exclui um produto de c�digo espec�fico */
/* e move todas posi��es da direita deste c�digo, */
/* uma casa pra esquerda.                         */
/* Retorno: exclui um produto da lista            */
/**************************************************/
void excluirCodigo(ESTOQUE *estoque){
  int codigo, i= 0, j; // i, j sao indices

  if( estoque->contador == 0 )
      printf("\n Lista vazia!");
  else{
  	  printf("\n Informe o codigo que deseja excluir: ");
  	  fflush(stdin);
	  scanf("\n %i", &codigo);	 // codigo a ser excluido

	  while( codigo != estoque->produtos[i].codigo && i < estoque->contador ) // caminha pela lista procurando o codigo ate encontra-lo ou chegar ao final da lista
	  	     i++;

	  if( codigo == estoque->produtos[i].codigo ){       // verifica se encontrou o codigo que deseja excluir na lista
	  	 for(j = i; j < estoque->contador-1 ; j++)
		     estoque->produtos[j] = estoque->produtos[j+1]; // realiza o deslocamento dos registros posteriores ao excluido evitando buracos na lista

	  	 estoque->contador--; // decrementa o numero de registros validos
	  	 printf("\n Produto excluido!");
	  }
	  else
	     printf("\n Codigo nao encontrado!");
  }
}

/***********************************************/
/* Nome: excluirVencidos                       */
/* Fun��o: deleta produtos vencidos            */
/* Retorno: lista sem produtos vencidos        */
/***********************************************/
void excluirVencidos(ESTOQUE *estoque){

    int i, j,contas_excluidas=0,resultado=0;
    char opcao;
    PRODUTOS aux;

    /* ordena jogando os vencidos para o final da lista */
	for(j=0;j<estoque->contador;j++){
        for(i=j+1;i<estoque->contador;i++){
            if(estoque->produtos[j].validade < estoque->produtos[i].validade){
                aux=estoque->produtos[j];
                estoque->produtos[j]=estoque->produtos[i];
                estoque->produtos[i]=aux;
            }
        }
    }
    /* verifica quais j� venceram */
    for(j=0;j<estoque->contador;j++){
        resultado = estoque->produtos[j].validade - estoque->somaValidade;
        if(resultado < 0){
            contas_excluidas++;
        }
    }
    /* se algum produto foi excluido, ele vai voltar o indice deixando os vencidos no limbo...*/
    if(contas_excluidas > 0){
        printf("\n%d encontrados.\nDeseja excluir?[S/n]", contas_excluidas);
       // __fpurge(stdin);
        fflush(stdin); //-> limpeza Linux (pode remover)
        scanf("%c",&opcao);

        if (toupper(opcao) == 'S')
        {
            printf("Produtos excluidos com sucesso!");
            estoque->contador -= contas_excluidas;
        }else{
            /*Se nao quiser excluir, deixa na ordem da validade(opcao 3)*/
            ordenaValidade(estoque);
        }
    }

}
