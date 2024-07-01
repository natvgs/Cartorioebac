#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respos�vel por cuidar das string

int registro() //Fun�o resposanlvel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refe-se a string
	
	strcpy(arquivo, cpf); //respos�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo o "w" siginifica escrever
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s",nome); //referente a string
	
	file = fopen(arquivo, "a"); //abre um arquivo para adi��o de novos dados
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s", sobrenome); //referente a string
	
	file = fopen(arquivo, "a"); //abre um arquivo para adi��o de novos dados
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s",cargo);//referente a string
	
	file = fopen(arquivo, "a");//abre um arquivo para adi��o de novos dados
	fprintf(file,cargo);//salva o valor da variavel
	fclose(file); //fecha arquivo
	
	system("pause");
}

int consulta() //Fun�o resposanlvel por consultar os usu�rios cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");//coletando informa��o do usuario
	scanf("%s",cpf); //referente a string
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //valor n�o localizado
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//operador de repeti��o 
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //exibe as informa��es ao usuario
		printf("%s", conteudo); //referente a string
		printf("\n\n"); //fim
	}
	
	system("pause");
	
}

int deletar()//Fun�o resposanlvel por deletar os usu�rios cadastrados no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio deletado: ");//coletando informa��o do usuario
	scanf("%s,cpf");//referente a string
	
	remove(cpf); //apaga variavel do cpf
	
	FILE *file;//cria arquivo
	file = fopen(cpf,"r");//"r" le o arquivo
	
	if(file == NULL) //operador de repeti��o
	{
		printf("Usu�rio deletado com sucesso!.\n"); //exibe informa��es ao usuario
		system("pause");
	}
	
}

int main() //fun��o principal/ponto de partida
{
	int opcao=0; ///Definindo vari�veis 
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); //clear
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
        printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
	    printf("Op��o: ");//fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	    system("cls"); //responsavel por limpar a tela
	    
	    switch(opcao) //inicio da sele��o
	    {
	    	case 1:
	    	registro(); //chamada de fun��es
		    break;
		
	        case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3://chamada de fun��es
		    deletar();
			break;
	
		    default: //caso o usuario pe�a uma op��o invalida
		    	printf("Essa op��o n�o est� disponivel!\n");
		    	system("pause");
		    	break;
				
					}//fim da sele��o
  }
}
