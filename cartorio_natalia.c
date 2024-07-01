#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca resposável por cuidar das string

int registro() //Funão resposanlvel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refe-se a string
	
	strcpy(arquivo, cpf); //resposável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo o "w" siginifica escrever
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuario
	scanf("%s",nome); //referente a string
	
	file = fopen(arquivo, "a"); //abre um arquivo para adição de novos dados
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuario
	scanf("%s", sobrenome); //referente a string
	
	file = fopen(arquivo, "a"); //abre um arquivo para adição de novos dados
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuario
	scanf("%s",cargo);//referente a string
	
	file = fopen(arquivo, "a");//abre um arquivo para adição de novos dados
	fprintf(file,cargo);//salva o valor da variavel
	fclose(file); //fecha arquivo
	
	system("pause");
}

int consulta() //Funão resposanlvel por consultar os usuários cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");//coletando informação do usuario
	scanf("%s",cpf); //referente a string
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //valor não localizado
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//operador de repetição 
	{
		printf("\nEssas são as informações do usuário: "); //exibe as informações ao usuario
		printf("%s", conteudo); //referente a string
		printf("\n\n"); //fim
	}
	
	system("pause");
	
}

int deletar()//Funão resposanlvel por deletar os usuários cadastrados no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usuário deletado: ");//coletando informação do usuario
	scanf("%s,cpf");//referente a string
	
	remove(cpf); //apaga variavel do cpf
	
	FILE *file;//cria arquivo
	file = fopen(cpf,"r");//"r" le o arquivo
	
	if(file == NULL) //operador de repetição
	{
		printf("Usuário deletado com sucesso!.\n"); //exibe informações ao usuario
		system("pause");
	}
	
}

int main() //função principal/ponto de partida
{
	int opcao=0; ///Definindo variáveis 
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); //clear
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
        printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
	    printf("Opção: ");//fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuário
	
	    system("cls"); //responsavel por limpar a tela
	    
	    switch(opcao) //inicio da seleção
	    {
	    	case 1:
	    	registro(); //chamada de funções
		    break;
		
	        case 2:
			consulta(); //chamada de funções
			break;
			
			case 3://chamada de funções
		    deletar();
			break;
	
		    default: //caso o usuario peça uma opção invalida
		    	printf("Essa opção não está disponivel!\n");
		    	system("pause");
		    	break;
				
					}//fim da seleção
  }
}
