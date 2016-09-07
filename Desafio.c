/***********************************************/
/* Desafio de Programação Listas               */ 
/* Listas Sequenciais                          */
/* objetivo:                                   */
/* programador:                                */
/* criado em:                                  */
/* data da última alteração:                   */
/***********************************************/

#include <stdio.h> 
#include <stdio_ext.h> // __fpurge
// #include <conio.h> //getche on Windows  - DESCOMENTAR LINHA PARA USAR NO WINDOWS e alterar os 'getchar' por 'getche'
#include <stdlib.h> // exit
#include <string.h>
#include <ctype.h> //toupper 
#include <locale.h> //potugues




/***********************************************/
/* Definição dos Registros                     */
/***********************************************/


/***********************************************/
/* Definição das Funções                       */
/***********************************************/


/***********************************************/
/* Programa Principal                          */
/***********************************************/
int main(void){
	                                                             
    setlocale(LC_ALL, "Portuguese");
    char op;

    while( 1 ){
         printf( "\n /-------------------------------------------------------/" );
         printf( "\n Nome do Programa - Menu                                  " );
         printf( "\n [1] Faz alguma coisa                                     " );
         printf( "\n [2] Faz alguma coisa                                     " );              
         printf( "\n [3] Faz alguma coisa                                     " );
         printf( "\n [s] Para sair do programa                                " );
         printf( "\n /-------------------------------------------------------/" );
         printf( "\n Opção: " );
	 
	fflush( stdin ); // limpeza do stdin - WINDOWS
	__fpurge(stdin); // limpeza do stdin - LINUX
 	
         op = toupper(getchar());
 	 printf( "%c",op );  	         
         switch( op ) {
            case '1':
	    printf( "\n Deu certo!" ); 
                    break;
            case '2':  
                    break;
            case '3':  
                    break;
            case '4':  
                    break;
            case '5':  
                    break;

            case 'S': // término do programa
                    exit( 1 );
                    break;

            default :
                    printf( "\n Digite uma opção!" );
                    break;
        }

        printf( "\n" );
     } // fim do while( 1 )

 return 0;
} // fim do programa principal


/***********************************************/
/* Funções                                     */
/***********************************************/

