#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings
#include <windows.h>//Biblioteca de API's do windows

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	
	file = fopen(arquivo, "w"); //abre o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa atualizar
	fprintf(file,","); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s",nome); // %s refere-se a strings
	
	file = fopen(arquivo, "a"); // abre o arquivo e "a" significa atualizar
	fprintf(file,nome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s",sobrenome); // %s refere-se a strings
	
	file = fopen(arquivo, "a"); // abre o arquivo e "a" significa atualizar
	fprintf(file,sobrenome); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e "a" significa atualizar
	fprintf(file, ","); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s",cargo); // %s refere-se a strings
	
	file = fopen(arquivo, "a"); // abre o arquivo e "a" significa atualizar
	fprintf(file,cargo); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	system("pause"); 
	
}

int consulta() // Função responsável por consultar os usuários cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Língua
	
	// Início da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	// Final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); // Coletando informações do usuário
	scanf("%s",cpf); // %s refere-se a string
	
	FILE *file; // Cria o arquivo
	
	file = fopen(cpf,"r"); // Abre o arquivo e "r" significa ler 
	
	if(file == NULL) // Início do operador de repetição
	{
		printf("Não foi possivel abrir o arquivo, não loccalizado!.\n"); // Exibe ao usuário caso não encontre o arquivo
	} // Fim do operador de repetição
	
	while (fgets(conteudo, 200, file) != NULL) // Início do operador de repetição
	{
		printf("\nEssas são as informações do usuário: "); // Exibe as informações ao usuário
		printf("%s",conteudo); // %s refere-se a string
		printf("\n\n");
	} // Fim do operador de repetição
	
	system("pause");
	
}

int deletar() // Função responsável por deletar o usuário cadastrado no sistema
{
	char cpf[40]; // Criação de variável do tipo string
	
	printf("Digite o CPF do usuário cadastrado a ser deletado: "); // Coletando informações do usuário
	scanf("%s",cpf); // %s refere-se a string
	
	remove(cpf); // Remove a variável reponsável por armazenar o CPF
	
	FILE *file; // Cria o arquivo
	
	file = fopen(cpf,"r"); // Abre o arquivo e "r" significa ler
	
	if(file == NULL) // Início do operador de repetição
	{
		printf("O usuário foi deletado do sistema!.\n"); // Exibe as informações ao usuário
	} // Fim do operador de repetição
	
	system("pause");
	
}

int main() //Função principal, responsável por apresentar o menu ao usuário
{
	int opcao=0; //Definindo Variável
	
	int laco=1; //Definindo Variável
	
	char senhadigitada[10] = "a"; // Criação de variável do tipo string
	
	int comparacao; //Definindo Variável
	
	printf("### Cartório da EBAC ###\n\n"); 
	printf("Login de Administrador!\n\nDigite a sua senha:");
	scanf("%s",&senhadigitada); //Armazenando a senha digitada
	
	comparacao = strcmp(senhadigitada, "admin"); //Definindo a comparação de strings
		
	if(comparacao == 0) // Início do operador de repetição
	{ 
		system("cls");
		
		for (laco=1;laco=1;) // Início do operador de repetição
		{
			setlocale(LC_ALL, "Portuguese"); //Definindo a Língua
	
			printf("### Cartório da EBAC ###\n\n"); //Início do Menu
			printf("Escolha a opção desejada do menu :\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");	
			printf("\t3 - Deletar nomes\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção:"); // Fim do Menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usuário
	
			system("cls"); // responsável por limpar a tela 
		
			switch(opcao) //início da seleção
			{
				case 1:
				printf("Você escolheu registro de nomes!\n\n");
				registro(); // Chamada da função reponsável por registrar
				break;
				
				case 2:
				printf("Você escolheu consultar nomes!\n\n");
				consulta(); // Chamada da função responsável por consultar
				break;
				
				case 3:
				printf("Você escolheu deletar nomes!\n\n");
				deletar(); // Chamada da função responsável por deletar 
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n"); // Exibe a informação ao usuário
				return 0;
				break;
					
				default: 
				printf("Essa opção não existe\n"); // Exibe a informação ao usuário 
				system("pause");
				break;
		
			}//Fim da seleção
			
		} // Fim do operador de repetição
		
	}  //Fim do operador de repetição
	
	else
		printf("Senha incorreta!");
	
} //Definição de Variável

