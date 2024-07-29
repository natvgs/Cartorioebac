#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings
#include <windows.h>//Biblioteca de API's do windows

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	
	file = fopen(arquivo, "w"); //abre o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa atualizar
	fprintf(file,","); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s",nome); // %s refere-se a strings
	
	file = fopen(arquivo, "a"); // abre o arquivo e "a" significa atualizar
	fprintf(file,nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s",sobrenome); // %s refere-se a strings
	
	file = fopen(arquivo, "a"); // abre o arquivo e "a" significa atualizar
	fprintf(file,sobrenome); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e "a" significa atualizar
	fprintf(file, ","); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s",cargo); // %s refere-se a strings
	
	file = fopen(arquivo, "a"); // abre o arquivo e "a" significa atualizar
	fprintf(file,cargo); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	system("pause"); 
	
}

int consulta() // Fun��o respons�vel por consultar os usu�rios cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a L�ngua
	
	// In�cio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	// Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); // Coletando informa��es do usu�rio
	scanf("%s",cpf); // %s refere-se a string
	
	FILE *file; // Cria o arquivo
	
	file = fopen(cpf,"r"); // Abre o arquivo e "r" significa ler 
	
	if(file == NULL) // In�cio do operador de repeti��o
	{
		printf("N�o foi possivel abrir o arquivo, n�o loccalizado!.\n"); // Exibe ao usu�rio caso n�o encontre o arquivo
	} // Fim do operador de repeti��o
	
	while (fgets(conteudo, 200, file) != NULL) // In�cio do operador de repeti��o
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // Exibe as informa��es ao usu�rio
		printf("%s",conteudo); // %s refere-se a string
		printf("\n\n");
	} // Fim do operador de repeti��o
	
	system("pause");
	
}

int deletar() // Fun��o respons�vel por deletar o usu�rio cadastrado no sistema
{
	char cpf[40]; // Cria��o de vari�vel do tipo string
	
	printf("Digite o CPF do usu�rio cadastrado a ser deletado: "); // Coletando informa��es do usu�rio
	scanf("%s",cpf); // %s refere-se a string
	
	remove(cpf); // Remove a vari�vel repons�vel por armazenar o CPF
	
	FILE *file; // Cria o arquivo
	
	file = fopen(cpf,"r"); // Abre o arquivo e "r" significa ler
	
	if(file == NULL) // In�cio do operador de repeti��o
	{
		printf("O usu�rio foi deletado do sistema!.\n"); // Exibe as informa��es ao usu�rio
	} // Fim do operador de repeti��o
	
	system("pause");
	
}

int main() //Fun��o principal, respons�vel por apresentar o menu ao usu�rio
{
	int opcao=0; //Definindo Vari�vel
	
	int laco=1; //Definindo Vari�vel
	
	char senhadigitada[10] = "a"; // Cria��o de vari�vel do tipo string
	
	int comparacao; //Definindo Vari�vel
	
	printf("### Cart�rio da EBAC ###\n\n"); 
	printf("Login de Administrador!\n\nDigite a sua senha:");
	scanf("%s",&senhadigitada); //Armazenando a senha digitada
	
	comparacao = strcmp(senhadigitada, "admin"); //Definindo a compara��o de strings
		
	if(comparacao == 0) // In�cio do operador de repeti��o
	{ 
		system("cls");
		
		for (laco=1;laco=1;) // In�cio do operador de repeti��o
		{
			setlocale(LC_ALL, "Portuguese"); //Definindo a L�ngua
	
			printf("### Cart�rio da EBAC ###\n\n"); //In�cio do Menu
			printf("Escolha a op��o desejada do menu :\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");	
			printf("\t3 - Deletar nomes\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o:"); // Fim do Menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
			system("cls"); // respons�vel por limpar a tela 
		
			switch(opcao) //in�cio da sele��o
			{
				case 1:
				printf("Voc� escolheu registro de nomes!\n\n");
				registro(); // Chamada da fun��o repons�vel por registrar
				break;
				
				case 2:
				printf("Voc� escolheu consultar nomes!\n\n");
				consulta(); // Chamada da fun��o respons�vel por consultar
				break;
				
				case 3:
				printf("Voc� escolheu deletar nomes!\n\n");
				deletar(); // Chamada da fun��o respons�vel por deletar 
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n"); // Exibe a informa��o ao usu�rio
				return 0;
				break;
					
				default: 
				printf("Essa op��o n�o existe\n"); // Exibe a informa��o ao usu�rio 
				system("pause");
				break;
		
			}//Fim da sele��o
			
		} // Fim do operador de repeti��o
		
	}  //Fim do operador de repeti��o
	
	else
		printf("Senha incorreta!");
	
} //Defini��o de Vari�vel

